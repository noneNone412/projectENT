#pragma once
#include "../../activeConstants/constants.h"

namespace activeEngine {


	class VulkanVariables {
		// only variables here
	private:
		// setup manager 
		GLFWwindow* window;
		VkPhysicalDevice physicalDevice;
		VkDevice device;
		VkInstance vkInstance;
		VkAllocationCallbacks vkAllocationCallbacks;
		VkSurfaceKHR vkSurfaceKHR;
		VkPhysicalDevice vkPhysicalDevice;
		VkPhysicalDeviceProperties vkPhysicalDeviceProperties;
		VkDevice vkDevice;
		VkSwapchainKHR vkSwapchainKHR;
		VkSurfaceFormatKHR surfaceFormat;
		std::vector<VkImageView> swapChainImageViews;
		std::vector<VkFramebuffer> swapChainFrameBuffers;
		std::vector<VkImage> swapChainImages;
		VkRenderPass  vkRenderPass;
		VkPipeline vkPipeline;
		VkExtent2D frameExtent;

		int width;
		int height;
	private:
		// resource manager
		std::vector<VkBuffer> vkBuffer;
		std::vector<VkDeviceMemory> vkDeviceMemory;
		std::vector<VkSemaphore> vkSemaphore;
		std::vector<VkFence> vkFence;

	public:
		// render manager
		VkRenderPass & get_vkRenderPass();
		VkPipeline & get_vkPipeline();
	public:
		// resource manager
		std::vector<VkBuffer> get_vkBuffer();
		std::vector<VkDeviceMemory> get_vkDeviceMemory();
		std::vector<VkSemaphore>  get_vkSemaphore();
		std::vector<VkFence>  get_vkFence();
	public:
		// window
		GLFWwindow* get_window();
		void set_window(GLFWwindow* win);

		// instance
		VkInstance* get_vkInstance();
		VkAllocationCallbacks* get_vkAllocationCallbacks();

		// surface
		VkSurfaceKHR* get_vkSurface();
		void  set_vkPhysicalDevice(VkPhysicalDevice& physicalDevice);

		// physical device
		VkPhysicalDevice get_vkPhysicalDevice();

		// logical device
		VkDevice* get_vkDevice();

		// swapchain
		VkSwapchainKHR* get_vkSwapchainKHR();

		VkPhysicalDeviceProperties get_vkPhysicalDeviceProperties();
		void set_vkPhysicalDeviceProperties(VkPhysicalDeviceProperties deviceProperties);

		// swapchain imageviews
		std::vector<VkImageView>& get_swapChainImageViews();
		std::vector<VkImage>& get_swapChainImages();
		std::vector<VkFramebuffer>& get_swapChainFramebuffers();
		void resize_swapChainImageViews(int size);
		void clear_swapChainImageViews();

		void set_width(int width);
		void set_height(int height);


		void set_vkExtent2D(VkExtent2D &extent);
		void set_vkSurfaceFormat(VkSurfaceFormatKHR &format);
		VkExtent2D get_vkExtent2D();
		VkSurfaceFormatKHR get_vkSurfaceFormatKHR();

		int get_width();
		int get_height();
	};

}