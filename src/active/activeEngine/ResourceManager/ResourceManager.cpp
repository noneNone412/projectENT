#include"ResourceManager.h"

#ifndef VMA_IMPLEMENTATION
#define VMA_IMPLEMENTATION
#include <vma/vk_mem_alloc.h>

#include "spirv_glsl.hpp"
#include "spirv_reflect.hpp"
#endif


namespace activeEngine {
	ResourceManager::ResourceManager(VulkanVariables* variables) :var(variables) {}
}

// private
namespace activeEngine {

	void ResourceManager::set_vkBuffer(int index, int size)
	{
		VkBufferCreateInfo bufferCreateInfo = {};
		bufferCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferCreateInfo.pNext = nullptr;
		bufferCreateInfo.flags = 0;
		bufferCreateInfo.size = size;
		bufferCreateInfo.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT |     // Specifies how the buffer will be used, can be a bitmask of VkBufferUsageFlagBits
			VK_BUFFER_USAGE_TRANSFER_DST_BIT |
			VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
		bufferCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
		bufferCreateInfo.queueFamilyIndexCount = 0;
		bufferCreateInfo.pQueueFamilyIndices = nullptr;                 // Pointer to an array of queue family indices that will access the buffer (ignored if sharingMode is EXCLUSIVE)

	}
	void ResourceManager::set_vkBufferView()
	{
		VkBufferViewCreateInfo bufferViewCreateInfo = {};
		bufferViewCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;  // Must be VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO
		bufferViewCreateInfo.pNext = nullptr;                                    // Pointer to extension-specific structure (if any)
		bufferViewCreateInfo.flags = 0;                                          // Reserved for future use, should be 0
		//bufferViewCreateInfo.buffer = buffer;                                    // The buffer that the view will be created from (VkBuffer)
		bufferViewCreateInfo.format = VK_FORMAT_R32_SFLOAT;                      // Format of the data in the buffer (e.g., VK_FORMAT_R32_SFLOAT for 32-bit float)
		bufferViewCreateInfo.offset = 0;                                         // Offset in bytes from the start of the buffer (must be aligned to format requirements)
		bufferViewCreateInfo.range = VK_WHOLE_SIZE;                              // Size of the buffer view in bytes, or VK_WHOLE_SIZE to use the rest of the buffer

	}
	void ResourceManager::set_vkFence()
	{
		VkFenceCreateInfo fenceInfo{};
		fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
		fenceInfo.pNext = nullptr;
		fenceInfo.flags = 0; // or VK_FENCE_CREATE_SIGNALED_BIT if you want it to start signaled

	}
	void ResourceManager::set_vkSemaphore() {
		VkSemaphoreCreateInfo semaphoreInfo{};
		semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
		semaphoreInfo.pNext = nullptr;
		semaphoreInfo.flags = 0;

	}

	void ResourceManager::set_vmaAllocator() {
		VmaAllocatorCreateInfo allocatorInfo = {};
		allocatorInfo.physicalDevice = var->get_vkPhysicalDevice();
		allocatorInfo.device = *var->get_vkDevice();
		allocatorInfo.instance = *var->get_vkInstance();
		VkResult result = vmaCreateAllocator(&allocatorInfo, &vmaAllocator);
		if (result != VK_SUCCESS) {
			throw std::runtime_error("Failed to create VMA allocator!");
		}
	}

	std::vector<uint32_t> load_spirv_file(const std::string& filename) {
		// Open the file in binary mode and move the file pointer to the end to get the file size
		std::ifstream file(filename, std::ios::ate | std::ios::binary);

		// Check if the file was opened successfully
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open SPIR-V file: " + filename);
		}

		// Get the file size
		size_t fileSize = static_cast<size_t>(file.tellg());

		// Ensure the file size is a multiple of 4 (since each SPIR-V word is 4 bytes)
		if (fileSize % 4 != 0) {
			throw std::runtime_error("SPIR-V file size is not a multiple of 4: " + filename);
		}
		else {
			std::cout << "returning compiled shader\n";
		}

		// Create a vector of uint32_t with enough space to hold the file content
		std::vector<uint32_t> spirvBinary(fileSize / sizeof(uint32_t));

		// Move back to the beginning of the file to read the contents
		file.seekg(0);

		// Read the file contents into the vector
		file.read(reinterpret_cast<char*>(spirvBinary.data()), fileSize);

		// Close the file
		file.close();

