#pragma once
#include <libical/ical.h>
#include <string>
#include <vector>

typedef struct event_t {
    std::string summary;
    time_t starttime;
    time_t endtime;
} event_t;

class ICal {
private:
    void parseEvent(icalcomponent *event);
public:
    void createICalDir();
    void downloadICalFiles();
    void loadICalFiles();
    void parseICal(const std::string &filepath);
    std::vector<event_t> events;
};
