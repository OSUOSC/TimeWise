#pragma once
#include <string>

class NewEvent {
public:
    static void makeEvent();

    static void setEvent(bool set) {
        makeNew = set;
    }

    static bool getEvent() {
        return makeNew;
    }
private:
    NewEvent() {}
    NewEvent(const NewEvent&) = delete; 
    void operator=(const NewEvent&) = delete; 

    static bool makeNew;
    
};
