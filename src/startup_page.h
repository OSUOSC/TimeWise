#pragma once

#include <vector>
#include <string>

class StartupPage {

	public:
		void draw();
	private:
		std::vector<const char*> getTasks();
		char* getDate();


};