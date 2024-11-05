#include "startup_page.h"
#include "imgui.h"
#include <ctime>

void StartupPage::draw() {
	//set up window and font 
	ImGui::Begin("Welcome");
	ImGuiIO& io = ImGui::GetIO();
	ImFont* textFont = io.Fonts->Fonts[1];
	ImFont* titleFont = io.Fonts->Fonts[2];
	ImGui::PushFont(titleFont);

	//title text
	ImGui::Text("Welcome To Time Wise!!!");
	ImGui::PopFont();

	//section 1: description about the app
	ImGui::PushFont(textFont);
	ImGui::SeparatorText("About this app");
	ImGui::Text("TimeWise is a calendar app that helps integrate and manage your calendar and daily events");
	
	//section 2: task list
	ImGui::SeparatorText("Today's Task");
	//display today's date 
	char* time = getDate();
	ImGui::Text("Today is: ");
	ImGui::SameLine(); ImGui::Text(time);

	//task list of the day 
	std::vector<const char*> tasks = getTasks();
	for (const auto& text : tasks) {
		ImGui::BulletText(text);
	}

	ImGui::PopFont();
	ImGui::End();

}

std::vector<const char*> StartupPage::getTasks() {

	//TO DO pull events from the calender 
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