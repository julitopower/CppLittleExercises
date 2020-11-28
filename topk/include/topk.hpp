#pragma once

#include <algorithm>
#include <vector>
#include <type_traits>

namespace topk {

template <typename Iter, typename Fn>
class TopK {
private:
  Iter begin_;
  Iter end_;
  using T = std::remove_reference_t<decltype(*begin_)>;
  Fn fn_;
  
public:
  TopK(Iter begin, Iter end, Fn fn) : begin_{begin}, end_{end}, fn_{fn} {
    
  }

  /**
   * Return the Top K elements based on the evaluation of fn_ on
   * each element of the input vector.
   *
   * - Build buffer vector<sort_value, value> and sort it
   * - Copy value from pair vector and return it
   */
  std::vector<T> topk(std::size_t k) {
    // Buffer vector = vector<pair<sort_value, value>>
    std::vector<std::pair<decltype(fn_(*begin_)), T>> buffer{};
    buffer.reserve(k);
    buffer.resize(k);

    // Output vector is simply a vector<T> with k elmenets
    std::vector<T> output{};
    output.reserve(k);
    output.resize(k);    

    // TODO: Very inefficient code for large input vectors
    const std::size_t input_size = (end_ - begin_);
    // Pickup up to input_size elements
    k = std::min(input_size, k);

    // Resize buffer to the size of the input. We are going to
    // evaluate all elements in the input and store the pairs<sort_value, value> here
    buffer.resize(input_size);
    std::transform(begin_, end_, buffer.begin(),
                   [this](const T& elem) {
                     // Evaluate each element and build pair<sort_value, value>
                     return std::make_pair(fn_(elem), elem);
                   });
    std::sort(buffer.begin(), buffer.end());
    // Pick up only the top k elements
    buffer.resize(k);

    // Copy the topk values in the output vector
    std::transform(buffer.begin(), buffer.end(), output.begin(),
                   [](decltype(*buffer.begin()) elem) {
                     return elem.second;
                   });
    return output;
  }

};

template <typename Iter, typename Fn>
TopK<Iter, Fn> buildTopK(Iter begin, Iter end, Fn fn) {
  return TopK<Iter, Fn>(begin, end, fn);
}

}
