#include "import_cal.h"
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

bool ImportCalendar::openImport = false;

void ImportCalendar::drawImport() {
    if (!openImport) {
        return;
    }
    ImGui::OpenPopup("Import Calendar");
    if (ImGui::BeginPopupModal("Import Calendar"))
    {
        ImGui::Text("You can import from Carmen, Google, and anything that supports .ics files.");
        static char linkical[256] = "";
        ImGui::Text("Insert iCal link");
        ImGui::InputText("##iCal", linkical, sizeof(linkical));

        if (ImGui::Button("Import")) {
            // Importing actions

            // Close popup
            ImGui::CloseCurrentPopup();
            ImportCalendar::setImport(false);
        }

        if (ImGui::Button("Close")) {
            ImGui::CloseCurrentPopup();
            ImportCalendar::setImport(false);
        }
        ImGui::EndPopup();
    }
}