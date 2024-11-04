#include "startup_page.h"
#include "imgui.h"
#include <ctime>

void StartupPage::draw() {
	//set up window and font 
	ImGui::Begin("Welcome");
	ImGuiIO& io = ImGui::GetIO();
	ImFont* bigUbuntu = io.Fonts->Fonts[1];
	ImGui::PushFont(bigUbuntu);

	//title text
	ImGui::Text("Welcome To Time Wise!!!");

	//Display today's date 
	char* time = getDate();
	ImGui::Text("Today is: ");
	ImGui::SameLine(); ImGui::Text(time);


	//task list of the day 
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

char* StartupPage::getDate() {

	std::time_t result = std::time(nullptr);
	std::tm* localTime = std::localtime(&result);
	char* time = new char[80];
	strftime(time, 80, "%B%e %Y", localTime);

	return time;

}