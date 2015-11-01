#include "Path.h"

#include <cstdlib>

std::string currentPath() {
	static char* cwd = nullptr;
	if(cwd == nullptr)
		cwd = std::getenv("PWD");
	return std::string(cwd);
}

