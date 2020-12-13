#pragma once

#include <string>
#include <ostream>

namespace netclient {

/*! \brief Network client configuration
 *
 * It will include things like connection timeout.
 *
 * \TODO: Flesh out, it is empty for the moment
 */
struct NetClientConfig {
  // Timeouts and other parameters
};

/*! \brief https://tools.ietf.org/html/rfc2616#page-39 HTTP reponse
 *
 * See https://tools.ietf.org/html/rfc2616#page-39 for more details
 */
struct HTTPResponse {
  std::size_t code;
  std::string payload;
};

/*! \brief https://tools.ietf.org/html/rfc3986#section-3 URL
 *
 * Not all the components in RCF3986 are represented at the moment
 *
 */
struct URL {
  const std::string schema = "http";
  std::string host;
  std::size_t port;
  std::string path;

  std::string str() const {
    return schema + "://" + host + ":" + std::to_string(port) + path;
  }
};


class HTTPClient {
 public:
  HTTPClient();
  HTTPClient(NetClientConfig config);
  HTTPResponse get(URL url);
};

std::ostream& operator<<(std::ostream& os, const URL& url);

}
