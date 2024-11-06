#pragma once
#include "ical.h"
#include <string>

class CalendarPanel {
public:
    void draw(ICal &cal);
private:
    std::string getMonth();
    std::string getYear();
    int getStartDay();
    int getDaysInMonth();
    int getDaysInLastMonth();
};
