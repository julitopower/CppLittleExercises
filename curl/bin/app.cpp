#include <iostream>

#include "netclient.hpp"

int main(int argc, char *argv[]) {
  std::cout << "Curl based HTTP client\n";
  netclient::URL url{"http://", "www.google.com", 80, "/"};
  netclient::HTTPClient httpclient{};
  httpclient.get(url);
  
  return 0;
}