		// Return the SPIR-V binary as a vector of uint32_t
		return spirvBinary;
	}

	std::vector<uint32_t> ResourceManager::load_spirv_file(const std::string& filename)
	{

		// Open the file in binary mode and move the file pointer to the end to get the file size
		std::ifstream file(filename, std::ios::ate | std::ios::binary);

		// Check if the file was opened successfully
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open SPIR-V file: " + filename);
		}

		// Get the file size
		size_t fileSize = static_cast<size_t>(file.tellg());

		// Ensure the file size is a multiple of 4 (since each SPIR-V word is 4 bytes)
		if (fileSize % 4 != 0) {
			throw std::runtime_error("SPIR-V file size is not a multiple of 4: " + filename);
		}
		else {
			std::cout << "returning compiled shader\n";
		}

		// Create a vector of uint32_t with enough space to hold the file content
		std::vector<uint32_t> spirvBinary(fileSize / sizeof(uint32_t));

		// Move back to the beginning of the file to read the contents
		file.seekg(0);

		// Read the file contents into the vector
		file.read(reinterpret_cast<char*>(spirvBinary.data()), fileSize);

		// Close the file
		file.close();

		// Return the SPIR-V binary as a vector of uint32_t
		return spirvBinary;
	}

	void ResourceManager::reflect_spv(const std::string& out_path)
	{
		std::vector<uint32_t> spirv_binary = load_spirv_file(out_path);
		spirv_cross::CompilerGLSL glsl(std::move(spirv_binary));

		spirv_cross::ShaderResources resources = glsl.get_shader_resources();

		// Print all resources found in the SPIR-V code
		std::cout << "Uniform Buffers: \n";
		for (const auto& resource : resources.uniform_buffers) {
			std::cout << "  " << resource.name << " at binding: "
				<< glsl.get_decoration(resource.id, spv::DecorationBinding) << std::endl;
		}

		std::cout << "\nStorage Buffers: \n";
		for (const auto& resource : resources.storage_buffers) {
			std::cout << "  " << resource.name << " at binding: "
				<< glsl.get_decoration(resource.id, spv::DecorationBinding) << std::endl;
		}

		std::cout << "\nSampled Images (Textures): \n";
		for (const auto& resource : resources.sampled_images) {
			std::cout << "  " << resource.name << " at binding: "
				<< glsl.get_decoration(resource.id, spv::DecorationBinding) << std::endl;
		}

		std::cout << "\nStorage Images: \n";
		for (const auto& resource : resources.storage_images) {
			std::cout << "  " << resource.name << " at binding: "
				<< glsl.get_decoration(resource.id, spv::DecorationBinding) << std::endl;
		}

		std::cout << "\nPush Constants: \n";
		for (const auto& resource : resources.push_constant_buffers) {
			std::cout << "  " << resource.name << std::endl;
		}

		std::cout << "\nShader Inputs: \n";
		for (const auto& resource : resources.stage_inputs) {
			std::cout << "  " << resource.name << " at location: "
				<< glsl.get_decoration(resource.id, spv::DecorationLocation) << std::endl;
		}

		std::cout << "\nShader Outputs: \n";
		for (const auto& resource : resources.stage_outputs) {
			std::cout << "  " << resource.name << " at location: "
				<< glsl.get_decoration(resource.id, spv::DecorationLocation) << std::endl;
		}

		std::string glsl_code = glsl.compile();
		std::cout << "\nGenerated GLSL Code:\n" << glsl_code << std::endl;

	}

	void ResourceManager::create_vkDescriptorPool(VkDescriptorPoolSize pool)
	{
		/*
		// Fetch limits related to descriptor sets
		uint32_t maxDescriptorSetUniformBuffers = deviceProperties.limits.maxPerStageDescriptorUniformBuffers;
		uint32_t maxDescriptorSetSamplers = deviceProperties.limits.maxPerStageDescriptorSamplers;
		uint32_t maxDescriptorSetSampledImages = deviceProperties.limits.maxPerStageDescriptorSampledImages;
		uint32_t maxDescriptorSetStorageBuffers = deviceProperties.limits.maxPerStageDescriptorStorageBuffers;
		uint32_t maxDescriptorSetStorageImages = deviceProperties.limits.maxPerStageDescriptorStorageImages;
		uint32_t maxDescriptorSetInputAttachments = deviceProperties.limits.maxPerStageDescriptorInputAttachments;
		uint32_t maxDescriptorSetUniformBuffersDynamic = deviceProperties.limits.maxDescriptorSetUniformBuffersDynamic;
		uint32_t maxDescriptorSetStorageBuffersDynamic = deviceProperties.limits.maxDescriptorSetStorageBuffersDynamic;

		// Print the limits
		std::cout << "Max Per Stage Descriptor Uniform Buffers: " << maxDescriptorSetUniformBuffers << std::endl;
		std::cout << "Max Per Stage Descriptor Samplers: " << maxDescriptorSetSamplers << std::endl;
		std::cout << "Max Per Stage Descriptor Sampled Images: " << maxDescriptorSetSampledImages << std::endl;
		std::cout << "Max Per Stage Descriptor Storage Buffers: " << maxDescriptorSetStorageBuffers << std::endl;
		std::cout << "Max Per Stage Descriptor Storage Images: " << maxDescriptorSetStorageImages << std::endl;
		std::cout << "Max Per Stage Descriptor Input Attachments: " << maxDescriptorSetInputAttachments << std::endl;
		std::cout << "Max Descriptor Set Uniform Buffers Dynamic: " << maxDescriptorSetUniformBuffersDynamic << std::endl;
		std::cout << "Max Descriptor Set Storage Buffers Dynamic: " << maxDescriptorSetStorageBuffersDynamic << std::endl;
		*/
		VkDescriptorPoolCreateFlags flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT | VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT;

		std::vector<VkDescriptorPoolSize> poolSizes = {
	{ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 10 },
	{ VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 10 },
	{ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 5 }
		};


		VkDescriptorPoolCreateInfo poolCreateInfo = {};
		poolCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		poolCreateInfo.poolSizeCount = poolSizes.size();
		poolCreateInfo.pPoolSizes = poolSizes.data();
		poolCreateInfo.maxSets = 5;
		poolCreateInfo.flags = flags;

		VkDescriptorPool descriptorPool;
		VkResult result = vkCreateDescriptorPool(*var->get_vkDevice(), &poolCreateInfo, nullptr, &descriptorPool);
		if (result != VK_SUCCESS) {
			throw std::runtime_error("Failed to create descriptor pool!");
		}
	}


	void ResourceManager::create_vkCommandPool(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags)
	{
		VkCommandPoolCreateInfo poolCreateInfo = {};
		poolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		poolCreateInfo.queueFamilyIndex = queueFamilyIndex;
		poolCreateInfo.flags = flags;
		VkCommandPool commandPool;
		VkResult result = vkCreateCommandPool(*var->get_vkDevice(), &poolCreateInfo, nullptr, &commandPool);
		if (result != VK_SUCCESS) {
			throw std::runtime_error("Failed to create command pool!");
		}
	}

	void  ResourceManager::create_vkBuffer(VkBuffer& buffer, VmaAllocation& allocation, VkBufferUsageFlags flags, VkSharingMode sharingMode, int size) {

		VkBufferCreateInfo bufferInfo{};
		bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferInfo.size = size; // size of the buffer in bytes
		bufferInfo.usage = flags;
		bufferInfo.sharingMode = sharingMode;

		VmaAllocationCreateInfo allocInfo = {};
		allocInfo.usage = VMA_MEMORY_USAGE_GPU_ONLY; // Choose memory usage (e.g., GPU only, CPU visible, etc.)

		if (vmaCreateBuffer(vmaAllocator, &bufferInfo, &allocInfo, &buffer, &allocation, nullptr) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create buffer with VMA!");
		}
		/*
		if (vkCreateBuffer(*var->get_vkDevice(), &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create buffer!");
		}*/
	}

	void ResourceManager::create_vkBufferView(VkBufferView& bufferView, VkBufferViewCreateInfo bufferViewInfo)
	{
		if (vkCreateBufferView(*var->get_vkDevice(), &bufferViewInfo, nullptr, &bufferView) != VK_SUCCESS) {
			throw std::runtime_error("failed to create buffer view!");
		}
	}

	void ResourceManager::create_vkDescriptorSetLayout(VkDescriptorSetLayout& descriptorSetLayout, VkDescriptorSetLayoutCreateInfo layoutInfo)
	{
		if (vkCreateDescriptorSetLayout(*var->get_vkDevice(), &layoutInfo, nullptr, &descriptorSetLayout) != VK_SUCCESS) {
			throw std::runtime_error("failed to create descriptor set layout!");
		}
	}





	void ResourceManager::create_vkImage(VkImage& image, VmaAllocation& allocation, VmaAllocationInfo& allocInfoResult, VkImageCreateInfo imageInfo, VmaAllocationCreateInfo allocInfo)
	{
		if (vmaCreateImage(vmaAllocator, &imageInfo, &allocInfo, &image, &allocation, &allocInfoResult) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create image with VMA");
		}
	}

	void ResourceManager::setup()
	{
		set_vmaAllocator();
	}
	void ResourceManager::create_image_for_sampling()
	{
		VkImage image;
		VmaAllocation allocation;
		VmaAllocationInfo allocInfoResult;

		VkImageCreateInfo imageInfo;
		imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
		imageInfo.imageType = VK_IMAGE_TYPE_2D;
		imageInfo.extent.width = var->get_width();
		imageInfo.extent.height = var->get_height();
		imageInfo.extent.depth = 1;
		imageInfo.mipLevels = 1;
		imageInfo.arrayLayers = 1;
		imageInfo.format = VK_FORMAT_R8G8B8A8_UNORM;
		imageInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
		imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		imageInfo.usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
		imageInfo.samples = VK_SAMPLE_COUNT_1_BIT;
		imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

		VmaAllocationCreateInfo allocInfo;
		allocInfo.usage = VMA_MEMORY_USAGE_GPU_ONLY;

		create_vkImage(image, allocation, allocInfoResult, imageInfo, allocInfo);
	}
}