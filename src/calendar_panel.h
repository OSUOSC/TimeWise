#pragma once
#include <string>

class CalendarPanel {
public:
    void draw();
private:
    std::string getMonth();
    std::string getYear();
    int getStartDay();
    int getDaysInMonth();
    int getDaysInLastMonth();
};
