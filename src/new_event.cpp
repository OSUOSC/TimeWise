// Define the lowest year that the picker can select. In this example, '1970' is the Unix epoch.
#define IMGUI_DATEPICKER_YEAR_MIN 1970
// Define the highest year that the picker can select.
#define IMGUI_DATEPICKER_YEAR_MAX 2500
#include <ImGuiDatePicker.hpp>
#include <chrono>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <new_event.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
bool NewEvent::makeNew = false;

void NewEvent::makeEvent() {
    if (makeNew == false) {
        return;
    }
    ImGui::OpenPopup("Stacked 1");
    if (ImGui::BeginPopupModal("Stacked 1"))
    {
        static char eventName[128] = "";
        static char eventLocation[128] = "";
        const char* hours[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" };
        const char* minutes[60] = {};
        static int currentHour = 1;
        static int currentMinute = 0;
        static int ampm = 0;
        static int repeatable = 0;

        ImGui::Text("Create New Event");
        ImGui::Text("Event Name");
        ImGui::InputText("##EventName", eventName, sizeof(eventName));
        ImGui::Text("Location");
        ImGui::InputText("##Location", eventLocation, sizeof(eventLocation));
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        tm t = *std::gmtime(&currentTime);
        static tm setDate = t;
        ImGui::Text("Date");
        // Use the picker for date
        if (ImGui::DatePicker("", setDate))
        {
            // Perform some event whenever the date 't' is changed
        }
        // Time
        ImGui::Text("Time");
        ImGui::PushItemWidth(80);
        // Hours and minutes picker
        ImGui::ListBox("Hour", &currentHour, hours, IM_ARRAYSIZE(hours), 4); ImGui::PushItemWidth(80); ImGui::SameLine();
        for (int i = 0; i < 60; i++) {
            char* minuteStr = new char[3];
            snprintf(minuteStr, 3, "%02d", i);
            minutes[i] = minuteStr;
        }
        ImGui::ListBox("Minute", &currentMinute, minutes, IM_ARRAYSIZE(minutes), 4); ImGui::PushItemWidth(60); ImGui::SameLine();
        // AM/PM Picker
        ImGui::RadioButton("AM", &ampm, 0); ImGui::SameLine();
        ImGui::RadioButton("PM", &ampm, 1);

        // Repeat Event
        ImGui::Text("Repeat");
        ImGui::RadioButton("Never", &repeatable, 0); ImGui::SameLine();
        ImGui::RadioButton("Daily", &repeatable, 1); ImGui::SameLine();
        ImGui::RadioButton("Weekly", &repeatable, 2); ImGui::SameLine();
        ImGui::RadioButton("Monthly", &repeatable, 3); ImGui::SameLine();
        ImGui::RadioButton("Yearly", &repeatable, 4);

        if (ImGui::Button("Create")) {
            // Put event on calendar here

            // Close popup
            ImGui::CloseCurrentPopup();
            NewEvent::setEvent(false);
        }

        if (ImGui::Button("Close")) {
            ImGui::CloseCurrentPopup();
            NewEvent::setEvent(false);
        }
        ImGui::EndPopup();
    }
}
