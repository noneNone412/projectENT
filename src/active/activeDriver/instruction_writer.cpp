#include "driver.h"

// private
namespace activeDriver {
	void instruction_writer::makeDirectory()
	{
	}
	void instruction_writer::writeFile(const std::string &filename,nlohmann::json &jsonData)
	{
		// encryption begins

		// encryption ends

		std::ofstream file(read_location + filename);
		if (file.is_open()) {
			file << jsonData.dump(4);
			file.close();
			std::cout << "JSON data successfully written to " << filename << std::endl;
		}
		else {
			std::cerr << "Unable to open file for writing." << std::endl;
		}
	}
}
// public
namespace activeDriver {
	std::string instruction_writer::encrypt(const std::string data)
	{
		return data;
	}
	void instruction_writer::write_requiredInstanceExtensions(){/*
		// write vulkan extensions here
		// Add some data to it
		//jsonObject["name"] = "John Doe";
		//jsonObject["age"] = 30;
		//jsonObject["isStudent"] = false; 
		nlohmann::json jsonObject;
		jsonObject[activeConstants::Constants::required_instance_extensions] = { 
			  VK_EXT_DEBUG_UTILS_EXTENSION_NAME
		};
		// "VK_KHR_win32_surface"
		//""VK_EXT_debug_utils"",
		//"VK_KHR_surface",
		std::string filePath = directory + activeConstants::Constants::required_instance_extensions + ".json";
		std::cout << filePath << "\n";
		std::ofstream outFile(filePath);

		// Check if the file was opened successfully
		if (outFile.is_open()) {

			// Write the JSON object to the file
			outFile << encrypt(jsonObject.dump(4));
			// The number 4 is for pretty-printing with an indentation of 4 spaces
			outFile.close();
		}
		else {
			std::cerr << "Could not open file for writing!" << std::endl;
		}
		*/}
	void instruction_writer::write_requiredValidationExtensions()
	{
		/*
		
		// write vulkan extensions here
		// Add some data to it
		//jsonObject["name"] = "John Doe";
		//jsonObject["age"] = 30;
		//jsonObject["isStudent"] = false; 
		nlohmann::json jsonObject;
		jsonObject[activeConstants::Constants::required_validation_extensions] = { "VK_LAYER_KHRONOS_validation" };
		std::string filePath = directory + activeConstants::Constants::required_validation_extensions + ".json";
		std::cout << filePath << "\n";
		std::ofstream outFile(filePath);

		// Check if the file was opened successfully
		if (outFile.is_open()) {

			// Write the JSON object to the file
			outFile << encrypt(jsonObject.dump(4));
			// The number 4 is for pretty-printing with an indentation of 4 spaces
			outFile.close();
		}
		else {
			std::cerr << "Could not open file for writing!" << std::endl;
		}
		*/
	}


	void instruction_writer::write_requiredDeviceExtensions() {
		//nlohmann::json jsonObject;
		nlohmann::json j_array= nlohmann::json::array();
		
	}
	void instruction_writer::write_vkBuffer(const std::string filename)
	{
		nlohmann::json jsonData;
		// 
		//
		writeFile(filename,jsonData);
	}
}