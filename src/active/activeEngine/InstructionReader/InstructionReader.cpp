#include"../Engine/Engine.h"
#include "InstructionReader.h"


namespace activeEngine {
	void InstructionReader::decrypt() {
	
	}
    nlohmann::json InstructionReader::readFile(const std::string filepath)
	{
        nlohmann::json jsonObject;

		std::ifstream file(filepath);

		if (!file.is_open()) {
			throw std::runtime_error("File not found: " + filepath);
		}

		// Proceed with file processing
		std::cout << "File opened successfully." << std::endl;
        // decrypt here
        file >> jsonObject;
		// Don't forget to close the file when done
		file.close();

        return jsonObject;
	}
    
}