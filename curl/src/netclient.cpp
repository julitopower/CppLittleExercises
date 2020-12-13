#include <functional>
#include <iostream>

#include <curl/curl.h>

#include "netclient.hpp"

namespace {
/*!
 * This class is used to manage the initalization and
 * cleanup of culr
 */
class LibCurlHandler {
 public:
  LibCurlHandler() {
    std::cout << "LibCurlHandler initialized\n";
    curl_global_init(CURL_GLOBAL_ALL);
  }

  ~LibCurlHandler() {
    std::cout << "LibCurlHandler deleted\n";
    curl_global_cleanup();
  }
};

// This is supposed to be a global handler that guarantees
// that curl only gets initialized and cleanedup once
  const LibCurlHandler libcurlhandler{};

// Curl reponse handler, to extract payload
void print_payload_fn(void *ptr, size_t size, size_t nmemb, void *stream) {
  std::cout << std::string{static_cast<char*>(ptr)} << std::endl;
}
};

namespace netclient {

std::ostream& operator<<(std::ostream& os, const URL& url) {
  os << url.str();
  return os;
}

HTTPClient::HTTPClient() {};

HTTPResponse HTTPClient::get(URL url) {
  std::cout << "Requesting: " << url.str() << "\n";
  CURL* curl = curl_easy_init();
  CURLcode res;
  curl_easy_setopt(curl, CURLOPT_URL, url.str().c_str());
  // In order to get the full response, libcurl requires that we
  // register a callback
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, print_payload_fn);
  
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  return HTTPResponse{};
}

}
