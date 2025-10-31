#include "driver.h"

namespace activeDriver {
	void Publisher::buildVertexShaders()
	{
		std::string in_path = std::string(SOURCE_DIR) + "/src/active/activeShaders/readable/vertex/";
		std::string out_path = std::string(SOURCE_DIR) + "/src/active/activeShaders/compiled/vertex/";
		try {
			for (const auto& entry : std::filesystem::directory_iterator(in_path)) {
				// Print the file name including the extension
				std::string inputFile = in_path + entry.path().filename().string();
				std::string outputFile = out_path + entry.path().filename().string()+".spv";
				std::cout << inputFile << std::endl;
				std::cout << outputFile << std::endl;
				std::string command = std::string(glslcPath) + " " + inputFile + " -o " + outputFile;
				int result = system(command.c_str());
				if (result == 0) {
					std::cout << "Shader compiled successfully to " << outputFile << std::endl;
				}
				else {
					std::cerr << "Failed to compile shader : "<< entry.path().filename().string() << std::endl;
				}
			}
		}
		catch (const std::filesystem::filesystem_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	void Publisher::buildFragmentShaders()
	{
		std::string in_path = std::string(SOURCE_DIR) + "/src/active/activeShaders/readable/fragment/";
		std::string out_path = std::string(SOURCE_DIR) + "/src/active/activeShaders/compiled/fragment/";
		try {
			for (const auto& entry : std::filesystem::directory_iterator(in_path)) {
				std::string inputFile = in_path + entry.path().filename().string();
				std::string outputFile = out_path + entry.path().filename().string() + ".spv";
				std::string command = std::string(glslcPath) + " " + inputFile + " -o " + outputFile;
				int result = system(command.c_str());
				if (result == 0) {
					std::cout << "Shader compiled successfully to " << outputFile << std::endl;
				}
				else {
					std::cerr << "Failed to compile shader : " << entry.path().filename().string() << std::endl;
				}
			}
		}
		catch (const std::filesystem::filesystem_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	void Publisher::buildComputeShaders()
	{

		std::string in_path = std::string(SOURCE_DIR) + "/src/active/activeShaders/readable/compute/";
		std::string out_path = std::string(SOURCE_DIR) + "/src/active/activeShaders/compiled/compute/";
		try {
			for (const auto& entry : std::filesystem::directory_iterator(in_path)) {
				std::string inputFile = in_path + entry.path().filename().string();
				std::string outputFile = out_path + entry.path().filename().string() + ".spv";
				std::string command = std::string(glslcPath) + " " + inputFile + " -o " + outputFile;
				int result = system(command.c_str());
				if (result == 0) {
					std::cout << "Shader compiled successfully to " << outputFile << std::endl;
				}
				else {
					std::cerr << "Failed to compile shader : " << entry.path().filename().string() << std::endl;
				}
			}
		}
		catch (const std::filesystem::filesystem_error& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	void Publisher::buildShaders()
	{
		buildVertexShaders();
		buildFragmentShaders();
		buildComputeShaders();
	}
}

namespace activeDriver {

	void Publisher::publish_vkExtensions() {
		instruction_writer::write_requiredValidationExtensions();
		instruction_writer::write_requiredInstanceExtensions();
		instruction_writer::write_requiredDeviceExtensions();
	}
}