
// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include <iostream>

#include "Catalog.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TTransport.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::store::books;

int main(int argc, char **argv) {
  int port = 9090;

  ::std::shared_ptr<TSocket> socket{new TSocket{"localhost", port}};
  ::std::shared_ptr<TTransport> transport{new TBufferedTransport{socket}};
  ::std::shared_ptr<TProtocol> protocol{new TBinaryProtocol{transport}};
  transport->open();

  CatalogClient client{protocol};
  Book b{};
  client.getBookById(b, 32);
  b.printTo(std::cout);
  std::cout << std::endl;

  transport->close();
  return 0;
}

