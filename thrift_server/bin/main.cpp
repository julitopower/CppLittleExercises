#include <iostream>

#include "books_types.h"

int main(int argc, char *argv[]) {
  using namespace store::books;
  std::cout << "Starting app..." << std::endl;

  // First book in the collection
  Book b{};
  b.id = 0;
  b.Author = "Julio Delgado";
  b.Title = "Elisp is awesome";
  b.numPages = 42;

  b.printTo(std::cout);
  std::cout << std::endl;

  return 0;
}
