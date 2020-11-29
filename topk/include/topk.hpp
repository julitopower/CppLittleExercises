#pragma once

#include <algorithm>
#include <vector>
#include <type_traits>
#include <cmath>

namespace topk {

template <typename Iter, typename Fn>
class TopK {
private:
  Iter begin_;
  Iter end_;
  using T = std::remove_reference_t<decltype(*begin_)>;
  Fn fn_;
  
public:
  TopK(Iter begin, Iter end, Fn fn) : begin_{begin}, end_{end}, fn_{fn} {}

  /**
   * Return the Top K elements based on the evaluation of a cost function on
   * each element of the input vector.
   *
   * This implementation selects the fastest implementation based on computational
   * complexity calculations.
   */
  std::vector<T> topk(std::size_t k) {
    const auto n = (end_ - begin_);
    // Requested more elements that available. Use the solution that loads
    // all the dataset at once.
    if (k >= n) {
      return topkmem(n);
    }

    // Select implementation based on computational complexity.
    if (k < std::log2l(n)) {
      return topkbuffer(k);
    } else {
      return topkmem(k);
    }
    
  }

  /**
   * Return the Top K elements based on the evaluation of a cost function on
   * each element of the input vector. Algorithm:
   *
   * Use a buffer of k elements to get the topk. This method is faster
   * than ordering the entire dataset in memory when K < log2(n).
   *
   * Use topk instead of this method. Topk automatically selects the fastest
   * implementation based on their computational complexity.
   */
  std::vector<T> topkbuffer(std::size_t k) {
    // Buffer vector = vector<pair<sort_value, value>>
    std::vector<std::pair<decltype(fn_(*begin_)), T>> buffer{};
    std::transform(begin_, begin_ + k + 1, std::back_inserter(buffer),
                   [this](const T& elem) {
                     // Evaluate each element and build pair<sort_value, value>
                     return std::make_pair(fn_(elem), elem);
                   });
    
    std::sort(buffer.begin(), buffer.end());
    for (auto it = begin_ + k + 1 ; it != end_; ++it) {
      buffer.back() = std::make_pair(fn_(*it), *it);
      std::sort(buffer.begin(), buffer.end());      
    }

    // Output vector is simply a vector<T> with k elmenets
    std::vector<T> output{};
    // Copy the topk values in the output vector
    std::transform(buffer.begin(), buffer.end() - 1, std::back_inserter(output),
                   [](decltype(*buffer.begin()) elem) {
                     return elem.second;
                   });
    return output;
  }
  
  /**
   * Return the Top K elements based on the evaluation of a cost function on
   * each element of the input vector. Algorithm:
   *
   * - Build buffer vector<sort_value, value> and sort it
   * - Copy value from pair vector and return it
   *
   * Use topk instead of this method. Topk automatically selects the fastest
   * implementation based on their computational complexity.   
   */
  std::vector<T> topkmem(std::size_t k) {
    // Buffer vector = vector<pair<sort_value, value>>
    std::vector<std::pair<decltype(fn_(*begin_)), T>> buffer{};

    // Output vector is simply a vector<T> with k elements
    std::vector<T> output{};
    
    const std::size_t input_size = (end_ - begin_);
    // Pickup up to input_size elements
    k = std::min(input_size, k);

    // Resize buffer to the size of the input. We are going to
    // evaluate all elements in the input and store the pairs<sort_value, value> here
    buffer.resize(input_size);
    std::transform(begin_, end_, std::back_inserter(buffer),
                   [this](const T& elem) {
                     // Evaluate each element and build pair<sort_value, value>
                     return std::make_pair(fn_(elem), elem);
                   });
    std::sort(buffer.begin(), buffer.end());
    // Pick up only the top k elements
    buffer.resize(k);

    // Copy the topk values in the output vector
    std::transform(buffer.begin(), buffer.end(), std::back_inserter(output),
                   [](decltype(*buffer.begin()) elem) {
                     return elem.second;
                   });
    return output;
  }

};

/*! \brief Build a topk object
 *  Utility function to avoid having to define the template parameters
 *  to instantiate a TopK class object.
 *
 *  \tparam Iter an iterator that must be dereferenciable and must work with the
 *           algorithms in the <algorithm> header.
 *  \tparam Fn A function with signature K(*fn)(T), where T is the type returned
 *          by dereferencing Iter, and K is any type that supports < comparison
 */
template <typename Iter, typename Fn>
TopK<Iter, Fn> buildTopK(Iter begin, Iter end, Fn fn) {
  return TopK<Iter, Fn>(begin, end, fn);
}

}
