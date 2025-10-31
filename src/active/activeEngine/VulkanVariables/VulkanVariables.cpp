#include"VulkanVariables.h"


// public functions
namespace activeEngine {
	VkRenderPass & VulkanVariables::get_vkRenderPass()
	{
		return this->vkRenderPass;
	}
	VkPipeline& VulkanVariables::get_vkPipeline()
	{
		return this->vkPipeline;
	}
	// window
	GLFWwindow* VulkanVariables::get_window() {
		return this->window;
	}
	void VulkanVariables::set_window(GLFWwindow* win) {
		this->window = win;
	}
	VkInstance* VulkanVariables::get_vkInstance()
	{
		return &vkInstance;
	}
	VkAllocationCallbacks* VulkanVariables::get_vkAllocationCallbacks()
	{
		return &vkAllocationCallbacks;
	}
	VkSurfaceKHR* VulkanVariables::get_vkSurface()
	{
		return &vkSurfaceKHR;
	}
	VkPhysicalDevice VulkanVariables::get_vkPhysicalDevice()
	{
		return vkPhysicalDevice;
	}
	VkDevice* VulkanVariables::get_vkDevice()
	{
		return &vkDevice;
	}
	VkSwapchainKHR* VulkanVariables::get_vkSwapchainKHR()
	{
		return &vkSwapchainKHR;
	}
	VkPhysicalDeviceProperties VulkanVariables::get_vkPhysicalDeviceProperties()
	{
		return vkPhysicalDeviceProperties;
	}
	void VulkanVariables::set_vkPhysicalDeviceProperties(VkPhysicalDeviceProperties deviceProperties)
	{
		this->vkPhysicalDeviceProperties = deviceProperties;
	}
	std::vector<VkImageView>& VulkanVariables::get_swapChainImageViews()
	{
		return swapChainImageViews;
	}
	std::vector<VkImage>& VulkanVariables::get_swapChainImages()
	{
		return this->swapChainImages;
	}
	std::vector<VkFramebuffer>& VulkanVariables::get_swapChainFramebuffers()
	{
		return this->swapChainFrameBuffers;
	}
	void VulkanVariables::resize_swapChainImageViews(int size)
	{
		swapChainImageViews.resize(size);
	}
	void VulkanVariables::clear_swapChainImageViews()
	{
		swapChainImageViews.clear();
	}
	void VulkanVariables::set_vkPhysicalDevice(VkPhysicalDevice& physicalDevice)
	{
		this->vkPhysicalDevice = physicalDevice;
	}

	void VulkanVariables::set_width(int width) {
		this->width = width;
	}
	void VulkanVariables::set_height(int height) {
		this->height = height;
	}
	void VulkanVariables::set_vkExtent2D(VkExtent2D &extent)
	{
		this->frameExtent = extent;
	}
	void VulkanVariables::set_vkSurfaceFormat(VkSurfaceFormatKHR& format)
	{
		this->surfaceFormat = format;
	}
	VkExtent2D VulkanVariables::get_vkExtent2D()
	{
		return frameExtent;
	}

	VkSurfaceFormatKHR VulkanVariables::get_vkSurfaceFormatKHR()
	{
		return this->surfaceFormat;
	}

	int VulkanVariables::get_width() {
		return width;
	}
	int VulkanVariables::get_height() {
		return height;
	}
}