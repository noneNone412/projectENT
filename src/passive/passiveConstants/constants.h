#pragma once
#include<string>
#include<vulkan/vulkan.h>
#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <stdexcept>
#include "../../external files/json/json.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

namespace activeConstants {
	class Constants {
	protected:
		const std::string read_location = "";
		const std::string write_location = "";

	};
}