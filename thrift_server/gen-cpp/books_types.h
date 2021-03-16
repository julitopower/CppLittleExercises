/**
 * Autogenerated by Thrift Compiler (0.14.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef books_TYPES_H
#define books_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace store { namespace books {

class Book;

typedef struct _Book__isset {
  _Book__isset() : id(false), Title(false), Author(false), numPages(false) {}
  bool id :1;
  bool Title :1;
  bool Author :1;
  bool numPages :1;
} _Book__isset;

class Book : public virtual ::apache::thrift::TBase {
 public:

  Book(const Book&);
  Book& operator=(const Book&);
  Book() : id(0), Title(), Author(), numPages(0) {
  }

  virtual ~Book() noexcept;
  int32_t id;
  std::string Title;
  std::string Author;
  int16_t numPages;

  _Book__isset __isset;

  void __set_id(const int32_t val);

  void __set_Title(const std::string& val);

  void __set_Author(const std::string& val);

  void __set_numPages(const int16_t val);

  bool operator == (const Book & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(Title == rhs.Title))
      return false;
    if (!(Author == rhs.Author))
      return false;
    if (!(numPages == rhs.numPages))
      return false;
    return true;
  }
  bool operator != (const Book &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Book & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Book &a, Book &b);

std::ostream& operator<<(std::ostream& out, const Book& obj);

}} // namespace

#endif