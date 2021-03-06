// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Catalog.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::store::books;

class CatalogHandler : virtual public CatalogIf {
 public:
  CatalogHandler() {
    // Your initialization goes here
  }

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

  void deep_ping() {
    // Your implementation goes here
    printf("deep_ping\n");
  }

  void getBookById(Book& _return, const int32_t id) {
    // Your implementation goes here
    printf("getBookById\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<CatalogHandler> handler(new CatalogHandler());
  ::std::shared_ptr<TProcessor> processor(new CatalogProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

