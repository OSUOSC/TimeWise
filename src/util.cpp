#include "util.h"
#include "imgui.h"

namespace ImGui {

void RightText(const char* text) {
    float text_width = ImGui::CalcTextSize(text).x;
    float cursor_x = ImGui::GetCursorPosX();
    float available_width = ImGui::GetContentRegionAvail().x;
    ImGui::SetCursorPosX(cursor_x + (available_width - text_width));
    ImGui::TextUnformatted(text);
}

}
