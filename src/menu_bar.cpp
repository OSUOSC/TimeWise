#include "menu_bar.h"
#include "imgui.h"
#include "theme.h"

void MenuBar::draw(GLFWwindow *window, int &theme) {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::BeginMenu("New")) {
                if (ImGui::MenuItem("Event")) {
                }
                ImGui::EndMenu();
            }

            if (ImGui::MenuItem("Exit")) {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Settings")) {
            if (ImGui::BeginMenu("Theme")) {
                if (ImGui::MenuItem("Moonlight", NULL, theme == 0)) {
                    theme = 0;
                }
                if (ImGui::MenuItem("Gray Dark", NULL, theme == 1)) {
                    theme = 1;
                }
                if (ImGui::MenuItem("Classic Dark", NULL, theme == 2)) {
                    theme = 2;
                }
                if (ImGui::MenuItem("Retro Steam", NULL, theme == 3)) {
                    theme = 3;
                }
                if (ImGui::MenuItem("Red Dark", NULL, theme == 4)) {
                    theme = 4;
                }
                if (ImGui::MenuItem("Comfy Dark", NULL, theme == 5)) {
                    theme = 5;
                }
                if (ImGui::MenuItem("Ruda Dark", NULL, theme == 6)) {
                    theme = 6;
                }
                if (ImGui::MenuItem("Cyberpunk", NULL, theme == 7)) {
                    theme = 7;
                }
                if (ImGui::MenuItem("Future Dark", NULL, theme == 8)) {
                    theme = 8;
                }
                if (ImGui::MenuItem("Classic Light", NULL, theme == 9)) {
                    theme = 9;
                }
                if (ImGui::MenuItem("Oxidized", NULL, theme == 10)) {
                    theme = 10;
                }
                if (ImGui::MenuItem("Retro Light", NULL, theme == 11)) {
                    theme = 11;
                }
                ImGui::StyleColorsDark();
                SetImguiTheme(theme);
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}
