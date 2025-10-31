#pragma once
#include<string>
#include<vulkan/vulkan.h>
#include <vector>
#include <iostream>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include<random>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../external files/json/json.hpp"


#include "../../external files/taskflow/taskflow.hpp"

#include <glslang/SPIRV/GlslangToSpv.h>
#include <vma/vk_mem_alloc.h>
#include <filesystem>





namespace activeConstants {
	class Constants {
	protected:
		const std::string read_location = "D:/temporary/";
		const std::string write_location = "D:/temporary/";

		const std::string f_current_scene = "f_current_scene";
		const std::string f_load_difficulty = "f_load_difficulty";


		/*
		// Vulkan Enumerations
	protected:
		VkAttachmentDescriptionFlagBits stringToVkAttachmentDescriptionFlagBits(const std::string& formatStr);
		VkAttachmentLoadOp stringToVkAttachmentLoadOp(const std::string& formatStr);
		VkBlendFactor stringToVkBlendFactor(const std::string& formatStr);
		VkBlendOp stringToVkBlendOp(const std::string& formatStr);
		VkBlendOverlapEXT stringToVkBlendOverlapEXT(const std::string& formatStr);
		VkBorderColor stringToVkBorderColor(const std::string& formatStr);
		VkBufferCreateFlagBits stringToVkBufferCreateFlagBits(const std::string& formatStr);
		VkBufferUsageFlagBits stringToVkBufferUsageFlagBits(const std::string& formatStr);
		VkBuildAccelerationStructureFlagBitsNV stringToVkBuildAccelerationStructureFlagBitsNV(const std::string& formatStr);
		VkChromaLocation stringToVkChromaLocation(const std::string& formatStr);
		VkCoarseSampleOrderTypeNV stringToVkCoarseSampleOrderTypeNV(const std::string& formatStr);
		VkColorComponentFlagBits stringToVkColorComponentFlagBits(const std::string& formatStr);
		VkColorSpaceKHR stringToVkColorSpaceKHR(const std::string& formatStr);
		VkCommandBufferLevel stringToVkCommandBufferLevel(const std::string& formatStr);
		VkCommandBufferResetFlagBits stringToVkCommandBufferResetFlagBits(const std::string& formatStr);
		VkCommandBufferUsageFlagBits stringToVkCommandBufferUsageFlagBits(const std::string& formatStr);
		VkCommandPoolCreateFlagBits stringToVkCommandPoolCreateFlagBits(const std::string& formatStr);
		VkCommandPoolResetFlagBits stringToVkCommandPoolResetFlagBits(const std::string& formatStr);
		VkCompareOp stringToVkCompareOp(const std::string& formatStr);
		VkComponentSwizzle stringToVkComponentSwizzle(const std::string& formatStr);
		VkComponentTypeNV stringToVkComponentTypeNV(const std::string& formatStr);
		VkCompositeAlphaFlagBitsKHR stringToVkCompositeAlphaFlagBitsKHR(const std::string& formatStr);
		VkConditionalRenderingFlagBitsEXT stringToVkConditionalRenderingFlagBitsEXT(const std::string& formatStr);
		VkConservativeRasterizationModeEXT stringToVkConservativeRasterizationModeEXT(const std::string& formatStr);
		VkCopyAccelerationStructureModeNV stringToVkCopyAccelerationStructureModeNV(const std::string& formatStr);
		VkCoverageModulationModeNV stringToVkCoverageModulationModeNV(const std::string& formatStr);
		VkCoverageReductionModeNV stringToVkCoverageReductionModeNV(const std::string& formatStr);
		VkCullModeFlagBits stringToVkCullModeFlagBits(const std::string& formatStr);
		VkDebugReportFlagBitsEXT stringToVkDebugReportFlagBitsEXT(const std::string& formatStr);
		VkDebugReportObjectTypeEXT stringToVkDebugReportObjectTypeEXT(const std::string& formatStr);
		VkDebugUtilsMessageSeverityFlagBitsEXT stringToVkDebugUtilsMessageSeverityFlagBitsEXT(const std::string& formatStr);
		VkDebugUtilsMessageTypeFlagBitsEXT stringToVkDebugUtilsMessageTypeFlagBitsEXT(const std::string& formatStr);
		VkDependencyFlagBits stringToVkDependencyFlagBits(const std::string& formatStr);
		VkDescriptorBindingFlagBits stringToVkDescriptorBindingFlagBits(const std::string& formatStr);
		VkDescriptorPoolCreateFlagBits stringToVkDescriptorPoolCreateFlagBits(const std::string& formatStr);
		VkDescriptorSetLayoutCreateFlagBits stringToVkDescriptorSetLayoutCreateFlagBits(const std::string& formatStr);
		VkDescriptorType stringToVkDescriptorType(const std::string& formatStr);
		VkDescriptorUpdateTemplateType stringToVkDescriptorUpdateTemplateType(const std::string& formatStr);
		VkDeviceEventTypeEXT stringToVkDeviceEventTypeEXT(const std::string& formatStr);
		VkDeviceGroupPresentModeFlagBitsKHR stringToVkDeviceGroupPresentModeFlagBitsKHR(const std::string& formatStr);
		VkDeviceQueueCreateFlagBits stringToVkDeviceQueueCreateFlagBits(const std::string& formatStr);
		VkDiscardRectangleModeEXT stringToVkDiscardRectangleModeEXT(const std::string& formatStr);
		VkDisplayEventTypeEXT stringToVkDisplayEventTypeEXT(const std::string& formatStr);
		VkDisplayPlaneAlphaFlagBitsKHR stringToVkDisplayPlaneAlphaFlagBitsKHR(const std::string& formatStr);
		VkDisplayPowerStateEXT stringToVkDisplayPowerStateEXT(const std::string& formatStr);
		VkDriverId stringToVkDriverId(const std::string& formatStr);
		VkDynamicState stringToVkDynamicState(const std::string& formatStr);
		VkExternalFenceFeatureFlagBits stringToVkExternalFenceFeatureFlagBits(const std::string& formatStr);
		VkExternalFenceHandleTypeFlagBits stringToVkExternalFenceHandleTypeFlagBits(const std::string& formatStr);
		VkExternalMemoryFeatureFlagBits stringToVkExternalMemoryFeatureFlagBits(const std::string& formatStr);
		VkExternalMemoryFeatureFlagBitsNV stringToVkExternalMemoryFeatureFlagBitsNV(const std::string& formatStr);
		VkExternalMemoryHandleTypeFlagBits stringToVkExternalMemoryHandleTypeFlagBits(const std::string& formatStr);
		VkExternalMemoryHandleTypeFlagBitsNV stringToVkExternalMemoryHandleTypeFlagBitsNV(const std::string& formatStr);
		VkExternalSemaphoreFeatureFlagBits stringToVkExternalSemaphoreFeatureFlagBits(const std::string& formatStr);
		VkExternalSemaphoreHandleTypeFlagBits stringToVkExternalSemaphoreHandleTypeFlagBits(const std::string& formatStr);
		VkFenceCreateFlagBits stringToVkFenceCreateFlagBits(const std::string& formatStr);
		VkFenceImportFlagBits stringToVkFenceImportFlagBits(const std::string& formatStr);
		VkFilter stringToVkFilter(const std::string& formatStr);
		VkFormat stringToVkFormat(const std::string& formatStr);
		VkFormatFeatureFlagBits stringToVkFormatFeatureFlagBits(const std::string& formatStr);
		VkFramebufferCreateFlagBits stringToVkFramebufferCreateFlagBits(const std::string& formatStr);
		VkFrontFace stringToVkFrontFace(const std::string& formatStr);
		VkGeometryFlagBitsNV stringToVkGeometryFlagBitsNV(const std::string& formatStr);
		VkGeometryInstanceFlagBitsNV stringToVkGeometryInstanceFlagBitsNV(const std::string& formatStr);
		VkGeometryTypeNV stringToVkGeometryTypeNV(const std::string& formatStr);
		VkImageAspectFlagBits stringToVkImageAspectFlagBits(const std::string& formatStr);
		VkImageCreateFlagBits stringToVkImageCreateFlagBits(const std::string& formatStr);
		VkImageLayout stringToVkImageLayout(const std::string& formatStr);
		VkImageTiling stringToVkImageTiling(const std::string& formatStr);
		VkImageType stringToVkImageType(const std::string& formatStr);
		VkImageUsageFlagBits stringToVkImageUsageFlagBits(const std::string& formatStr);
		VkImageViewCreateFlagBits stringToVkImageViewCreateFlagBits(const std::string& formatStr);
		VkImageViewType stringToVkImageViewType(const std::string& formatStr);
		VkIndexType stringToVkIndexType(const std::string& formatStr);
		VkInternalAllocationType stringToVkInternalAllocationType(const std::string& formatStr);
		VkLineRasterizationModeEXT stringToVkLineRasterizationModeEXT(const std::string& formatStr);
		VkLogicOp stringToVkLogicOp(const std::string& formatStr);
		VkMemoryAllocateFlagBits stringToVkMemoryAllocateFlagBits(const std::string& formatStr);
		VkMemoryHeapFlagBits stringToVkMemoryHeapFlagBits(const std::string& formatStr);
		VkMemoryOverallocationBehaviorAMD stringToVkMemoryOverallocationBehaviorAMD(const std::string& formatStr);
		VkMemoryPropertyFlagBits stringToVkMemoryPropertyFlagBits(const std::string& formatStr);
		VkObjectType stringToVkObjectType(const std::string& formatStr);
		VkPeerMemoryFeatureFlagBits stringToVkPeerMemoryFeatureFlagBits(const std::string& formatStr);
		VkPerformanceConfigurationTypeINTEL stringToVkPerformanceConfigurationTypeINTEL(const std::string& formatStr);
		VkPerformanceCounterDescriptionFlagBitsKHR stringToVkPerformanceCounterDescriptionFlagBitsKHR(const std::string& formatStr);
		VkPerformanceCounterScopeKHR stringToVkPerformanceCounterScopeKHR(const std::string& formatStr);
		VkPerformanceCounterStorageKHR stringToVkPerformanceCounterStorageKHR(const std::string& formatStr);
		VkPhysicalDeviceType stringToVkPhysicalDeviceType(const std::string& formatStr);
		VkPipelineBindPoint stringToVkPipelineBindPoint(const std::string& formatStr);
		VkPipelineCacheHeaderVersion stringToVkPipelineCacheHeaderVersion(const std::string& formatStr);
		VkPipelineCreateFlagBits stringToVkPipelineCreateFlagBits(const std::string& formatStr);
		VkPipelineCreationFeedbackFlagBitsEXT stringToVkPipelineCreationFeedbackFlagBitsEXT(const std::string& formatStr);
		VkPipelineExecutableStatisticFormatKHR stringToVkPipelineExecutableStatisticFormatKHR(const std::string& formatStr);
		VkPipelineShaderStageCreateFlagBits stringToVkPipelineShaderStageCreateFlagBits(const std::string& formatStr);
		VkPipelineStageFlagBits stringToVkPipelineStageFlagBits(const std::string& formatStr);
		VkPointClippingBehavior stringToVkPointClippingBehavior(const std::string& formatStr);
		VkPolygonMode stringToVkPolygonMode(const std::string& formatStr);
		VkPresentModeKHR stringToVkPresentModeKHR(const std::string& formatStr);
		VkPrimitiveTopology stringToVkPrimitiveTopology(const std::string& formatStr);
		VkQueryControlFlagBits stringToVkQueryControlFlagBits(const std::string& formatStr);
		VkQueryPipelineStatisticFlagBits stringToVkQueryPipelineStatisticFlagBits(const std::string& formatStr);
		VkQueryResultFlagBits stringToVkQueryResultFlagBits(const std::string& formatStr);
		VkQueryType stringToVkQueryType(const std::string& formatStr);
		VkQueueFlagBits stringToVkQueueFlagBits(const std::string& formatStr);
		VkQueueGlobalPriorityEXT stringToVkQueueGlobalPriorityEXT(const std::string& formatStr);
		VkResolveModeFlagBits stringToVkResolveModeFlagBits(const std::string& formatStr);
		VkResult stringToVkResult(const std::string& formatStr);
		VkSampleCountFlagBits stringToVkSampleCountFlagBits(const std::string& formatStr);
		VkSamplerAddressMode stringToVkSamplerAddressMode(const std::string& formatStr);
		VkSamplerCreateFlagBits stringToVkSamplerCreateFlagBits(const std::string& formatStr);
		VkSamplerMipmapMode stringToVkSamplerMipmapMode(const std::string& formatStr);
		VkSamplerReductionMode stringToVkSamplerReductionMode(const std::string& formatStr);
		VkSamplerYcbcrModelConversion stringToVkSamplerYcbcrModelConversion(const std::string& formatStr);
		VkSamplerYcbcrRange stringToVkSamplerYcbcrRange(const std::string& formatStr);
		VkSemaphoreImportFlagBits stringToVkSemaphoreImportFlagBits(const std::string& formatStr);
		VkSemaphoreType stringToVkSemaphoreType(const std::string& formatStr);
		VkSemaphoreWaitFlagBits stringToVkSemaphoreWaitFlagBits(const std::string& formatStr);
		VkShaderFloatControlsIndependence stringToVkShaderFloatControlsIndependence(const std::string& formatStr);
		VkShaderStageFlagBits stringToVkShaderStageFlagBits(const std::string& formatStr);
		VkSharingMode stringToVkSharingMode(const std::string& formatStr);
		VkSparseImageFormatFlagBits stringToVkSparseImageFormatFlagBits(const std::string& formatStr);
		VkSparseMemoryBindFlagBits stringToVkSparseMemoryBindFlagBits(const std::string& formatStr);
		VkStencilFaceFlagBits stringToVkStencilFaceFlagBits(const std::string& formatStr);
		VkStencilOp stringToVkStencilOp(const std::string& formatStr);
		VkSubgroupFeatureFlagBits stringToVkSubgroupFeatureFlagBits(const std::string& formatStr);
		VkSubpassContents stringToVkSubpassContents(const std::string& formatStr);
		VkSubpassDescriptionFlagBits stringToVkSubpassDescriptionFlagBits(const std::string& formatStr);
		VkSurfaceCounterFlagBitsEXT stringToVkSurfaceCounterFlagBitsEXT(const std::string& formatStr);
		VkSurfaceTransformFlagBitsKHR stringToVkSurfaceTransformFlagBitsKHR(const std::string& formatStr);
		VkSwapchainCreateFlagBitsKHR stringToVkSwapchainCreateFlagBitsKHR(const std::string& formatStr);
		VkSystemAllocationScope stringToVkSystemAllocationScope(const std::string& formatStr);
		VkTessellationDomainOrigin stringToVkTessellationDomainOrigin(const std::string& formatStr);
		VkTimeDomainEXT stringToVkTimeDomainEXT(const std::string& formatStr);
		VkToolPurposeFlagBitsEXT stringToVkToolPurposeFlagBitsEXT(const std::string& formatStr);
		VkVertexInputRate stringToVkVertexInputRate(const std::string& formatStr);
		*/
	
	};
}