#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

/*! \brief Simulated test case class
 *
 *  Test cases have dependencies on each other, and we use them to exercise
 *  out toposort code
 */
class Test {
 public:
  Test(std::size_t id) : id_{id}, done_{false} {};
  
  void add_dependency(std::size_t id) {
    // Don't add duplicate dependencies
    const auto it = std::find(dependencies_.begin(), dependencies_.end(), id);
    if (it == dependencies_.end()) {
      // New dependency, add it
      dependencies_.push_back(id);
    }
  }

  void add_dependencies(const std::vector<std::size_t>& deps) {
    std::for_each(deps.begin(), deps.end(),
                  [this](const auto& id) { add_dependency(id); });
  }

  void operator()() {
    if (!done_) {
      std::cout << "Executing " << id_ << std::endl;
      done_ = true;
    } else {
      std::cout << "Test " << id_ << " is already done" << std::endl;
    }
  }

  std::size_t id() const { return id_; }
  const std::vector<std::size_t> dependencies() const { return dependencies_; }
  
  bool done() const { return done_; }
 private:
  std::size_t id_;
  std::vector<std::size_t> dependencies_;
  bool done_;
};

std::vector<std::vector<std::size_t>>
toposort(const std::vector<Test>& tests) {
  // Maps test_id to the tests that depend on it
  std::map<std::size_t, std::vector<std::size_t>> dependents_of;
  // Maps test_id to the number of tests it depends on, and are not done
  std::map<std::size_t, std::size_t> dependencies_of;
  // Current tests without pending dependencies
  std::vector<std::size_t> tests_ready;

  for (const Test& test : tests) {
    const std::size_t id = test.id();
    if (test.dependencies().size() == 0) {
      tests_ready.push_back(id);
    } else {
      for(const auto& dependency_id : test.dependencies()) {
        dependents_of[dependency_id].push_back(id);
        ++dependencies_of[id];
      }
    }
  }

  std::vector<std::vector<std::size_t>> schedule{};

  while (!tests_ready.empty()) {
    schedule.push_back(tests_ready);    
    std::vector<std::size_t> next_step_ready;
    for (const auto& ready_id : tests_ready) {
      for (const auto& dependent_id : dependents_of[ready_id]) {
        auto deps = --dependencies_of[dependent_id];
        if (deps == 0) {
          next_step_ready.push_back(dependent_id);
          dependencies_of.erase(dependent_id);
        }
      }
    }

    tests_ready.swap(next_step_ready);
  }

  return schedule;
}

int main(int, char**) {
  std::cout << "Topological sort demo" << std::endl;
  Test t1{1}, t2{2}, t3{3}, t4{4};
  t4.add_dependency(3);
  t3.add_dependencies({1, 1});
  t2.add_dependencies({1, 3});

  std::map<std::size_t, Test*> tests;
  tests[t1.id()] = &t1;
  tests[t2.id()] = &t2;
  tests[t3.id()] = &t3;
  tests[t4.id()] = &t4;
  
  auto schedule = toposort({t1, t2, t3, t4});
  for (const auto& step : schedule) {
    std::cout << "Step" << std::endl;
    for (const auto& test_id : step) {
      (*tests[test_id])();
    }
  }
}
