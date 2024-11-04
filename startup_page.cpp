#include "startup_page.h"
#include "imgui.h"

void StartupPage::draw() {

	ImGui::Begin("Welcome");
	ImGuiIO& io = ImGui::GetIO();
	ImFont* bigUbuntu = io.Fonts->Fonts[1];
	ImGui::PushFont(bigUbuntu);
	ImGui::Text("Welcome To Time Wise!!");

	ImGui::SeparatorText("Today's Task");
	std::vector<const char*> tasks = getTasks();
	for (const auto& text : tasks) {
		ImGui::BulletText(text);
	}

	ImGui::PopFont();
	ImGui::End();

}

std::vector<const char*> StartupPage::getTasks() {

	std::vector<const char*> result;
	result.push_back("Filler1");
	result.push_back("Filler2");
	result.push_back("Filler3");
	result.push_back("Filler4");
	return result;
	
}