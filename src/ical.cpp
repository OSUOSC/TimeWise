#include <ctime>
#include <iostream>
#include <fstream>
#include <libical/ical.h>
#include <filesystem>
#include <string>
#include "ical.h"

void ICal::parseEvent(icalcomponent *event) {
    event_t e;
    icalproperty* summary_prop = icalcomponent_get_first_property(event, ICAL_SUMMARY_PROPERTY);
    if (summary_prop)
        e.summary = icalproperty_get_value_as_string(summary_prop);
    
    icalproperty *desc_prop = icalcomponent_get_first_property(event, ICAL_DESCRIPTION_PROPERTY);
    if (desc_prop)
        e.desc = icalproperty_get_value_as_string(desc_prop);

    icalproperty* dtstart_prop = icalcomponent_get_first_property(event, ICAL_DTSTART_PROPERTY);
    if (dtstart_prop) {
        struct icaltimetype start_time = icalproperty_get_dtstart(dtstart_prop);
        e.starttime = icaltime_as_timet(start_time);
    }

    icalproperty* dtend_prop = icalcomponent_get_first_property(event, ICAL_DTEND_PROPERTY);
    if (dtend_prop) {
        struct icaltimetype end_time = icalproperty_get_dtend(dtend_prop);
        e.endtime = icaltime_as_timet(end_time);
    }
    tm *event_time = localtime(&e.starttime);
    std::string key = std::to_string(event_time->tm_mon) + std::to_string(event_time->tm_mday);
    events[key].push_back(e);
}

void ICal::parseICal(const std::string& filepath) {
    // Read iCal file into a string
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filepath << "\n";
        return;
    }
    std::string ical_content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    icalcomponent* root = icalparser_parse_string(ical_content.c_str());

    // Traverse through the components
    for (icalcomponent* comp = icalcomponent_get_first_component(root, ICAL_VEVENT_COMPONENT);
         comp != nullptr;
         comp = icalcomponent_get_next_component(root, ICAL_VEVENT_COMPONENT)) {
        parseEvent(comp);
    }

    icalcomponent_free(root);
}

void ICal::createICalDir() {
    const char* homeDir = std::getenv("HOME");
    if (!homeDir) {
        return;
    }
    std::filesystem::path configDir = std::filesystem::path(homeDir) / ".config" / "timewise";

    if (!std::filesystem::exists(configDir)) {
        try {
            std::filesystem::create_directories(configDir);
        } catch (const std::filesystem::filesystem_error& e) {
            return;
        }
    }

}

void ICal::loadICalFiles() {
    const char* homeDir = std::getenv("HOME");
    if (!homeDir) {
        return;
    }
    std::filesystem::path configDir = std::filesystem::path(homeDir) / ".config" / "timewise";
    try {
        if (std::filesystem::exists(configDir) && std::filesystem::is_directory(configDir)) {
            for (const auto& entry : std::filesystem::directory_iterator(configDir)) {
                if (entry.is_regular_file() && entry.path().extension() == ".ics") {
                    parseICal(entry.path().string());
                }
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } 
}
