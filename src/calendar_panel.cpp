#include "calendar_panel.h"
#include "imgui.h"

CalendarPanel::CalendarPanel() {}

void CalendarPanel::draw() {
    ImGui::Begin("Calendar");
    ImGui::Text("October");
    
    ImGui::End();
}
