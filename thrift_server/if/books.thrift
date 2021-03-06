namespace cpp store.books

struct Book {
  1: i32 id,
  2: required string Title,
  3: required string Author,
  4: i16 numPages,
}

service Catalog {
  void ping(),
  void deep_ping(),
  Book getBookById(1:i32 id), 
}
