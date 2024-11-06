#include <ctime>
#include <array>
#include <string>
#include "calendar_panel.h"
#include "ical.h"
#include "imgui.h"
#include "util.h"
#include "new_event.h"

void CalendarPanel::draw(ICal &cal) {
    ImGui::Begin("Calendar");
    ImGuiIO& io = ImGui::GetIO();
    ImFont* bigUbuntu = io.Fonts->Fonts[1];
    ImGui::PushFont(bigUbuntu);
    ImGui::TextUnformatted(getMonth().c_str());
    ImGui::SameLine();
    ImGui::RightText(getYear().c_str());
    ImGui::PopFont();

    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

    ImVec2 available_size = ImGui::GetContentRegionAvail();
    int row_count = 5;
    float row_height = (available_size.y - 42) / row_count;

    if (ImGui::BeginTable("calendar", 7, flags, ImVec2(available_size.x, available_size.y - 42)))
    {
        ImGui::TableSetupColumn("SUN");
        ImGui::TableSetupColumn("MON");
        ImGui::TableSetupColumn("TUE");
        ImGui::TableSetupColumn("WED");
        ImGui::TableSetupColumn("THU");
        ImGui::TableSetupColumn("FRI");
        ImGui::TableSetupColumn("SAT");
        ImGui::TableHeadersRow();

        int maxDays = getDaysInLastMonth();
        int startDay = getStartDay();
        int currentDay;
        if (startDay == 0) {
            currentDay = 1;
            maxDays = getDaysInMonth();
        } else {
            currentDay = getDaysInLastMonth() - startDay;
        }
        for (int row = 0; row < row_count; row++)
        {
            ImGui::TableNextRow(ImGuiTableRowFlags_None, row_height);
            for (int column = 0; column < 7; column++)
            {
                ImGui::TableSetColumnIndex(column);
                ImGui::TextUnformatted(std::to_string(currentDay).c_str());
                // print any events in the day
                std::time_t t = std::time(nullptr);
                std::tm* localTime = std::localtime(&t);

                int monthIndex = localTime->tm_mon;
                std::string key = std::to_string(monthIndex) + std::to_string(currentDay);
                if (!cal.events[key].empty()) {
                    for (auto &event : cal.events[key]) {
                        std::string event_label = std::to_string(localtime(&event.starttime)->tm_hour) + ":";
                        if (localtime(&event.starttime)->tm_min < 10) {
                            event_label += "0";
                        }
                        event_label += std::to_string(localtime(&event.starttime)->tm_min) + " " + event.summary;
                        if (ImGui::Button(event_label.c_str())) {
                            popupEvent = event;
                            isPopupOpen = true;
                        }
                    }
                }
                
                currentDay++;
                if (currentDay >= maxDays) {
                    currentDay = 1;
                    maxDays = getDaysInMonth();
                }
            }
        }
        ImGui::EndTable();

        // Open createEvent here because it is a modal of calendar
        if (NewEvent::getEvent()) {
            NewEvent::makeEvent();
        }

    }

    ImGui::End();
}

void CalendarPanel::drawEventPopup() {
    if (!isPopupOpen)
        return;

    ImGui::OpenPopup("Event Details");
    isPopupOpen = ImGui::BeginPopupModal("Event Details", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
    if (isPopupOpen) {
        ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionMax().x);
        ImGui::TextUnformatted(popupEvent.summary.c_str());
        ImGui::Separator();
        ImGui::TextUnformatted(popupEvent.desc.c_str());
        ImGui::PopTextWrapPos();
        ImGui::NewLine();
        if (ImGui::Button("Close")) {
            isPopupOpen = false;
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
}

std::string CalendarPanel::getMonth() {
    const std::array<std::string, 12> monthNames = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    int monthIndex = localTime->tm_mon;

    return monthNames[monthIndex];
}

std::string CalendarPanel::getYear() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    int year = localTime->tm_year + 1900;
    return std::to_string(year);
}

int CalendarPanel::getStartDay() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    localTime->tm_mday = 1;

    std::mktime(localTime);

    return localTime->tm_wday;
}

int CalendarPanel::getDaysInMonth() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    std::tm timeIn = {0, 0, 0, 1, localTime->tm_mon, localTime->tm_year};

    if (++timeIn.tm_mon == 12) {
        timeIn.tm_mon = 0;
        timeIn.tm_year++;
    }
    std::mktime(&timeIn);

    timeIn.tm_mday = 0;
    std::mktime(&timeIn);
    return timeIn.tm_mday + 1;
}

int CalendarPanel::getDaysInLastMonth() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);

    int month = localTime->tm_mon;  // Current month (0-based)
    int year = localTime->tm_year + 1900;  // Current year

    if (month == 0) { // January
        month = 11;  // December
        year--;      // Previous year
    } else {
        month--;  // Move to the previous month
    }

    std::tm timeIn = {0, 0, 0, 1, month, year - 1900}; // month is 0-based, year is years since 1900

    if (++timeIn.tm_mon == 12) {
        timeIn.tm_mon = 0;  // Wrap around to January
        timeIn.tm_year++;    // Move to next year
    }
    std::mktime(&timeIn);

    timeIn.tm_mday = 0; // This moves to the last day of the previous month

    std::mktime(&timeIn);
    return timeIn.tm_mday + 1;
}
