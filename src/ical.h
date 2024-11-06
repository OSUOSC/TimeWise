#pragma once
#include <libical/ical.h>
#include <string>
#include <unordered_map>
#include <vector>

typedef struct event_t {
    std::string summary;
    std::string desc;
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
    std::unordered_map<std::string, std::vector<event_t>> events;
};
