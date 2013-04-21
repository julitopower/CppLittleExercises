#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED
#include <string>

class Event {
    private:
        int type;
        std::string message;
    public:
        Event(int eventType, std::string eventMessage);
};


#endif // EVENT_HPP_INCLUDED
