#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include "task.h"
#include <condition_variable>
#include <mutex>
#include <string>
#include <sstream>

namespace {
using namespace std::chrono_literals;

  // A runnable of sorts
  class Task {
  public:
    virtual void operator()() = 0;
  };

  // Dummy Task to test the code. Simply
  // Writes a message passed at construction
  // time
  class WriterTask : public Task {
  public:
    WriterTask(const std::string& str) : msg{str} {};
    virtual void operator()() override {
      std::cout << msg << std::endl;
    }
  private:
    std::string msg;
  };

  // Worker that executes on a separate thread. It has
  // a mailbox to receive tasks. It doesn't start executing
  // until its start method is called. When stopped, it first
  // drains the mailbox.
  class WorkerThread {
  public:
    void start() {
      t.reset(new std::thread{&WorkerThread::operator(), this});
    }
    void addWork(Task* task) {
      std::lock_guard<std::mutex> lk{m};
      // Don't accept more work if we have been told to stop
      if (!stop_) {
	mailbox.push_back(task);
	cv.notify_all();
      }
    }

    void stop() {
      std::lock_guard<std::mutex> lk{m};
      stop_ = true;
      cv.notify_all();
    }

    bool busy() {
      std::lock_guard<std::mutex> lk{m};
      return !mailbox.empty();
    }

    void join() {
      t->join();
    }
    
  private:
    void operator()() {
      // Process Tasks from the mailbox until empty
      // If empty && stop_, the thread will stop
      while (true) {
	std::unique_lock<std::mutex> lk{m};
	if (mailbox.size() == 0) {
	  if (stop_) {
	    break;
	  }

	  // Wait with timeout to be able to react to
	  // stop conditions
	  if(!cv.wait_for(lk, 1000ms, [this]() {
	    return (mailbox.size() > 0);
	  })) {
	    continue;
	  }
	}

	// Carry out work
	Task* t = mailbox.back();
	mailbox.pop_back();
	(*t)();
      }
    }
    
    std::vector<Task*> mailbox;
    std::condition_variable cv;
    std::mutex m;
    bool stop_ = false;
    std::unique_ptr<std::thread> t;
  };

  // A Thread pool that manages N WorkerThread objects. The
  // current algorithm is very simple, just use free/running lists,
  // and move threads between the two lists as approprioate.
  // This thread pool is designed to be used from a single thread.
  // We will add thread safety at a later stage.
  class ThreadPool {
  public:
    ThreadPool(int n)  {
      for (auto i = 0U ; i < n ; ++i) {
	free_.emplace_back(new WorkerThread{});
      }

      for (auto& workerPtr : free_) {
	workerPtr->start();
      }
    }
 
    std::string str() {
      std::stringstream ss;
      ss << free_.size() << " "
	 << running_.size();
      return ss.str();
    }
    
    void run(Task* task) {
      if (!free_.empty()) {
	auto& workerPtr = free_.back();
	// Schedule the work before moving into the running_
	// vector, because the std::move empties the unique_ptr
	workerPtr->addWork(task);	
	running_.push_back(std::move(workerPtr));	
	free_.pop_back();
      } else {
	// See if you can move any worker from running to free
	// Otherwise schedule at the back
	bool dispatched = false;
	for (auto it = running_.begin() ; it != running_.end() ; ++it) {
	  auto& workerPtr = *it;
	  if (!workerPtr->busy()) {
	    if (!dispatched) {
	      workerPtr->addWork(task);
	      dispatched = true;
	    } else {
	      // Recycle WorkerThread
	      free_.push_back(std::move(workerPtr));
	      it = running_.erase(it);
	      --it;
	    }
	  }
	}
      }
    }

    void stop_and_wait() {
      for(auto& workerPtr : free_) {
	workerPtr->stop();
      }

      for(auto& workerPtr : free_) {
	workerPtr->join();
      }      

      for(auto& workerPtr : running_) {
	workerPtr->stop();
      }

      for(auto& workerPtr : running_) {
	workerPtr->join();
      }            
    }

  private:
    std::vector<std::unique_ptr<WorkerThread>> free_;
    std::vector<std::unique_ptr<WorkerThread>> running_;    
  };
}

int main(int argc, char** argv) {
  std::cout << "Starting scheduller" << std::endl;
  ThreadPool tp{10};
  WriterTask t1{"What the hell"};

  tp.run(&t1);
  tp.run(&t1);  

  std::cout << tp.str() << std::endl;
  for (auto i = 0 ; i < 100 ; ++i) {
    tp.run(&t1);
    std::this_thread::sleep_for(10ms);
    std::cout << tp.str() << std::endl;      
  }
  std::cout << tp.str() << std::endl;    
  tp.stop_and_wait();

  
}
