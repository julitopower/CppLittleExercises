#pragma once

#include <algorithm>
#include <vector>
#include <set>
#include <type_traits>
#include <cmath>

namespace topk {

/*! \brief Utility to get the top-k elements from a container based on a cost function
 * \tparam Iter Iterator to container. Must be compatible with the std library interator
 * \tparam Fn Cost function. Must have signature numeric Fn(T&), where T is the type returned
              by *Iter

   This class implements a variety of methods to retrieve the top-k. Different methods are
   appropritate for different types of input. For more information read the documentation
   of each of the topkXXXYYY methods.
 */
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
   *
   * TODO: Needs to be revised, since topkbuffer is now pretty much a constant time
   * operation. By leaving this and the 3 actual implementation in the public interface
   * we give users flexibility. The current recommended implementation is topklistbuffer
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
      return topklistbuffer(k);
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
   * implementation based on their computational complexity. This is the fastest
   * of the two buffer-based implementations. We have measued this implementation to be
   * 11 times faster than the memory based, and 10 times faster than the set-buffer.
   */
  std::vector<T> topklistbuffer(std::size_t k) {
    // Buffer vector = vector<pair<sort_value, value>>
    std::vector<std::pair<decltype(fn_(*begin_)), T>> buffer{};
    // Fill and sort the buffer, so that buffer.back() contains the
    // smaller element
    std::transform(begin_, begin_ + k + 1, std::back_inserter(buffer),
                   [this](const T& elem) {
                     // Evaluate each element and build pair<sort_value, value>
                     return std::make_pair(fn_(elem), elem);
                   });
    std::sort(buffer.begin(), buffer.end());

    // Process the rest of the input
    for (auto it = begin_ + k + 1 ; it != end_; ++it) {
      const auto val = fn_(*it);
      if (val < buffer.back().first) {
        buffer.back() = std::make_pair(val, *it);
        std::sort(buffer.begin(), buffer.end());
      }
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
   * Use a buffer of k elements to get the topk. This method is faster
   * than ordering the entire dataset in memory when K < log2(n). In fact, if
   * the const function values are uniformely distributed, then this method
   * performs at constant time, since most of the values are not part of the
   * topk, a simple comparision value > max_min_topk avoids the costly insertion
   * deletion in most cases.
   *
   * Use topk instead of this method. Topk automatically selects the fastest
   * implementation based on their computational complexity. This is the slowest
   * of the two buffer-based implementations, although it is still at least
   * 10x faster than the memory-based implementation.
   *
   */
  std::vector<T> topksetbuffer(std::size_t k) {
    // Buffer vector = vector<pair<sort_value, value>>
    std::multiset<std::pair<decltype(fn_(*begin_)), T>> sbuffer{};
    std::transform(begin_, begin_ + k + 1, std::inserter(sbuffer, sbuffer.begin()),
                   [this](const T& elem) {
                     // Evaluate each element and build pair<sort_value, value>
                     return std::make_pair(fn_(elem), elem);
                   });

    auto count = 0U;
    for (auto it = begin_ + k + 1 ; it != end_; ++it) {
      const auto val = fn_(*it);
      if (val < sbuffer.rbegin()->first) {
        ++count;
        sbuffer.erase(--sbuffer.end());
        sbuffer.insert(std::make_pair(val, *it));
      }
    }

    // Output vector is simply a vector<T> with k elmenets
    std::vector<T> output{};
    // Copy the topk values in the output vector
    std::transform(sbuffer.begin(), --sbuffer.end(), std::back_inserter(output),
                   [](decltype(*sbuffer.begin()) elem) {
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
