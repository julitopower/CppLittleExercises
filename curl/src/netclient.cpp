#include <iostream>

#include "netclient.hpp"

namespace netclient {

std::ostream& operator<<(std::ostream& os, const URL& url) {
  os << url.schema << "://" << url.host << ":" << url.port << url.path;
  return os;
}

HTTPClient::HTTPClient() {};

HTTPResponse HTTPClient::get(URL url) {
  std::cout << url << "\n";
  return HTTPResponse{};
}

}


