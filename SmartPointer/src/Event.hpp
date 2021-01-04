#pragma once

#include <string>
#include <ostream>

class Event {
public:
  explicit Event(int eventType, std::string eventMessage);
  friend std::ostream& operator<<(std::ostream& os, const Event& event);
private:
  std::int64_t type_;
  std::string message_;
};

