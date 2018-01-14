#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <iostream>

namespace matrix {

  /*
   * Wraps a memory region with a vector like interface. We are only interested in
   * iterators capabilities
  */
  template<typename T>
  class VectorView {
  public:
    VectorView(T* buffer, std::size_t size) : data_{buffer}, data_end_{buffer + size} {}
    /*
     * We don't own the memory, so we make sure our destructor does nothing.
     */
    ~VectorView() {}
    
    // To facilitate iteration in for loops
    T* begin() { return data_; }
    const T* begin() const { return data_; }
    T* end() { return data_end_; }
    const T* end() const { return data_end_; }

    // Full buffer access, for semantic convenience
    T* data() { return data_; }
    const T* data() const { return data_; }

  private:
    T* data_;
    T* data_end_;
  };

  /*
   * A two dimensional matrix view of a buffer. This class doesn't own the buffer
   */
  template<typename T>
  class Matrix2d {
  public:
    /*
     * Allows iterating through the different rows in the array
     */
    class VectorViewIterator {
    public:
      /*
       * Construct a VectorViewIterator
       * 
       * data: The buffer
       * size: the number of elements of type T in the buffer
       */
      VectorViewIterator(T* data, std::size_t size) : data_{data}, size_{size} {}

      /*
       * This method "extracts"" the contents from the iterator.
       * 
       * return a new VectorView wrapping the portion of the buffer
       * correspoding to a vector of size_ elements of type T
       */
      VectorView<T> get() const { return VectorView<T>(data_, size_); }

      /*
       * Updates the iterator to point to the next vector
       */
      void operator++() { data_ += size_; }

      /*
       * Comparison is based on the address of the buffer alone.
       * We may need to include also the size, if we ever use different
       * views into the same buffer
       */
      bool operator==(const VectorViewIterator& other) const {
	return data_ == other.data_;
      }

      /*
       * Counterpart of ==
       */
      bool operator!=(const VectorViewIterator& other) const {
	return data_ != other.data_;
      }      
    private:
      T* data_;
      std::size_t size_;
    };

    // For convenience, the type of the elements contained in the matrix
    typedef T Type;

    /* 
     * Constructs a matrix out of a buffer and dimenstions
     *
     * buffer, the data buffer
     * rows, the number of rows in the matrix
     * cols, the number of columns in the matrix*/
    Matrix2d(T* buffer, std::size_t rows, std::size_t cols) :
      data_{buffer}, cols_{cols}, rows_{rows}{}

    /*
     * The matrix doesn't own the buffer, so here we make sure
     * the destructor does nothing.
     */
    ~Matrix2d() {}

    /*
     * Get an iterator pointing to the first row in the matrix
     */
    VectorViewIterator begin() {
      return VectorViewIterator(data_, cols_);
    }

    const VectorViewIterator begin() const {
      return VectorViewIterator(data_, cols_);
    }    

    /*
     * Get an iterator pointing 1 past the last element in the 
     * last vector of the matrix
     */
    VectorViewIterator end() {
      return VectorViewIterator(data_ + rows_ * cols_, cols_);
    }

    const VectorViewIterator end() const {
      return VectorViewIterator(data_ + rows_ * cols_, cols_);
    }    
    
  private:
    T* data_;
    std::size_t cols_;
    std::size_t rows_;
  };

  template<typename T>
  std::ostream& operator<<(std::ostream& os, const Matrix2d<T>& matrix) {
    const auto& matrix_end = matrix.end();
    for (auto it = matrix.begin() ; it != matrix_end ; ++it) {
      const auto& vector_end = it.get().end();
      for (auto itv = it.get().begin() ; itv != vector_end ; ++itv) {
	os << *itv;
      }
      os << std::endl;
    }
    return os;
  }

} // namespace matrix

#endif /* MATRIX2D_H */
