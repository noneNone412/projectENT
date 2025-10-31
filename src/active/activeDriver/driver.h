#pragma once
#include "../activeConstants/constants.h"

namespace activeDriver {

	class HardwareConfigure {
	private:
		// configure some map here for the gpu
	private:
	};

	class instruction_writer :activeConstants::Constants, private HardwareConfigure {
		// variables
	private:
		const std::string directory = activeConstants::Constants::write_location;
		std::string selectedGPU;
		// functions
	private:
		std::string encrypt(const std::string data);
		void makeDirectory();
		void writeFile(const std::string& filename, nlohmann::json& jsonData);
	protected:

		void write_requiredInstanceExtensions();
		void write_requiredValidationExtensions();
		void write_requiredDeviceExtensions();

		// render pass
		void write_vkBuffer(const std::string filename);
		void write_vkBufferView();
		void write_vkCommandBuffer();
		void write_vkComputePipelines();
		void write_vkDescriptorPool();
		void write_vkDescriptorwriteLayout();
		void write_vkDescriptorUpdaterTemplater();
		void write_vkEvent();
		void write_vkFence();
		void write_vkFramebuffer();
		void write_vkGraphicPipeline();
		void write_vkImage();
		void write_vkImageView();
		void write_vkPipelineCache();
		void write_vkPipelineLayout();
		void write_vkQueryPool();
		void write_vkRenderPass();
		void write_vkRenderPass2();
		void write_vkSampler();
		void write_vkSamplerYcbcrConversion();
		void write_vkSemaphore();
		void write_vkShaderModule();

	};

	class Story :private instruction_writer {};

	class Script :private instruction_writer {};

	class Publisher :private instruction_writer {
	private:
		const char* glslcPath = "C:\\VulkanSDK\\Bin\\glslc.exe";
	private:
		void buildVertexShaders();
		void buildFragmentShaders();
		void buildComputeShaders();
	public:
		void publish_vkExtensions();
		void buildShaders();
	};

	class Driver {
	private:
		Publisher publisher;
		Story story;
		Script script;
	public:

	public:
		void begin();
		void run();
		void stop();
	};
}