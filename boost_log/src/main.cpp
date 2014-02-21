#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    boost::log::add_file_log("julio.log");
    BOOST_LOG_TRIVIAL(info) << "Starting application";
    BOOST_LOG_TRIVIAL(debug) << "More detailed message";
    std::cout << "Hello World" << std::endl;
}
