#ifndef FIND_DUPLICATES_H
#define FIND_DUPLICATES_H

#include <list>
#include <memory>

class FindDuplicates {
 public:
  std::unique_ptr<std::list<int>>
  findDuplicates(std::list<int> & inputA, std::list<int> & inputB);
};

#endif


