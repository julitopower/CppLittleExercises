#include "Event.hpp"

Event::Event(int eventType, std::string eventMessage):
        type_(eventType), message_(eventMessage) {
}

std::ostream& operator<<(std::ostream& os, const Event& event) {
  os << event.type_ << " " << event.message_;
  return os;
}
