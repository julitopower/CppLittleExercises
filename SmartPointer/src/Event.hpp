#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED
#include <string>

class Event {
    public:
        explicit Event(int eventType, std::string eventMessage);
  
    private:
        std::int64_t type_;
        std::string message_;  
};

#endif // EVENT_HPP_INCLUDED
