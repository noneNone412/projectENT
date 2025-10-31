#pragma once
#include "../../activeConstants/constants.h"
#include "../InstructionReader/InstructionReader.h"
#include "../VulkanVariables/VulkanVariables.h"


namespace activeEngine {

	class ResourceManager :private InstructionReader {
	private:
		VulkanVariables* var;
		// VMA
		VmaAllocator vmaAllocator;
	public:
		ResourceManager(VulkanVariables* vulkanVariables);
	private:
		/*
		std::vector<VkBuffer> vkBuffer;
		std::vector<VkDeviceMemory> vkDeviceMemory;
		std::vector<VkSemaphore> vkSemaphore;
		std::vector<VkFence> vkFence;
		std::vector<VkRenderPass> vkRenderPass;
		std::vector<VkPipeline> vkPipeline;
		*/
		void set_vkBuffer(int index, int size);
		void set_vkBufferView();
		void set_vkCommandPool();
		void set_vkComputePipelines();
		void set_vkDescriptorPool();
		void set_vkDescriptorSetLayout();
		void set_vkDescriptorUpdaterTemplater();
		void set_vkEvent();
		void set_vkFence();
		void set_vkFramebuffer();
		void set_vkGraphicPipeline();
		void set_vkImage();
		void set_vkImageView();
		void set_vkPipelineCache();
		void set_vkPipelineLayout();
		void set_vkQueryPool();
		void set_vkRenderPass();
		void set_vkRenderPass2();
		void set_vkSampler();
		void set_vkSamplerYcbcrConversion();
		void set_vkSemaphore();
		void set_vkShaderModule();

		void set_vmaAllocator();

		std::vector<uint32_t> load_spirv_file(const std::string& filename);
		void reflect_spv(const std::string& out_path);

		void create_vkDescriptorPool(VkDescriptorPoolSize pool);

		void create_vkCommandPool(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags);

		void create_vkBuffer(VkBuffer&buffer,VmaAllocation  &allocation,VkBufferUsageFlags flags,VkSharingMode sharingMode,int size);

		void create_vkBufferView(VkBufferView &bufferView,VkBufferViewCreateInfo  bufferViewInfo);

		void create_vkDescriptorSetLayout(VkDescriptorSetLayout &descriptorSetLayout,VkDescriptorSetLayoutCreateInfo layoutInfo);

		void create_vkImage(VkImage &image, VmaAllocation& allocation,
		VmaAllocationInfo &allocInfoResult,VkImageCreateInfo imageInfo, VmaAllocationCreateInfo allocInfo);

	public :
		void setup();
		void create_image_for_sampling();
	};
}