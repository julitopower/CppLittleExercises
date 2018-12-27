#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <typeinfo>

extern "C" {
#include <cblas.h>
}
namespace matrix {

  /*!
   * \brief Wraps a memory region with a vector like interface. 
   *
   * A VectorView does not own the buffer's memory. The VectorView can be used
   * to mutate the underlying data.
   */
  template<typename T>
  class VectorView {
  public:

    /*!
     * \brief Build A VectorView on top of the memory buffer.
     *
     * Caller must guarantee that size is correct, and that the memory is not
     * deleted while the VectorView is in use.
     */
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

  /*!
   * \brief A two dimensional matrix view of a buffer. This class doesn't own the buffer
   */
  template<typename T>
  class Matrix2d {
  public:
    /*!
     * \brief Allows iterating through the different rows in the array
     */
    class VectorViewIterator {
    public:
      /*!
       * \brief Construct a VectorViewIterator
       * 
       * \param data The buffer
       * \param size the number of elements of type T in the buffer
       */
      VectorViewIterator(T* data, std::size_t size) : data_{data}, size_{size} {}

      /*!
       * \brief This method "extracts"" the contents from the iterator.
       * 
       * \return a new VectorView wrapping the portion of the buffer
       * correspoding to a vector of size_ elements of type T
       */
      VectorView<T> get() const { return VectorView<T>(data_, size_); }

      /*!
       * \brief Update the iterator to point to the next vector
       */
      void operator++() { data_ += size_; }

      /*!
       * \brief Comparison is based on the address of the buffer alone.
       * 
       * We may need to include also the size, if we ever use different
       * views into the same buffer
       */
      bool operator==(const VectorViewIterator& other) const {
	return data_ == other.data_;
      }

      /*!
       * \brief Counterpart of ==
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

    /*!
     * \brief Constructs a matrix out of a buffer and dimenstions
     *
     * \param buffer the data buffer
     * \param rows the number of rows in the matrix
     * \param cols the number of columns in the matrix
     * \param owns_buffer Indicate if this Matrix owns the memory in the buffer. Memory will
     *        be released upon Matrix2d destruction if it owns the memory.
     */
     Matrix2d(T buffer[],
	      std::size_t rows,
	      std::size_t cols,
	      bool owns_buffer = false) :
	 data_{buffer}, rows_{rows}, cols_{cols}, owns_buffer_{owns_buffer}{}

    /*!
     * \brief Matrix2d is not copiable, because memory ownership becomes very complex
     *
     * It is movable instead.
     */
    Matrix2d(const Matrix2d& rhs) = delete;

    /*!
     * \brief Move constructor
     *
     * Memory ownership is passed on to the object we move into
     */
    Matrix2d(Matrix2d&& rhs) :
	data_{rhs.data_}, rows_{rhs.rows_}, cols_{rhs.cols_},
	owns_buffer_{rhs.owns_buffer_} {
	rhs.owns_buffer_ = false;
	rhs.data_ = nullptr;
    }

      
    /*!
     * \brief The matrix doesn't own the buffer, so here we make sure
     * the destructor does nothing.
     */
    ~Matrix2d() {
	if (owns_buffer_ && data_ != nullptr) {
	    delete[] data_;
	}
    }

    /*!
     * \brief Get an iterator pointing to the first row in the matrix
     */
    VectorViewIterator begin() {
      return VectorViewIterator(data_, cols_);
    }

    /*!
     * \brief Get a const iterator pointing to the first row in the matrix
     */      
    const VectorViewIterator begin() const {
      return VectorViewIterator(data_, cols_);
    }    

    /*!
     * \brief Get an iterator pointing 1 past the last element in the 
     * last vector of the matrix
     */
    VectorViewIterator end() {
      return VectorViewIterator(data_ + rows_ * cols_, cols_);
    }

    /*!
     * \brief Get a const iterator pointing 1 past the last element in the 
     * last vector of the matrix
     */      
    const VectorViewIterator end() const {
      return VectorViewIterator(data_ + rows_ * cols_, cols_);
    }

    /*!
     * \brief Get the shape of the array <rows, cols>
     */
    std::vector<std::size_t> shape() const {
	return {rows_, cols_};
    }

    /*!
     * \brief Generate a Matrix2d with random values
     *
     * Values are in the range [0, RAND_MAX]
     */
    static Matrix2d<T> random(std::size_t rows, std::size_t cols, int seed = 42) {
	srand(seed);
	return fill_matrix_with(rows, cols, []() { return static_cast<T>(rand()); });	
    }

    /*! 
     * \brief Generate a Matrix2d filled with ones
     */
    static Matrix2d<T> ones(std::size_t rows, std::size_t cols) {
	return fill_matrix_with(rows, cols, []() { return static_cast<T>(1); });
    }

    /*! 
     * \brief Generate a Matrix2d filled with zeros
     */
    static Matrix2d<T> zeros(std::size_t rows, std::size_t cols) {
	return fill_matrix_with(rows, cols, []() { return static_cast<T>(0); });
    }

    ////////////////////////////////////////////////////////////////////////////////
    // Arithmetic operators
    ////////////////////////////////////////////////////////////////////////////////
    Matrix2d<T> operator*(const Matrix2d<T>& rhs) {
	throw std::logic_error{"Operator * not implemented for type " +
		               std::string{typeid(T).name()}};
    }
      
  private:
    T* data_;
    std::size_t rows_;
    std::size_t cols_;      
    bool owns_buffer_;

    template <typename FUNC>
    static inline Matrix2d<T> fill_matrix_with(std::size_t rows,
					std::size_t cols,
					FUNC value_generator) {
	const std::size_t size{rows * cols};
	auto buffer = std::make_unique<T[]>(rows * cols);
	for (auto i = 0U ; i < size ; ++i) {
	    buffer[i] = value_generator();
	}	
	return Matrix2d<T>(buffer.release(), rows, cols, true);
    }            
  };

  template<typename T>
  std::ostream& operator<<(std::ostream& os, const Matrix2d<T>& matrix) {
    const auto& matrix_end = matrix.end();
    for (auto it = matrix.begin() ; it != matrix_end ; ++it) {
      const auto& vector_end = it.get().end();
      for (auto itv = it.get().begin() ; itv != vector_end ; ++itv) {
	os << *itv << ", ";
      }
      os << std::endl;
    }
    return os;
  }

  template<>
  Matrix2d<double> Matrix2d<double>::operator*(const Matrix2d<double>& rhs) {
      const auto M = rows_;
      const auto N = rhs.shape()[1];
      const auto K = cols_;
      const auto alpha = 1.;
      const auto beta = 0.;
      auto tmp = Matrix2d::ones(M, N);
      cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, M, N, K,
		  alpha, data_, M, rhs.data_, K, beta, tmp.data_, M);
      return tmp;
  }

  template<>
  Matrix2d<float> Matrix2d<float>::operator*(const Matrix2d<float>& rhs) {
      const auto M = rows_;
      const auto N = rhs.shape()[1];
      const auto K = cols_;
      const auto alpha = 1.f;
      const auto beta = 0.f;
      auto tmp = Matrix2d::ones(M, N);
      cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, M, N, K,
		  alpha, data_, M, rhs.data_, K, beta, tmp.data_, M);
      return tmp;
  }        
    
} // namespace matrix

#endif /* MATRIX2D_H */
