#include <bits/c++config.h>
#include <functional>
#include <list>
#include <thread>
#include <mutex>

using Fn = std::function<void()>;

/*! \brief A Command encapuslates a deferred action
 *
 * For instance, on a web server one may perform
 * certain actions synchronously with a request, but
 * enqueu others, like logging information so that
 * requests can be fullfilled fast, and non essential
 * activities can be carried out asynchronously.
 */
class Command {
 public:
  /*
   * The Function passed must be self contained and if
   * statefull, it must ensure it owns all its state, e.g.
   * data structures capturved via lambda capture.
   */
  Command(Fn fn) : fn_(fn) {}


  /* Commands are executed on a best effort fashion */
  void exec() noexcept {
    try {
      fn_();
    } catch (...) {}
  }
 private:
  Fn fn_;
};

/*! \brief Queue to communicate consumer and producers of Commands
 */
class CommandQueue {
 public:

  /*! \brief Get a Command that does nothing*
   *  Each call to this method returns the same command
   *  object.
   */
  static const Command& noop() {
    static Command cmd([](){});
    return cmd;
  }

  /*! \brief Enqueue a command
   *
   */
  void add(Command cmd) {
    std::lock_guard<std::mutex> lock{mutex_};
    queue.push_front(cmd);
  }

  /*! \brief Dequeue a command
   *
   */
  Command get() {
    std::lock_guard<std::mutex> lock{mutex_};
    if (!queue.empty()) {
      auto cmd = queue.back();
      queue.pop_back();
      return cmd;
    }
    std::this_thread::yield();
    return CommandQueue::noop();
  }

  /*! \brief Elements left in the queue
   *
   *  This method is not protected by a mutex, and thus
   *  the results may be inconsistent.
   */
  std::size_t size() const {
    return queue.size();
  }
  
 private:
  std::mutex mutex_;
  std::list<Command> queue;
};
