#include <functional>
#include <list>
#include <thread>
#include <mutex>

using Fn = std::function<void()>;

class Command {
 public:
  Command(Fn fn) : fn_(fn) {}

  void exec() {
    fn_();
  }
 private:
  Fn fn_;
};

class CommandQueue {
 public:

  static Command noop() {
    static Command cmd([](){});
    return cmd;
  }
  
  void add(Command cmd) {
    std::lock_guard<std::mutex> lock{mutex_};
    queue.push_front(cmd);
  }

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
  
 private:
  std::mutex mutex_;
  std::list<Command> queue;
};
