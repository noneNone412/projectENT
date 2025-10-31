#pragma once
#include "../../activeConstants/constants.h"
#include "../InstructionReader/InstructionReader.h"
#include "../VulkanVariables/VulkanVariables.h"

namespace activeEngine {

	class SetupManager :private InstructionReader {
	public:
		bool framebufferResized = false;
	private:
		VulkanVariables* var;
		VkDebugUtilsMessengerEXT debugMessenger;
		
	public:
		SetupManager(VulkanVariables* variables);
	private:
		void iterateMemoryType();
		// debug messenger
		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData) {
			std::cerr << "Validation layer: " << pCallbackData->pMessage << std::endl;
			return VK_FALSE;
		}
		static VKAPI_ATTR void* VKAPI_CALL customAlloc(
			void* pUserData,
			size_t size,
			size_t alignment,
			VkSystemAllocationScope allocationScope) {
			// Your custom allocation logic here
			return malloc(size); // Example: using malloc for simplicity
		}

		static VKAPI_ATTR void* VKAPI_CALL customRealloc(
			void* pUserData,
			void* pOriginal,
			size_t size,
			size_t alignment,
			VkSystemAllocationScope allocationScope) {
			// Your custom reallocation logic here
			return realloc(pOriginal, size); // Example: using realloc for simplicity
		}

		static VKAPI_ATTR void VKAPI_CALL customFree(
			void* pUserData,
			void* pMemory) {
			// Your custom free logic here
			free(pMemory); // Example: using free for simplicity
		}

		void set_vkDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessengerCreateInfoEXT& vkDebugUtilsMessengerCreateInfoEXT);
		void set_vkAllocationCallbacks(VkAllocationCallbacks& allocationCallbacks);
		// glfw
		void create_glfwWindow(int WIDTH, int HEIGHT);
		// vulkan
		void enumerate_instanceExt();
		bool check_vkInstanceExtensions();

		void create_vkInstance();
		void setup_vkDebugLayer();
		void create_vkSurface();
		void pick_vkPhysicalDevice();

		void enumerate_vkQueues();
		void enumerate_vkDeviceExtensions();
		void enumerate_vkDeviceFeatures();
		void create_vkLogicalDevice();

		void enumerate_swapChainCapabilities();
		void create_vkSwapchain();

		void create_vkImageViews();

		void create_vkRenderPass();
		void create_vkFramebuffer();

		void inflate_deviceLimits();
		void iterate_deviceLimits();

	public:
		void setup();
		void destroy();
		void handle_window_resize();
	};
}