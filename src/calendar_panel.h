#pragma once
#include "ical.h"
#include <string>

class CalendarPanel {
public:
    void draw(ICal &cal);
    void drawEventPopup();
private:
    std::string getMonth();
    std::string getYear();
    int getStartDay();
    int getDaysInMonth();
    int getDaysInLastMonth();
    event_t popupEvent;
    bool isPopupOpen;
};
