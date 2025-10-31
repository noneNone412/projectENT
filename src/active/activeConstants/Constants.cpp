#include "constants.h"

namespace activeConstants {


	/*
	VkAttachmentDescriptionFlagBits Constants::stringToVkAttachmentDescriptionFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkAttachmentDescriptionFlagBits> formatMap = {
			{"VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT ", VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT },
			{"VK_ATTACHMENT_DESCRIPTION_FLAG_BITS_MAX_ENUM ", VK_ATTACHMENT_DESCRIPTION_FLAG_BITS_MAX_ENUM },
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkAttachmentDescriptionFlagBits string: " + formatStr);
		}
	}

	VkAttachmentLoadOp Constants::stringToVkAttachmentLoadOp(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkAttachmentLoadOp> formatMap = {
			{"VK_ATTACHMENT_LOAD_OP_LOAD ",VK_ATTACHMENT_LOAD_OP_LOAD },
			{"VK_ATTACHMENT_LOAD_OP_CLEAR  ",VK_ATTACHMENT_LOAD_OP_CLEAR  },
			{"VK_ATTACHMENT_LOAD_OP_DONT_CARE  ",VK_ATTACHMENT_LOAD_OP_DONT_CARE  },
			{"VK_ATTACHMENT_LOAD_OP_MAX_ENUM  ",VK_ATTACHMENT_LOAD_OP_MAX_ENUM  },
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkAttachmentLoadOp string: " + formatStr);
		}
	}

	VkBlendFactor Constants::stringToVkBlendFactor(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkBlendFactor> formatMap = {
			{"VK_BLEND_FACTOR_ZERO",VK_BLEND_FACTOR_ZERO},
			{"VK_BLEND_FACTOR_ONE",VK_BLEND_FACTOR_ONE},
			{"VK_BLEND_FACTOR_SRC_COLOR",VK_BLEND_FACTOR_SRC_COLOR},
			{"VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR",VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR},
			{"VK_BLEND_FACTOR_DST_COLOR",VK_BLEND_FACTOR_DST_COLOR},
			{"VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR",VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR},
			{"VK_BLEND_FACTOR_SRC_ALPHA",VK_BLEND_FACTOR_SRC_ALPHA},
			{"VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA",VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA},
			{"VK_BLEND_FACTOR_DST_ALPHA",VK_BLEND_FACTOR_DST_ALPHA},
			{"VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA",VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA},
			{"VK_BLEND_FACTOR_CONSTANT_COLOR",VK_BLEND_FACTOR_CONSTANT_COLOR},
			{"VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR",VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR},
			{"VK_BLEND_FACTOR_CONSTANT_ALPHA",VK_BLEND_FACTOR_CONSTANT_ALPHA},
			{"VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA",VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA},
			{"VK_BLEND_FACTOR_SRC_ALPHA_SATURATE",VK_BLEND_FACTOR_SRC_ALPHA_SATURATE},
			{"VK_BLEND_FACTOR_SRC1_COLOR",VK_BLEND_FACTOR_SRC1_COLOR},
			{"VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR",VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR},
			{"VK_BLEND_FACTOR_SRC1_ALPHA",VK_BLEND_FACTOR_SRC1_ALPHA},
			{"VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA",VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA},
			{"VK_BLEND_FACTOR_MAX_ENUM",VK_BLEND_FACTOR_MAX_ENUM},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkBlendFactor string: " + formatStr);
		}
	}

	VkBlendOp Constants::stringToVkBlendOp(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkBlendOp> formatMap = {
			{"VK_BLEND_OP_ADD",VK_BLEND_OP_ADD},
			{"VK_BLEND_OP_SUBTRACT ",VK_BLEND_OP_SUBTRACT },
	{"VK_BLEND_OP_REVERSE_SUBTRACT", VK_BLEND_OP_REVERSE_SUBTRACT},
	{"VK_BLEND_OP_MIN", VK_BLEND_OP_MIN},
	{"VK_BLEND_OP_MAX", VK_BLEND_OP_MAX},
	{"VK_BLEND_OP_ZERO_EXT", VK_BLEND_OP_ZERO_EXT},
	{"VK_BLEND_OP_SRC_EXT", VK_BLEND_OP_SRC_EXT},
	{"VK_BLEND_OP_DST_EXT", VK_BLEND_OP_DST_EXT},
	{"VK_BLEND_OP_SRC_OVER_EXT", VK_BLEND_OP_SRC_OVER_EXT},
	{"VK_BLEND_OP_DST_OVER_EXT", VK_BLEND_OP_DST_OVER_EXT},
	{"VK_BLEND_OP_SRC_IN_EXT", VK_BLEND_OP_SRC_IN_EXT},
	{"VK_BLEND_OP_DST_IN_EXT", VK_BLEND_OP_DST_IN_EXT},
	{"VK_BLEND_OP_SRC_OUT_EXT", VK_BLEND_OP_SRC_OUT_EXT},
	{"VK_BLEND_OP_DST_OUT_EXT", VK_BLEND_OP_DST_OUT_EXT},
	{"VK_BLEND_OP_SRC_ATOP_EXT", VK_BLEND_OP_SRC_ATOP_EXT},
	{"VK_BLEND_OP_DST_ATOP_EXT", VK_BLEND_OP_DST_ATOP_EXT},
	{"VK_BLEND_OP_XOR_EXT", VK_BLEND_OP_XOR_EXT},
	{"VK_BLEND_OP_MULTIPLY_EXT", VK_BLEND_OP_MULTIPLY_EXT},
	{"VK_BLEND_OP_SCREEN_EXT", VK_BLEND_OP_SCREEN_EXT},
	{"VK_BLEND_OP_OVERLAY_EXT", VK_BLEND_OP_OVERLAY_EXT},
	{"VK_BLEND_OP_DARKEN_EXT", VK_BLEND_OP_DARKEN_EXT},
	{"VK_BLEND_OP_LIGHTEN_EXT", VK_BLEND_OP_LIGHTEN_EXT},
	{"VK_BLEND_OP_COLORDODGE_EXT", VK_BLEND_OP_COLORDODGE_EXT},
	{"VK_BLEND_OP_COLORBURN_EXT", VK_BLEND_OP_COLORBURN_EXT},
	{"VK_BLEND_OP_HARDLIGHT_EXT", VK_BLEND_OP_HARDLIGHT_EXT},
	{"VK_BLEND_OP_SOFTLIGHT_EXT", VK_BLEND_OP_SOFTLIGHT_EXT},
	{"VK_BLEND_OP_DIFFERENCE_EXT", VK_BLEND_OP_DIFFERENCE_EXT},
	{"VK_BLEND_OP_EXCLUSION_EXT", VK_BLEND_OP_EXCLUSION_EXT},
	{"VK_BLEND_OP_INVERT_EXT", VK_BLEND_OP_INVERT_EXT},
	{"VK_BLEND_OP_INVERT_RGB_EXT", VK_BLEND_OP_INVERT_RGB_EXT},
	{"VK_BLEND_OP_LINEARDODGE_EXT", VK_BLEND_OP_LINEARDODGE_EXT},
	{"VK_BLEND_OP_LINEARBURN_EXT", VK_BLEND_OP_LINEARBURN_EXT},
	{"VK_BLEND_OP_VIVIDLIGHT_EXT", VK_BLEND_OP_VIVIDLIGHT_EXT},
	{"VK_BLEND_OP_LINEARLIGHT_EXT", VK_BLEND_OP_LINEARLIGHT_EXT},
	{"VK_BLEND_OP_PINLIGHT_EXT", VK_BLEND_OP_PINLIGHT_EXT},
	{"VK_BLEND_OP_HARDMIX_EXT", VK_BLEND_OP_HARDMIX_EXT},
	{"VK_BLEND_OP_HSL_HUE_EXT", VK_BLEND_OP_HSL_HUE_EXT},
	{"VK_BLEND_OP_HSL_SATURATION_EXT", VK_BLEND_OP_HSL_SATURATION_EXT},
	{"VK_BLEND_OP_HSL_COLOR_EXT", VK_BLEND_OP_HSL_COLOR_EXT},
	{"VK_BLEND_OP_HSL_LUMINOSITY_EXT", VK_BLEND_OP_HSL_LUMINOSITY_EXT},
	{"VK_BLEND_OP_PLUS_EXT", VK_BLEND_OP_PLUS_EXT},
	{"VK_BLEND_OP_PLUS_CLAMPED_EXT", VK_BLEND_OP_PLUS_CLAMPED_EXT},
	{"VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT", VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT},
	{"VK_BLEND_OP_PLUS_DARKER_EXT", VK_BLEND_OP_PLUS_DARKER_EXT},
	{"VK_BLEND_OP_MINUS_EXT", VK_BLEND_OP_MINUS_EXT},
	{"VK_BLEND_OP_MINUS_CLAMPED_EXT", VK_BLEND_OP_MINUS_CLAMPED_EXT},
	{"VK_BLEND_OP_CONTRAST_EXT", VK_BLEND_OP_CONTRAST_EXT},
	{"VK_BLEND_OP_INVERT_OVG_EXT", VK_BLEND_OP_INVERT_OVG_EXT},
	{"VK_BLEND_OP_RED_EXT", VK_BLEND_OP_RED_EXT},
	{"VK_BLEND_OP_GREEN_EXT", VK_BLEND_OP_GREEN_EXT},
	{"VK_BLEND_OP_BLUE_EXT", VK_BLEND_OP_BLUE_EXT},
	{"VK_BLEND_OP_MAX_ENUM", VK_BLEND_OP_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkBlendOp string: " + formatStr);
		}
	}

	VkBlendOverlapEXT Constants::stringToVkBlendOverlapEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkBlendOverlapEXT> formatMap = {
			 {"VK_BLEND_OVERLAP_UNCORRELATED_EXT", VK_BLEND_OVERLAP_UNCORRELATED_EXT},
	{"VK_BLEND_OVERLAP_DISJOINT_EXT", VK_BLEND_OVERLAP_DISJOINT_EXT},
	{"VK_BLEND_OVERLAP_CONJOINT_EXT", VK_BLEND_OVERLAP_CONJOINT_EXT},
	{"VK_BLEND_OVERLAP_MAX_ENUM_EXT", VK_BLEND_OVERLAP_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkBlendOverlapEXT string: " + formatStr);
		}
	}

	VkBorderColor Constants::stringToVkBorderColor(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkBorderColor> formatMap = {
			 {"VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK", VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK},
	{"VK_BORDER_COLOR_INT_TRANSPARENT_BLACK", VK_BORDER_COLOR_INT_TRANSPARENT_BLACK},
	{"VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK", VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK},
	{"VK_BORDER_COLOR_INT_OPAQUE_BLACK", VK_BORDER_COLOR_INT_OPAQUE_BLACK},
	{"VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE", VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE},
	{"VK_BORDER_COLOR_INT_OPAQUE_WHITE", VK_BORDER_COLOR_INT_OPAQUE_WHITE},
	{"VK_BORDER_COLOR_MAX_ENUM", VK_BORDER_COLOR_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkBorderColor string: " + formatStr);
		}
	}

	VkBufferCreateFlagBits Constants::stringToVkBufferCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkBufferCreateFlagBits> formatMap = {
			 {"VK_BUFFER_CREATE_SPARSE_BINDING_BIT", VK_BUFFER_CREATE_SPARSE_BINDING_BIT},
	{"VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT", VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT},
	{"VK_BUFFER_CREATE_SPARSE_ALIASED_BIT", VK_BUFFER_CREATE_SPARSE_ALIASED_BIT},
	{"VK_BUFFER_CREATE_PROTECTED_BIT", VK_BUFFER_CREATE_PROTECTED_BIT},
	{"VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT", VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT},
	{"VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT", VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT},
	{"VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR", VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR},
	{"VK_BUFFER_CREATE_FLAG_BITS_MAX_ENUM", VK_BUFFER_CREATE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkBufferCreateFlagBits string: " + formatStr);
		}
	}

	VkBufferUsageFlagBits Constants::stringToVkBufferUsageFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkBufferUsageFlagBits> formatMap = {
			{"VK_BUFFER_USAGE_TRANSFER_SRC_BIT", VK_BUFFER_USAGE_TRANSFER_SRC_BIT},
	{"VK_BUFFER_USAGE_TRANSFER_DST_BIT", VK_BUFFER_USAGE_TRANSFER_DST_BIT},
	{"VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT", VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT},
	{"VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT", VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT},
	{"VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT", VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT},
	{"VK_BUFFER_USAGE_STORAGE_BUFFER_BIT", VK_BUFFER_USAGE_STORAGE_BUFFER_BIT},
	{"VK_BUFFER_USAGE_INDEX_BUFFER_BIT", VK_BUFFER_USAGE_INDEX_BUFFER_BIT},
	{"VK_BUFFER_USAGE_VERTEX_BUFFER_BIT", VK_BUFFER_USAGE_VERTEX_BUFFER_BIT},
	{"VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT", VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT},
	{"VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT", VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT},
	{"VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT", VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT},
	{"VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT", VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT},
	{"VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT", VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT},
	{"VK_BUFFER_USAGE_RAY_TRACING_BIT_NV", VK_BUFFER_USAGE_RAY_TRACING_BIT_NV},
	{"VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_EXT", VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_EXT},
	{"VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_KHR", VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_KHR},
	{"VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM", VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkBufferUsageFlagBits string: " + formatStr);
		}
	}

	VkBuildAccelerationStructureFlagBitsNV Constants::stringToVkBuildAccelerationStructureFlagBitsNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkBuildAccelerationStructureFlagBitsNV> formatMap = {

			{"VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_NV", VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_NV},
	{"VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_NV", VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_NV},
	{"VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_NV", VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_NV},
	{"VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_NV", VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_NV},
	{"VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_NV", VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_NV}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkBuildAccelerationStructureFlagBitsNV string: " + formatStr);
		}
	}

	VkChromaLocation Constants::stringToVkChromaLocation(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkChromaLocation> formatMap = {
			 {"VK_CHROMA_LOCATION_COSITED_EVEN", VK_CHROMA_LOCATION_COSITED_EVEN},
	{"VK_CHROMA_LOCATION_MIDPOINT", VK_CHROMA_LOCATION_MIDPOINT},
	{"VK_CHROMA_LOCATION_COSITED_EVEN_KHR", VK_CHROMA_LOCATION_COSITED_EVEN_KHR},
	{"VK_CHROMA_LOCATION_MIDPOINT_KHR", VK_CHROMA_LOCATION_MIDPOINT_KHR},
	{"VK_CHROMA_LOCATION_MAX_ENUM", VK_CHROMA_LOCATION_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkChromaLocation string: " + formatStr);
		}
	}

	VkCoarseSampleOrderTypeNV Constants::stringToVkCoarseSampleOrderTypeNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCoarseSampleOrderTypeNV> formatMap = {
			  {"VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV", VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV},
	{"VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV", VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV},
	{"VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV", VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV},
	{"VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV", VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV},
	{"VK_COARSE_SAMPLE_ORDER_TYPE_MAX_ENUM_NV", VK_COARSE_SAMPLE_ORDER_TYPE_MAX_ENUM_NV}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCoarseSampleOrderTypeNV string: " + formatStr);
		}
	}

	VkColorComponentFlagBits Constants::stringToVkColorComponentFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkColorComponentFlagBits> formatMap = {
			 {"VK_COLOR_COMPONENT_R_BIT", VK_COLOR_COMPONENT_R_BIT},
	{"VK_COLOR_COMPONENT_G_BIT", VK_COLOR_COMPONENT_G_BIT},
	{"VK_COLOR_COMPONENT_B_BIT", VK_COLOR_COMPONENT_B_BIT},
	{"VK_COLOR_COMPONENT_A_BIT", VK_COLOR_COMPONENT_A_BIT},
	{"VK_COLOR_COMPONENT_FLAG_BITS_MAX_ENUM", VK_COLOR_COMPONENT_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkColorComponentFlagBits string: " + formatStr);
		}
	}

	VkColorSpaceKHR Constants::stringToVkColorSpaceKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkColorSpaceKHR> formatMap = {
			 {"VK_COLOR_SPACE_SRGB_NONLINEAR_KHR", VK_COLOR_SPACE_SRGB_NONLINEAR_KHR},
	{"VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT", VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT},
	{"VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT", VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT},
	{"VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT", VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT},
	{"VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT", VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT},
	{"VK_COLOR_SPACE_BT709_LINEAR_EXT", VK_COLOR_SPACE_BT709_LINEAR_EXT},
	{"VK_COLOR_SPACE_BT709_NONLINEAR_EXT", VK_COLOR_SPACE_BT709_NONLINEAR_EXT},
	{"VK_COLOR_SPACE_BT2020_LINEAR_EXT", VK_COLOR_SPACE_BT2020_LINEAR_EXT},
	{"VK_COLOR_SPACE_HDR10_ST2084_EXT", VK_COLOR_SPACE_HDR10_ST2084_EXT},
	{"VK_COLOR_SPACE_DOLBYVISION_EXT", VK_COLOR_SPACE_DOLBYVISION_EXT},
	{"VK_COLOR_SPACE_HDR10_HLG_EXT", VK_COLOR_SPACE_HDR10_HLG_EXT},
	{"VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT", VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT},
	{"VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT", VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT},
	{"VK_COLOR_SPACE_PASS_THROUGH_EXT", VK_COLOR_SPACE_PASS_THROUGH_EXT},
	{"VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT", VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT},
	{"VK_COLOR_SPACE_DISPLAY_NATIVE_AMD", VK_COLOR_SPACE_DISPLAY_NATIVE_AMD},
	{"VK_COLORSPACE_SRGB_NONLINEAR_KHR", VK_COLORSPACE_SRGB_NONLINEAR_KHR},
	{"VK_COLOR_SPACE_DCI_P3_LINEAR_EXT", VK_COLOR_SPACE_DCI_P3_LINEAR_EXT},
	{"VK_COLOR_SPACE_MAX_ENUM_KHR", VK_COLOR_SPACE_MAX_ENUM_KHR}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkColorSpaceKHR string: " + formatStr);
		}
	}

	VkCommandBufferLevel Constants::stringToVkCommandBufferLevel(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCommandBufferLevel> formatMap = { {"VK_COMMAND_BUFFER_LEVEL_PRIMARY", VK_COMMAND_BUFFER_LEVEL_PRIMARY},
	{"VK_COMMAND_BUFFER_LEVEL_SECONDARY", VK_COMMAND_BUFFER_LEVEL_SECONDARY},
	{"VK_COMMAND_BUFFER_LEVEL_MAX_ENUM", VK_COMMAND_BUFFER_LEVEL_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCommandBufferLevel string: " + formatStr);
		}
	}

	VkCommandBufferResetFlagBits Constants::stringToVkCommandBufferResetFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCommandBufferResetFlagBits> formatMap = {
			   {"VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT", VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT},
	{"VK_COMMAND_BUFFER_RESET_FLAG_BITS_MAX_ENUM", VK_COMMAND_BUFFER_RESET_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCommandBufferResetFlagBits string: " + formatStr);
		}
	}

	VkCommandBufferUsageFlagBits Constants::stringToVkCommandBufferUsageFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCommandBufferUsageFlagBits> formatMap = { {"VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT", VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT},
	{"VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT", VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT},
	{"VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT", VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT},
	{"VK_COMMAND_BUFFER_USAGE_FLAG_BITS_MAX_ENUM", VK_COMMAND_BUFFER_USAGE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCommandBufferUsageFlagBits string: " + formatStr);
		}
	}

	VkCommandPoolCreateFlagBits Constants::stringToVkCommandPoolCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCommandPoolCreateFlagBits> formatMap = {
 {"VK_COMMAND_POOL_CREATE_TRANSIENT_BIT", VK_COMMAND_POOL_CREATE_TRANSIENT_BIT},
	{"VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT", VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT},
	{"VK_COMMAND_POOL_CREATE_PROTECTED_BIT", VK_COMMAND_POOL_CREATE_PROTECTED_BIT},
	{"VK_COMMAND_POOL_CREATE_FLAG_BITS_MAX_ENUM", VK_COMMAND_POOL_CREATE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCommandPoolCreateFlagBits string: " + formatStr);
		}
	}

	VkCommandPoolResetFlagBits Constants::stringToVkCommandPoolResetFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCommandPoolResetFlagBits> formatMap = { {"VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT", VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT},
	{"VK_COMMAND_POOL_RESET_FLAG_BITS_MAX_ENUM", VK_COMMAND_POOL_RESET_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCommandPoolResetFlagBits string: " + formatStr);
		}
	}

	VkCompareOp Constants::stringToVkCompareOp(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCompareOp> formatMap = { {"VK_COMPARE_OP_NEVER", VK_COMPARE_OP_NEVER},
	{"VK_COMPARE_OP_LESS", VK_COMPARE_OP_LESS},
	{"VK_COMPARE_OP_EQUAL", VK_COMPARE_OP_EQUAL},
	{"VK_COMPARE_OP_LESS_OR_EQUAL", VK_COMPARE_OP_LESS_OR_EQUAL},
	{"VK_COMPARE_OP_GREATER", VK_COMPARE_OP_GREATER},
	{"VK_COMPARE_OP_NOT_EQUAL", VK_COMPARE_OP_NOT_EQUAL},
	{"VK_COMPARE_OP_GREATER_OR_EQUAL", VK_COMPARE_OP_GREATER_OR_EQUAL},
	{"VK_COMPARE_OP_ALWAYS", VK_COMPARE_OP_ALWAYS},
	{"VK_COMPARE_OP_MAX_ENUM", VK_COMPARE_OP_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCompareOp string: " + formatStr);
		}
	}

	VkComponentSwizzle Constants::stringToVkComponentSwizzle(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkComponentSwizzle> formatMap = {
				{"VK_COMPONENT_SWIZZLE_IDENTITY", VK_COMPONENT_SWIZZLE_IDENTITY},
	{"VK_COMPONENT_SWIZZLE_ZERO", VK_COMPONENT_SWIZZLE_ZERO},
	{"VK_COMPONENT_SWIZZLE_ONE", VK_COMPONENT_SWIZZLE_ONE},
	{"VK_COMPONENT_SWIZZLE_R", VK_COMPONENT_SWIZZLE_R},
	{"VK_COMPONENT_SWIZZLE_G", VK_COMPONENT_SWIZZLE_G},
	{"VK_COMPONENT_SWIZZLE_B", VK_COMPONENT_SWIZZLE_B},
	{"VK_COMPONENT_SWIZZLE_A", VK_COMPONENT_SWIZZLE_A},
	{"VK_COMPONENT_SWIZZLE_MAX_ENUM", VK_COMPONENT_SWIZZLE_MAX_ENUM} };
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkComponentSwizzle string: " + formatStr);
		}
	}

	VkComponentTypeNV Constants::stringToVkComponentTypeNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkComponentTypeNV> formatMap = { {"VK_COMPONENT_TYPE_FLOAT16_NV", VK_COMPONENT_TYPE_FLOAT16_NV},
	{"VK_COMPONENT_TYPE_FLOAT32_NV", VK_COMPONENT_TYPE_FLOAT32_NV},
	{"VK_COMPONENT_TYPE_FLOAT64_NV", VK_COMPONENT_TYPE_FLOAT64_NV},
	{"VK_COMPONENT_TYPE_SINT8_NV", VK_COMPONENT_TYPE_SINT8_NV},
	{"VK_COMPONENT_TYPE_SINT16_NV", VK_COMPONENT_TYPE_SINT16_NV},
	{"VK_COMPONENT_TYPE_SINT32_NV", VK_COMPONENT_TYPE_SINT32_NV},
	{"VK_COMPONENT_TYPE_SINT64_NV", VK_COMPONENT_TYPE_SINT64_NV},
	{"VK_COMPONENT_TYPE_UINT8_NV", VK_COMPONENT_TYPE_UINT8_NV},
	{"VK_COMPONENT_TYPE_UINT16_NV", VK_COMPONENT_TYPE_UINT16_NV},
	{"VK_COMPONENT_TYPE_UINT32_NV", VK_COMPONENT_TYPE_UINT32_NV},
	{"VK_COMPONENT_TYPE_UINT64_NV", VK_COMPONENT_TYPE_UINT64_NV}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkComponentTypeNV string: " + formatStr);
		}
	}

	VkCompositeAlphaFlagBitsKHR Constants::stringToVkCompositeAlphaFlagBitsKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCompositeAlphaFlagBitsKHR> formatMap = { {"VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR", VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR},
	{"VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR", VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR},
	{"VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR", VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR},
	{"VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR", VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR},
	{"VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR", VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCompositeAlphaFlagBitsKHR string: " + formatStr);
		}
	}

	VkConditionalRenderingFlagBitsEXT Constants::stringToVkConditionalRenderingFlagBitsEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkConditionalRenderingFlagBitsEXT> formatMap = { {"VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT", VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT},
	{"VK_CONDITIONAL_RENDERING_FLAG_BITS_MAX_ENUM_EXT", VK_CONDITIONAL_RENDERING_FLAG_BITS_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkConditionalRenderingFlagBitsEXT string: " + formatStr);
		}
	}

	VkConservativeRasterizationModeEXT Constants::stringToVkConservativeRasterizationModeEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkConservativeRasterizationModeEXT> formatMap = { {"VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT", VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT},
	{"VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT", VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT},
	{"VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT", VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT},
	{"VK_CONSERVATIVE_RASTERIZATION_MODE_MAX_ENUM_EXT", VK_CONSERVATIVE_RASTERIZATION_MODE_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkConservativeRasterizationModeEXT string: " + formatStr);
		}
	}

	VkCopyAccelerationStructureModeNV Constants::stringToVkCopyAccelerationStructureModeNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCopyAccelerationStructureModeNV> formatMap = { {"VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_NV", VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_NV},
	{"VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_NV", VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_NV}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCopyAccelerationStructureModeNV string: " + formatStr);
		}
	}

	VkCoverageModulationModeNV Constants::stringToVkCoverageModulationModeNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCoverageModulationModeNV> formatMap = { {"VK_COVERAGE_MODULATION_MODE_NONE_NV", VK_COVERAGE_MODULATION_MODE_NONE_NV},
	{"VK_COVERAGE_MODULATION_MODE_RGB_NV", VK_COVERAGE_MODULATION_MODE_RGB_NV},
	{"VK_COVERAGE_MODULATION_MODE_ALPHA_NV", VK_COVERAGE_MODULATION_MODE_ALPHA_NV},
	{"VK_COVERAGE_MODULATION_MODE_RGBA_NV", VK_COVERAGE_MODULATION_MODE_RGBA_NV},
	{"VK_COVERAGE_MODULATION_MODE_MAX_ENUM_NV", VK_COVERAGE_MODULATION_MODE_MAX_ENUM_NV}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCoverageModulationModeNV string: " + formatStr);
		}
	}

	VkCoverageReductionModeNV Constants::stringToVkCoverageReductionModeNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCoverageReductionModeNV> formatMap = { {"VK_COVERAGE_REDUCTION_MODE_MERGE_NV", VK_COVERAGE_REDUCTION_MODE_MERGE_NV},
	{"VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV", VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV},
	{"VK_COVERAGE_REDUCTION_MODE_MAX_ENUM_NV", VK_COVERAGE_REDUCTION_MODE_MAX_ENUM_NV}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCoverageReductionModeNV string: " + formatStr);
		}
	}

	VkCullModeFlagBits Constants::stringToVkCullModeFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkCullModeFlagBits> formatMap = { {"VK_CULL_MODE_NONE", VK_CULL_MODE_NONE},
	{"VK_CULL_MODE_FRONT_BIT", VK_CULL_MODE_FRONT_BIT},
	{"VK_CULL_MODE_BACK_BIT", VK_CULL_MODE_BACK_BIT},
	{"VK_CULL_MODE_FRONT_AND_BACK", VK_CULL_MODE_FRONT_AND_BACK},
	{"VK_CULL_MODE_FLAG_BITS_MAX_ENUM", VK_CULL_MODE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkCullModeFlagBits string: " + formatStr);
		}
	}

	VkDebugReportFlagBitsEXT Constants::stringToVkDebugReportFlagBitsEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDebugReportFlagBitsEXT> formatMap = { {"VK_DEBUG_REPORT_INFORMATION_BIT_EXT", VK_DEBUG_REPORT_INFORMATION_BIT_EXT},
	{"VK_DEBUG_REPORT_WARNING_BIT_EXT", VK_DEBUG_REPORT_WARNING_BIT_EXT},
	{"VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT", VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT},
	{"VK_DEBUG_REPORT_ERROR_BIT_EXT", VK_DEBUG_REPORT_ERROR_BIT_EXT},
	{"VK_DEBUG_REPORT_DEBUG_BIT_EXT", VK_DEBUG_REPORT_DEBUG_BIT_EXT},
	{"VK_DEBUG_REPORT_FLAG_BITS_MAX_ENUM_EXT", VK_DEBUG_REPORT_FLAG_BITS_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDebugReportFlagBitsEXT string: " + formatStr);
		}
	}


	VkDebugReportObjectTypeEXT Constants::stringToVkDebugReportObjectTypeEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDebugReportObjectTypeEXT> formatMap = { {"VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR_EXT},
	{"VK_DEBUG_REPORT_OBJECT_TYPE_MAX_ENUM_EXT", VK_DEBUG_REPORT_OBJECT_TYPE_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDebugReportObjectTypeEXT string: " + formatStr);
		}
	}

	VkDebugUtilsMessageSeverityFlagBitsEXT Constants::stringToVkDebugUtilsMessageSeverityFlagBitsEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDebugUtilsMessageSeverityFlagBitsEXT> formatMap = { {"VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT", VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT},
	{"VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT", VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT},
	{"VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT", VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT},
	{"VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT", VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT},
	{"VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT", VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDebugUtilsMessageSeverityFlagBitsEXT string: " + formatStr);
		}
	}

	VkDebugUtilsMessageTypeFlagBitsEXT Constants::stringToVkDebugUtilsMessageTypeFlagBitsEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDebugUtilsMessageTypeFlagBitsEXT> formatMap = { {"VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT", VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT},
	{"VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT", VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT},
	{"VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT", VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT},
	{"VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT", VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDebugUtilsMessageTypeFlagBitsEXT string: " + formatStr);
		}
	}

	VkDependencyFlagBits Constants::stringToVkDependencyFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDependencyFlagBits> formatMap = { {"VK_DEPENDENCY_BY_REGION_BIT", VK_DEPENDENCY_BY_REGION_BIT},
	{"VK_DEPENDENCY_VIEW_LOCAL_BIT", VK_DEPENDENCY_VIEW_LOCAL_BIT},
	{"VK_DEPENDENCY_DEVICE_GROUP_BIT", VK_DEPENDENCY_DEVICE_GROUP_BIT},
	{"VK_DEPENDENCY_VIEW_LOCAL_BIT_KHR", VK_DEPENDENCY_VIEW_LOCAL_BIT_KHR},
	{"VK_DEPENDENCY_DEVICE_GROUP_BIT_KHR", VK_DEPENDENCY_DEVICE_GROUP_BIT_KHR},
	{"VK_DEPENDENCY_FLAG_BITS_MAX_ENUM", VK_DEPENDENCY_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDependencyFlagBits string: " + formatStr);
		}
	}

	VkDescriptorBindingFlagBits Constants::stringToVkDescriptorBindingFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDescriptorBindingFlagBits> formatMap = {
			{"VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT", VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT},
	{"VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT", VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT},
	{"VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT", VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT},
	{"VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT", VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT},
	{"VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT_EXT", VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT_EXT},
	{"VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT_EXT", VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT_EXT},
	{"VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT_EXT", VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT_EXT},
	{"VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT_EXT", VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT_EXT},
	{"VK_DESCRIPTOR_BINDING_FLAG_BITS_MAX_ENUM", VK_DESCRIPTOR_BINDING_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDescriptorBindingFlagBits string: " + formatStr);
		}
	}

	VkDescriptorPoolCreateFlagBits Constants::stringToVkDescriptorPoolCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDescriptorPoolCreateFlagBits> formatMap = { {"VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT", VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT},
	{"VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT", VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT},
	{"VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT_EXT", VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT_EXT},
	{"VK_DESCRIPTOR_POOL_CREATE_FLAG_BITS_MAX_ENUM", VK_DESCRIPTOR_POOL_CREATE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDescriptorPoolCreateFlagBits string: " + formatStr);
		}
	}

	VkDescriptorSetLayoutCreateFlagBits Constants::stringToVkDescriptorSetLayoutCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDescriptorSetLayoutCreateFlagBits> formatMap = { {"VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR", VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR},
	{"VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT", VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT},
	{"VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT_EXT", VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT_EXT},
	{"VK_DESCRIPTOR_SET_LAYOUT_CREATE_FLAG_BITS_MAX_ENUM", VK_DESCRIPTOR_SET_LAYOUT_CREATE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDescriptorSetLayoutCreateFlagBits string: " + formatStr);
		}
	}

	VkDescriptorType Constants::stringToVkDescriptorType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDescriptorType> formatMap = {
			{"VK_DESCRIPTOR_TYPE_SAMPLER", VK_DESCRIPTOR_TYPE_SAMPLER},
	{"VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER", VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER},
	{"VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE", VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE},
	{"VK_DESCRIPTOR_TYPE_STORAGE_IMAGE", VK_DESCRIPTOR_TYPE_STORAGE_IMAGE},
	{"VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER", VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER},
	{"VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER", VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER},
	{"VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER", VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER},
	{"VK_DESCRIPTOR_TYPE_STORAGE_BUFFER", VK_DESCRIPTOR_TYPE_STORAGE_BUFFER},
	{"VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC", VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC},
	{"VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC", VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC},
	{"VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT", VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT},
	{"VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT", VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT},
	{"VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV", VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV},
	{"VK_DESCRIPTOR_TYPE_MAX_ENUM", VK_DESCRIPTOR_TYPE_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDescriptorType string: " + formatStr);
		}
	}

	VkDescriptorUpdateTemplateType Constants::stringToVkDescriptorUpdateTemplateType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDescriptorUpdateTemplateType> formatMap = {
			 {"VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET", VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET},
	{"VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR", VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR},
	{"VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET_KHR", VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET_KHR},
	{"VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_MAX_ENUM", VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDescriptorUpdateTemplateType string: " + formatStr);
		}
	}

	VkDeviceEventTypeEXT Constants::stringToVkDeviceEventTypeEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDeviceEventTypeEXT> formatMap = { {"VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT", VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT},
	{"VK_DEVICE_EVENT_TYPE_MAX_ENUM_EXT", VK_DEVICE_EVENT_TYPE_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDeviceEventTypeEXT string: " + formatStr);
		}
	}

	VkDeviceGroupPresentModeFlagBitsKHR Constants::stringToVkDeviceGroupPresentModeFlagBitsKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDeviceGroupPresentModeFlagBitsKHR> formatMap = { {"VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR", VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR},
	{"VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR", VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR},
	{"VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR", VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR},
	{"VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR", VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR},
	{"VK_DEVICE_GROUP_PRESENT_MODE_FLAG_BITS_MAX_ENUM_KHR", VK_DEVICE_GROUP_PRESENT_MODE_FLAG_BITS_MAX_ENUM_KHR}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDeviceGroupPresentModeFlagBitsKHR string: " + formatStr);
		}
	}

	VkDeviceQueueCreateFlagBits Constants::stringToVkDeviceQueueCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDeviceQueueCreateFlagBits> formatMap = { {"VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT", VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT},
	{"VK_DEVICE_QUEUE_CREATE_FLAG_BITS_MAX_ENUM", VK_DEVICE_QUEUE_CREATE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDeviceQueueCreateFlagBits string: " + formatStr);
		}
	}

	VkDiscardRectangleModeEXT Constants::stringToVkDiscardRectangleModeEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDiscardRectangleModeEXT> formatMap = { {"VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT", VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT},
	{"VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT", VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT},
	{"VK_DISCARD_RECTANGLE_MODE_MAX_ENUM_EXT", VK_DISCARD_RECTANGLE_MODE_MAX_ENUM_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDiscardRectangleModeEXT string: " + formatStr);
		}
	}

	VkDisplayEventTypeEXT Constants::stringToVkDisplayEventTypeEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDisplayEventTypeEXT> formatMap = {
		{ "VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT", VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT },
		{ "VK_DISPLAY_EVENT_TYPE_MAX_ENUM_EXT", VK_DISPLAY_EVENT_TYPE_MAX_ENUM_EXT }

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDisplayEventTypeEXT string: " + formatStr);
		}
	}

	VkDisplayPlaneAlphaFlagBitsKHR Constants::stringToVkDisplayPlaneAlphaFlagBitsKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDisplayPlaneAlphaFlagBitsKHR> formatMap = { {"VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR", VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR},
	{"VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR", VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR},
	{"VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR", VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR},
	{"VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR", VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR},
	{"VK_DISPLAY_PLANE_ALPHA_FLAG_BITS_MAX_ENUM_KHR", VK_DISPLAY_PLANE_ALPHA_FLAG_BITS_MAX_ENUM_KHR}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDisplayPlaneAlphaFlagBitsKHR string: " + formatStr);
		}
	}

	VkDisplayPowerStateEXT Constants::stringToVkDisplayPowerStateEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDisplayPowerStateEXT> formatMap = { { "VK_DISPLAY_POWER_STATE_OFF_EXT", VK_DISPLAY_POWER_STATE_OFF_EXT },
		{ "VK_DISPLAY_POWER_STATE_SUSPEND_EXT", VK_DISPLAY_POWER_STATE_SUSPEND_EXT },
		{ "VK_DISPLAY_POWER_STATE_ON_EXT", VK_DISPLAY_POWER_STATE_ON_EXT },
		{ "VK_DISPLAY_POWER_STATE_MAX_ENUM_EXT", VK_DISPLAY_POWER_STATE_MAX_ENUM_EXT }
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDisplayPowerStateEXT string: " + formatStr);
		}
	}

	VkDriverId Constants::stringToVkDriverId(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDriverId> formatMap = { {"VK_DRIVER_ID_AMD_PROPRIETARY", VK_DRIVER_ID_AMD_PROPRIETARY},
	{"VK_DRIVER_ID_AMD_OPEN_SOURCE", VK_DRIVER_ID_AMD_OPEN_SOURCE},
	{"VK_DRIVER_ID_MESA_RADV", VK_DRIVER_ID_MESA_RADV},
	{"VK_DRIVER_ID_NVIDIA_PROPRIETARY", VK_DRIVER_ID_NVIDIA_PROPRIETARY},
	{"VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS", VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS},
	{"VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA", VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA},
	{"VK_DRIVER_ID_IMAGINATION_PROPRIETARY", VK_DRIVER_ID_IMAGINATION_PROPRIETARY},
	{"VK_DRIVER_ID_QUALCOMM_PROPRIETARY", VK_DRIVER_ID_QUALCOMM_PROPRIETARY},
	{"VK_DRIVER_ID_ARM_PROPRIETARY", VK_DRIVER_ID_ARM_PROPRIETARY},
	{"VK_DRIVER_ID_GOOGLE_SWIFTSHADER", VK_DRIVER_ID_GOOGLE_SWIFTSHADER},
	{"VK_DRIVER_ID_GGP_PROPRIETARY", VK_DRIVER_ID_GGP_PROPRIETARY},
	{"VK_DRIVER_ID_BROADCOM_PROPRIETARY", VK_DRIVER_ID_BROADCOM_PROPRIETARY},
	{"VK_DRIVER_ID_MAX_ENUM", VK_DRIVER_ID_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDriverId string: " + formatStr);
		}
	}

	VkDynamicState Constants::stringToVkDynamicState(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkDynamicState> formatMap = { {"VK_DYNAMIC_STATE_VIEWPORT", VK_DYNAMIC_STATE_VIEWPORT},
	{"VK_DYNAMIC_STATE_SCISSOR", VK_DYNAMIC_STATE_SCISSOR},
	{"VK_DYNAMIC_STATE_LINE_WIDTH", VK_DYNAMIC_STATE_LINE_WIDTH},
	{"VK_DYNAMIC_STATE_DEPTH_BIAS", VK_DYNAMIC_STATE_DEPTH_BIAS},
	{"VK_DYNAMIC_STATE_BLEND_CONSTANTS", VK_DYNAMIC_STATE_BLEND_CONSTANTS},
	{"VK_DYNAMIC_STATE_DEPTH_BOUNDS", VK_DYNAMIC_STATE_DEPTH_BOUNDS},
	{"VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK", VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK},
	{"VK_DYNAMIC_STATE_STENCIL_WRITE_MASK", VK_DYNAMIC_STATE_STENCIL_WRITE_MASK},
	{"VK_DYNAMIC_STATE_STENCIL_REFERENCE", VK_DYNAMIC_STATE_STENCIL_REFERENCE},
	{"VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV", VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV},
	{"VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT", VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT},
	{"VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT", VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT},
	{"VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV", VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV},
	{"VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV", VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV},
	{"VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV", VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV},
	{"VK_DYNAMIC_STATE_LINE_STIPPLE_EXT", VK_DYNAMIC_STATE_LINE_STIPPLE_EXT},
	{"VK_DYNAMIC_STATE_MAX_ENUM", VK_DYNAMIC_STATE_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkDynamicState string: " + formatStr);
		}
	}
	VkExternalFenceFeatureFlagBits Constants::stringToVkExternalFenceFeatureFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkExternalFenceFeatureFlagBits> formatMap = { {"VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT", VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT},
	{"VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT", VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT},
	{"VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT_KHR", VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT_KHR},
	{"VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT_KHR", VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT_KHR},
	{"VK_EXTERNAL_FENCE_FEATURE_FLAG_BITS_MAX_ENUM", VK_EXTERNAL_FENCE_FEATURE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkExternalFenceFeatureFlagBits string: " + formatStr);
		}
	}
	VkExternalFenceHandleTypeFlagBits Constants::stringToVkExternalFenceHandleTypeFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkExternalFenceHandleTypeFlagBits> formatMap = { {"VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT", VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT},
	{"VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT", VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT},
	{"VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT", VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT},
	{"VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT", VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT},
	{"VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR", VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR},
	{"VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR", VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR},
	{"VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR", VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR},
	{"VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT_KHR", VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT_KHR},
	{"VK_EXTERNAL_FENCE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM", VK_EXTERNAL_FENCE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkExternalFenceHandleTypeFlagBits string: " + formatStr);
		}
	}
	VkExternalMemoryFeatureFlagBits Constants::stringToVkExternalMemoryFeatureFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkExternalMemoryFeatureFlagBits> formatMap = { {"VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT", VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT},
	{"VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT", VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT},
	{"VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT", VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT},
	{"VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_KHR", VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_KHR", VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_KHR", VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM", VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkExternalMemoryFeatureFlagBits string: " + formatStr);
		}
	}
	VkExternalMemoryFeatureFlagBitsNV Constants::stringToVkExternalMemoryFeatureFlagBitsNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkExternalMemoryFeatureFlagBitsNV> formatMap = {
			  {"VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV", VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV},
	{"VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV", VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV},
	{"VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV", VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV},
	{"VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM_NV", VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM_NV}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkExternalMemoryFeatureFlagBitsNV string: " + formatStr);
		}
	}
	VkExternalMemoryHandleTypeFlagBits Constants::stringToVkExternalMemoryHandleTypeFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkExternalMemoryHandleTypeFlagBits> formatMap = { {"VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID", VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT", VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT_KHR", VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR", VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR", VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT_KHR", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT_KHR", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT_KHR", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT_KHR", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT_KHR},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM", VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkExternalMemoryHandleTypeFlagBits string: " + formatStr);
		}
	}
	VkExternalMemoryHandleTypeFlagBitsNV Constants::stringToVkExternalMemoryHandleTypeFlagBitsNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkExternalMemoryHandleTypeFlagBitsNV> formatMap = { {"VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV", VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV", VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV", VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV},
	{"VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM_NV", VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM_NV}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkExternalMemoryHandleTypeFlagBitsNV string: " + formatStr);
		}
	}
	VkExternalSemaphoreFeatureFlagBits Constants::stringToVkExternalSemaphoreFeatureFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkExternalSemaphoreFeatureFlagBits> formatMap = { {"VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT", VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT},
	{"VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT", VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT},
	{"VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT_KHR", VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT_KHR},
	{"VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT_KHR", VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT_KHR},
	{"VK_EXTERNAL_SEMAPHORE_FEATURE_FLAG_BITS_MAX_ENUM", VK_EXTERNAL_SEMAPHORE_FEATURE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkExternalSemaphoreFeatureFlagBits string: " + formatStr);
		}
	}
	VkExternalSemaphoreHandleTypeFlagBits Constants::stringToVkExternalSemaphoreHandleTypeFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkExternalSemaphoreHandleTypeFlagBits> formatMap = { {"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT_KHR", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT_KHR},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR},
	{"VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM", VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkExternalSemaphoreHandleTypeFlagBits string: " + formatStr);
		}
	}
	VkFenceCreateFlagBits Constants::stringToVkFenceCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkFenceCreateFlagBits> formatMap = { {"VK_FENCE_CREATE_SIGNALED_BIT", VK_FENCE_CREATE_SIGNALED_BIT},
	{"VK_FENCE_CREATE_FLAG_BITS_MAX_ENUM", VK_FENCE_CREATE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkFenceCreateFlagBits string: " + formatStr);
		}
	}
	VkFenceImportFlagBits Constants::stringToVkFenceImportFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkFenceImportFlagBits> formatMap = { {"VK_FENCE_IMPORT_TEMPORARY_BIT", VK_FENCE_IMPORT_TEMPORARY_BIT},
	{"VK_FENCE_IMPORT_TEMPORARY_BIT_KHR", VK_FENCE_IMPORT_TEMPORARY_BIT_KHR},
	{"VK_FENCE_IMPORT_FLAG_BITS_MAX_ENUM", VK_FENCE_IMPORT_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkFenceImportFlagBits string: " + formatStr);
		}
	}
	VkFilter Constants::stringToVkFilter(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkFilter> formatMap = { {"VK_FILTER_NEAREST", VK_FILTER_NEAREST},
	{"VK_FILTER_LINEAR", VK_FILTER_LINEAR},
	{"VK_FILTER_CUBIC_IMG", VK_FILTER_CUBIC_IMG},
	{"VK_FILTER_CUBIC_EXT", VK_FILTER_CUBIC_EXT},
	{"VK_FILTER_MAX_ENUM", VK_FILTER_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkFilter string: " + formatStr);
		}
	}
	VkFormat Constants::stringToVkFormat(const std::string& formatStr) {
		static std::unordered_map<std::string, VkFormat> formatMap = {
{"VK_FORMAT_B8G8R8A8_SRGB", VK_FORMAT_B8G8R8A8_SRGB},
{"VK_FORMAT_D32_SFLOAT", VK_FORMAT_D32_SFLOAT},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkFormat string: " + formatStr);
		}
	}
	VkFormatFeatureFlagBits Constants::stringToVkFormatFeatureFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkFormatFeatureFlagBits> formatMap = {
			 {"VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT},
	{"VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT", VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT},
	{"VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT", VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT},
	{"VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT", VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT},
	{"VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT", VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT},
	{"VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT", VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT},
	{"VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT", VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT},
	{"VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT", VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT},
	{"VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT", VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT},
	{"VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT", VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT},
	{"VK_FORMAT_FEATURE_BLIT_SRC_BIT", VK_FORMAT_FEATURE_BLIT_SRC_BIT},
	{"VK_FORMAT_FEATURE_BLIT_DST_BIT", VK_FORMAT_FEATURE_BLIT_DST_BIT},
	{"VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT},
	{"VK_FORMAT_FEATURE_TRANSFER_SRC_BIT", VK_FORMAT_FEATURE_TRANSFER_SRC_BIT},
	{"VK_FORMAT_FEATURE_TRANSFER_DST_BIT", VK_FORMAT_FEATURE_TRANSFER_DST_BIT},
	{"VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT", VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT},
	{"VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT},
	{"VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT},
	{"VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT},
	{"VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT},
	{"VK_FORMAT_FEATURE_DISJOINT_BIT", VK_FORMAT_FEATURE_DISJOINT_BIT},
	{"VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT", VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT},
	{"VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT", VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT},
	{"VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG", VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG},
	{"VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT", VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT},
	{"VK_FORMAT_FEATURE_FLAG_BITS_MAX_ENUM", VK_FORMAT_FEATURE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkFormatFeatureFlagBits string: " + formatStr);
		}
	}
	VkFramebufferCreateFlagBits Constants::stringToVkFramebufferCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkFramebufferCreateFlagBits> formatMap = { {"VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT", VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT},
	{"VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT_KHR", VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT_KHR},
	{"VK_FRAMEBUFFER_CREATE_FLAG_BITS_MAX_ENUM", VK_FRAMEBUFFER_CREATE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkFramebufferCreateFlagBits string: " + formatStr);
		}
	}
	VkFrontFace Constants::stringToVkFrontFace(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkFrontFace> formatMap = { {"VK_FRONT_FACE_COUNTER_CLOCKWISE", VK_FRONT_FACE_COUNTER_CLOCKWISE},
	{"VK_FRONT_FACE_CLOCKWISE", VK_FRONT_FACE_CLOCKWISE},
	{"VK_FRONT_FACE_MAX_ENUM", VK_FRONT_FACE_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkFrontFace string: " + formatStr);
		}
	}
	VkGeometryFlagBitsNV Constants::stringToVkGeometryFlagBitsNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkGeometryFlagBitsNV> formatMap = { {"VK_GEOMETRY_OPAQUE_BIT_NV", VK_GEOMETRY_OPAQUE_BIT_NV},
	{"VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_NV", VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_NV},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkGeometryFlagBitsNV string: " + formatStr);
		}
	}
	VkGeometryInstanceFlagBitsNV Constants::stringToVkGeometryInstanceFlagBitsNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkGeometryInstanceFlagBitsNV> formatMap = { {"VK_GEOMETRY_INSTANCE_TRIANGLE_CULL_DISABLE_BIT_NV", VK_GEOMETRY_INSTANCE_TRIANGLE_CULL_DISABLE_BIT_NV},
	{"VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_NV", VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_NV},
	{"VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_NV", VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_NV},
	{"VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_NV", VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_NV}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkGeometryInstanceFlagBitsNV string: " + formatStr);
		}
	}
	VkGeometryTypeNV Constants::stringToVkGeometryTypeNV(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkGeometryTypeNV> formatMap = { {"VK_GEOMETRY_TYPE_TRIANGLES_NV", VK_GEOMETRY_TYPE_TRIANGLES_NV},
	{"VK_GEOMETRY_TYPE_AABBS_NV", VK_GEOMETRY_TYPE_AABBS_NV}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkGeometryTypeNV string: " + formatStr);
		}
	}
	VkImageAspectFlagBits Constants::stringToVkImageAspectFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkImageAspectFlagBits> formatMap = { {"VK_IMAGE_ASPECT_COLOR_BIT", VK_IMAGE_ASPECT_COLOR_BIT},
	{"VK_IMAGE_ASPECT_DEPTH_BIT", VK_IMAGE_ASPECT_DEPTH_BIT},
	{"VK_IMAGE_ASPECT_STENCIL_BIT", VK_IMAGE_ASPECT_STENCIL_BIT},
	{"VK_IMAGE_ASPECT_METADATA_BIT", VK_IMAGE_ASPECT_METADATA_BIT},
	{"VK_IMAGE_ASPECT_PLANE_0_BIT", VK_IMAGE_ASPECT_PLANE_0_BIT},
	{"VK_IMAGE_ASPECT_PLANE_1_BIT", VK_IMAGE_ASPECT_PLANE_1_BIT},
	{"VK_IMAGE_ASPECT_PLANE_2_BIT", VK_IMAGE_ASPECT_PLANE_2_BIT},
	{"VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT", VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT},
	{"VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT", VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT},
	{"VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT", VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT},
	{"VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT", VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkImageAspectFlagBits string: " + formatStr);
		}
	}
	VkImageCreateFlagBits Constants::stringToVkImageCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkImageCreateFlagBits> formatMap = { {"VK_IMAGE_CREATE_SPARSE_BINDING_BIT", VK_IMAGE_CREATE_SPARSE_BINDING_BIT},
	{"VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT", VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT},
	{"VK_IMAGE_CREATE_SPARSE_ALIASED_BIT", VK_IMAGE_CREATE_SPARSE_ALIASED_BIT},
	{"VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT", VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT},
	{"VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT", VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT},
	{"VK_IMAGE_CREATE_ALIAS_BIT", VK_IMAGE_CREATE_ALIAS_BIT},
	{"VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT", VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT},
	{"VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT", VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT},
	{"VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT", VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT},
	{"VK_IMAGE_CREATE_EXTENDED_USAGE_BIT", VK_IMAGE_CREATE_EXTENDED_USAGE_BIT},
	{"VK_IMAGE_CREATE_PROTECTED_BIT", VK_IMAGE_CREATE_PROTECTED_BIT},
	{"VK_IMAGE_CREATE_DISJOINT_BIT", VK_IMAGE_CREATE_DISJOINT_BIT},
	{"VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV", VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV},
	{"VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT", VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT},
	{"VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT", VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT},
	{"VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR", VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR},
	{"VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT_KHR", VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT_KHR},
	{"VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR", VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR},
	{"VK_IMAGE_CREATE_EXTENDED_USAGE_BIT_KHR", VK_IMAGE_CREATE_EXTENDED_USAGE_BIT_KHR},
	{"VK_IMAGE_CREATE_DISJOINT_BIT_KHR", VK_IMAGE_CREATE_DISJOINT_BIT_KHR},
	{"VK_IMAGE_CREATE_ALIAS_BIT_KHR", VK_IMAGE_CREATE_ALIAS_BIT_KHR}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkImageCreateFlagBits string: " + formatStr);
		}
	}
	VkImageLayout Constants::stringToVkImageLayout(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkImageLayout> formatMap = { {"VK_IMAGE_LAYOUT_UNDEFINED", VK_IMAGE_LAYOUT_UNDEFINED},
	{"VK_IMAGE_LAYOUT_GENERAL", VK_IMAGE_LAYOUT_GENERAL},
	{"VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL},
	{"VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL},
	{"VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL},
	{"VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL},
	{"VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL", VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL},
	{"VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL", VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL},
	{"VK_IMAGE_LAYOUT_PREINITIALIZED", VK_IMAGE_LAYOUT_PREINITIALIZED},
	{"VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL},
	{"VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL},
	{"VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL},
	{"VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL},
	{"VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL", VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL},
	{"VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL", VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL},
	{"VK_IMAGE_LAYOUT_PRESENT_SRC_KHR", VK_IMAGE_LAYOUT_PRESENT_SRC_KHR},
	{"VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR", VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR},
	{"VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV", VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV},
	{"VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT", VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT},
	{"VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR", VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR},
	{"VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR", VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR},
	{"VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR", VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR},
	{"VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR", VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR},
	{"VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR", VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR},
	{"VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR", VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkImageLayout string: " + formatStr);
		}
	}
	VkImageTiling Constants::stringToVkImageTiling(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkImageTiling> formatMap = { {"VK_IMAGE_TILING_OPTIMAL", VK_IMAGE_TILING_OPTIMAL},
	{"VK_IMAGE_TILING_LINEAR", VK_IMAGE_TILING_LINEAR},
	{"VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT", VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkImageTiling string: " + formatStr);
		}
	}
	VkImageType Constants::stringToVkImageType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkImageType> formatMap = { {"VK_IMAGE_TYPE_1D", VK_IMAGE_TYPE_1D},
	{"VK_IMAGE_TYPE_2D", VK_IMAGE_TYPE_2D},
	{"VK_IMAGE_TYPE_3D", VK_IMAGE_TYPE_3D}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkImageType string: " + formatStr);
		}
	}
	VkImageUsageFlagBits Constants::stringToVkImageUsageFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkImageUsageFlagBits> formatMap = { {"VK_IMAGE_USAGE_TRANSFER_SRC_BIT", VK_IMAGE_USAGE_TRANSFER_SRC_BIT},
	{"VK_IMAGE_USAGE_TRANSFER_DST_BIT", VK_IMAGE_USAGE_TRANSFER_DST_BIT},
	{"VK_IMAGE_USAGE_SAMPLED_BIT", VK_IMAGE_USAGE_SAMPLED_BIT},
	{"VK_IMAGE_USAGE_STORAGE_BIT", VK_IMAGE_USAGE_STORAGE_BIT},
	{"VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT", VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT},
	{"VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT", VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT},
	{"VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT", VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT},
	{"VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT", VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT},
	{"VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV", VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV},
	{"VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT", VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkImageUsageFlagBits string: " + formatStr);
		}
	}
	VkImageViewCreateFlagBits Constants::stringToVkImageViewCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkImageViewCreateFlagBits> formatMap = {
	{"VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT", VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkImageViewCreateFlagBits string: " + formatStr);
		}
	}
	VkImageViewType Constants::stringToVkImageViewType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkImageViewType> formatMap = { {"VK_IMAGE_VIEW_TYPE_1D", VK_IMAGE_VIEW_TYPE_1D},
	{"VK_IMAGE_VIEW_TYPE_2D", VK_IMAGE_VIEW_TYPE_2D},
	{"VK_IMAGE_VIEW_TYPE_3D", VK_IMAGE_VIEW_TYPE_3D},
	{"VK_IMAGE_VIEW_TYPE_CUBE", VK_IMAGE_VIEW_TYPE_CUBE},
	{"VK_IMAGE_VIEW_TYPE_1D_ARRAY", VK_IMAGE_VIEW_TYPE_1D_ARRAY},
	{"VK_IMAGE_VIEW_TYPE_2D_ARRAY", VK_IMAGE_VIEW_TYPE_2D_ARRAY},
	{"VK_IMAGE_VIEW_TYPE_CUBE_ARRAY", VK_IMAGE_VIEW_TYPE_CUBE_ARRAY}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkImageViewType string: " + formatStr);
		}
	}
	VkIndexType Constants::stringToVkIndexType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkIndexType> formatMap = { {"VK_INDEX_TYPE_UINT16", VK_INDEX_TYPE_UINT16},
	{"VK_INDEX_TYPE_UINT32", VK_INDEX_TYPE_UINT32},
	{"VK_INDEX_TYPE_NONE_NV", VK_INDEX_TYPE_NONE_NV},
	{"VK_INDEX_TYPE_UINT8_EXT", VK_INDEX_TYPE_UINT8_EXT}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkIndexType string: " + formatStr);
		}
	}
	VkInternalAllocationType Constants::stringToVkInternalAllocationType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkInternalAllocationType> formatMap = { {"VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE", VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkInternalAllocationType string: " + formatStr);
		}
	}
	VkLineRasterizationModeEXT Constants::stringToVkLineRasterizationModeEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkLineRasterizationModeEXT> formatMap = {
			   {"VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT", VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT},
	{"VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT", VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT},
	{"VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT", VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT},
	{"VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT", VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkLineRasterizationModeEXT string: " + formatStr);
		}
	}
	VkLogicOp Constants::stringToVkLogicOp(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkLogicOp> formatMap = { {"VK_LOGIC_OP_CLEAR", VK_LOGIC_OP_CLEAR},
	{"VK_LOGIC_OP_AND", VK_LOGIC_OP_AND},
	{"VK_LOGIC_OP_AND_REVERSE", VK_LOGIC_OP_AND_REVERSE},
	{"VK_LOGIC_OP_COPY", VK_LOGIC_OP_COPY},
	{"VK_LOGIC_OP_AND_INVERTED", VK_LOGIC_OP_AND_INVERTED},
	{"VK_LOGIC_OP_NO_OP", VK_LOGIC_OP_NO_OP},
	{"VK_LOGIC_OP_XOR", VK_LOGIC_OP_XOR},
	{"VK_LOGIC_OP_OR", VK_LOGIC_OP_OR},
	{"VK_LOGIC_OP_NOR", VK_LOGIC_OP_NOR},
	{"VK_LOGIC_OP_EQUIVALENT", VK_LOGIC_OP_EQUIVALENT},
	{"VK_LOGIC_OP_INVERT", VK_LOGIC_OP_INVERT},
	{"VK_LOGIC_OP_OR_REVERSE", VK_LOGIC_OP_OR_REVERSE},
	{"VK_LOGIC_OP_COPY_INVERTED", VK_LOGIC_OP_COPY_INVERTED},
	{"VK_LOGIC_OP_OR_INVERTED", VK_LOGIC_OP_OR_INVERTED},
	{"VK_LOGIC_OP_NAND", VK_LOGIC_OP_NAND},
	{"VK_LOGIC_OP_SET", VK_LOGIC_OP_SET}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkLogicOp string: " + formatStr);
		}
	}
	VkMemoryAllocateFlagBits Constants::stringToVkMemoryAllocateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkMemoryAllocateFlagBits> formatMap = {
			   {"VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT", VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT},
	{"VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT", VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT},
	{"VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT", VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT},
	{"VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT_KHR", VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT_KHR},
	{"VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT_KHR", VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT_KHR},
	{"VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR", VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR}


		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkMemoryAllocateFlagBits string: " + formatStr);
		}
	}
	VkMemoryHeapFlagBits Constants::stringToVkMemoryHeapFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkMemoryHeapFlagBits> formatMap = { {"VK_MEMORY_HEAP_DEVICE_LOCAL_BIT", VK_MEMORY_HEAP_DEVICE_LOCAL_BIT},
	{"VK_MEMORY_HEAP_MULTI_INSTANCE_BIT", VK_MEMORY_HEAP_MULTI_INSTANCE_BIT},
	{"VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR", VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR},
		{"VK_MEMORY_HEAP_FLAG_BITS_MAX_ENUM",VK_MEMORY_HEAP_FLAG_BITS_MAX_ENUM
  }
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkMemoryHeapFlagBits string: " + formatStr);
		}
	}
	VkMemoryOverallocationBehaviorAMD Constants::stringToVkMemoryOverallocationBehaviorAMD(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkMemoryOverallocationBehaviorAMD> formatMap = { {"VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD ",VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD }, {"VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD  ",VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD  }, {"VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD  ",VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD  }, {"VK_MEMORY_OVERALLOCATION_BEHAVIOR_MAX_ENUM_AMD  ",VK_MEMORY_OVERALLOCATION_BEHAVIOR_MAX_ENUM_AMD  },

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkMemoryOverallocationBehaviorAMD string: " + formatStr);
		}
	}
	VkMemoryPropertyFlagBits Constants::stringToVkMemoryPropertyFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkMemoryPropertyFlagBits> formatMap = { {"VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT", VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT},
	{"VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT", VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT},
	{"VK_MEMORY_PROPERTY_HOST_COHERENT_BIT", VK_MEMORY_PROPERTY_HOST_COHERENT_BIT},
	{"VK_MEMORY_PROPERTY_HOST_CACHED_BIT", VK_MEMORY_PROPERTY_HOST_CACHED_BIT},
	{"VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT", VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT},
	{"VK_MEMORY_PROPERTY_PROTECTED_BIT", VK_MEMORY_PROPERTY_PROTECTED_BIT},
	{"VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD", VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD},
	{"VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD", VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkMemoryPropertyFlagBits string: " + formatStr);
		}
	}
	VkObjectType Constants::stringToVkObjectType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkObjectType> formatMap = { {"VK_OBJECT_TYPE_UNKNOWN", VK_OBJECT_TYPE_UNKNOWN},
	{"VK_OBJECT_TYPE_INSTANCE", VK_OBJECT_TYPE_INSTANCE},
	{"VK_OBJECT_TYPE_PHYSICAL_DEVICE", VK_OBJECT_TYPE_PHYSICAL_DEVICE},
	{"VK_OBJECT_TYPE_DEVICE", VK_OBJECT_TYPE_DEVICE},
	{"VK_OBJECT_TYPE_QUEUE", VK_OBJECT_TYPE_QUEUE},
	{"VK_OBJECT_TYPE_SEMAPHORE", VK_OBJECT_TYPE_SEMAPHORE},
	{"VK_OBJECT_TYPE_COMMAND_BUFFER", VK_OBJECT_TYPE_COMMAND_BUFFER},
	{"VK_OBJECT_TYPE_FENCE", VK_OBJECT_TYPE_FENCE},
	{"VK_OBJECT_TYPE_DEVICE_MEMORY", VK_OBJECT_TYPE_DEVICE_MEMORY},
	{"VK_OBJECT_TYPE_BUFFER", VK_OBJECT_TYPE_BUFFER},
	{"VK_OBJECT_TYPE_IMAGE", VK_OBJECT_TYPE_IMAGE},
	{"VK_OBJECT_TYPE_EVENT", VK_OBJECT_TYPE_EVENT},
	{"VK_OBJECT_TYPE_QUERY_POOL", VK_OBJECT_TYPE_QUERY_POOL},
	{"VK_OBJECT_TYPE_BUFFER_VIEW", VK_OBJECT_TYPE_BUFFER_VIEW},
	{"VK_OBJECT_TYPE_IMAGE_VIEW", VK_OBJECT_TYPE_IMAGE_VIEW},
	{"VK_OBJECT_TYPE_SHADER_MODULE", VK_OBJECT_TYPE_SHADER_MODULE},
	{"VK_OBJECT_TYPE_PIPELINE_CACHE", VK_OBJECT_TYPE_PIPELINE_CACHE},
	{"VK_OBJECT_TYPE_PIPELINE_LAYOUT", VK_OBJECT_TYPE_PIPELINE_LAYOUT},
	{"VK_OBJECT_TYPE_RENDER_PASS", VK_OBJECT_TYPE_RENDER_PASS},
	{"VK_OBJECT_TYPE_PIPELINE", VK_OBJECT_TYPE_PIPELINE},
	{"VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT", VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT},
	{"VK_OBJECT_TYPE_SAMPLER", VK_OBJECT_TYPE_SAMPLER},
	{"VK_OBJECT_TYPE_DESCRIPTOR_POOL", VK_OBJECT_TYPE_DESCRIPTOR_POOL},
	{"VK_OBJECT_TYPE_DESCRIPTOR_SET", VK_OBJECT_TYPE_DESCRIPTOR_SET},
	{"VK_OBJECT_TYPE_FRAMEBUFFER", VK_OBJECT_TYPE_FRAMEBUFFER},
	{"VK_OBJECT_TYPE_COMMAND_POOL", VK_OBJECT_TYPE_COMMAND_POOL},
	{"VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION", VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION},
	{"VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE", VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE},
	{"VK_OBJECT_TYPE_SURFACE_KHR", VK_OBJECT_TYPE_SURFACE_KHR},
	{"VK_OBJECT_TYPE_SWAPCHAIN_KHR", VK_OBJECT_TYPE_SWAPCHAIN_KHR},
	{"VK_OBJECT_TYPE_DISPLAY_KHR", VK_OBJECT_TYPE_DISPLAY_KHR},
	{"VK_OBJECT_TYPE_DISPLAY_MODE_KHR", VK_OBJECT_TYPE_DISPLAY_MODE_KHR},
	{"VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT", VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT},
	{"VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT", VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT},
	{"VK_OBJECT_TYPE_VALIDATION_CACHE_EXT", VK_OBJECT_TYPE_VALIDATION_CACHE_EXT},
	{"VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV", VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV},
	{"VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL", VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL},
	{"VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR", VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR},
	{"VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR", VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkObjectType string: " + formatStr);
		}
	}
	VkPeerMemoryFeatureFlagBits Constants::stringToVkPeerMemoryFeatureFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPeerMemoryFeatureFlagBits> formatMap = { {"VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT", VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT},
	{"VK_PEER_MEMORY_FEATURE_COPY_DST_BIT", VK_PEER_MEMORY_FEATURE_COPY_DST_BIT},
	{"VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT", VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT},
	{"VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT", VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT},
	{"VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT_KHR", VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT_KHR},
	{"VK_PEER_MEMORY_FEATURE_COPY_DST_BIT_KHR", VK_PEER_MEMORY_FEATURE_COPY_DST_BIT_KHR},
	{"VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT_KHR", VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT_KHR},
	{"VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT_KHR", VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT_KHR}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPeerMemoryFeatureFlagBits string: " + formatStr);
		}
	}
	VkPerformanceConfigurationTypeINTEL Constants::stringToVkPerformanceConfigurationTypeINTEL(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPerformanceConfigurationTypeINTEL> formatMap = { {"VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL", VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL},
	{"VK_PERFORMANCE_CONFIGURATION_TYPE_MAX_ENUM_INTEL", VK_PERFORMANCE_CONFIGURATION_TYPE_MAX_ENUM_INTEL}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPerformanceConfigurationTypeINTEL string: " + formatStr);
		}
	}
	VkPerformanceCounterDescriptionFlagBitsKHR Constants::stringToVkPerformanceCounterDescriptionFlagBitsKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPerformanceCounterDescriptionFlagBitsKHR> formatMap = { {"VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_KHR", VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_KHR},
	{"VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_KHR", VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_KHR},
	{"VK_PERFORMANCE_COUNTER_DESCRIPTION_FLAG_BITS_MAX_ENUM_KHR", VK_PERFORMANCE_COUNTER_DESCRIPTION_FLAG_BITS_MAX_ENUM_KHR}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPerformanceCounterDescriptionFlagBitsKHR string: " + formatStr);
		}
	}
	VkPerformanceCounterScopeKHR Constants::stringToVkPerformanceCounterScopeKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPerformanceCounterScopeKHR> formatMap = { {"VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR", VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR},
	{"VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR", VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR},
	{"VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR", VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR},
	{"VK_QUERY_SCOPE_COMMAND_BUFFER_KHR", VK_QUERY_SCOPE_COMMAND_BUFFER_KHR},
	{"VK_QUERY_SCOPE_RENDER_PASS_KHR", VK_QUERY_SCOPE_RENDER_PASS_KHR},
	{"VK_QUERY_SCOPE_COMMAND_KHR", VK_QUERY_SCOPE_COMMAND_KHR},
	{"VK_PERFORMANCE_COUNTER_SCOPE_MAX_ENUM_KHR", VK_PERFORMANCE_COUNTER_SCOPE_MAX_ENUM_KHR}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPerformanceCounterScopeKHR string: " + formatStr);
		}
	}
	VkPerformanceCounterStorageKHR Constants::stringToVkPerformanceCounterStorageKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPerformanceCounterStorageKHR> formatMap = { {"VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR", VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR},
	{"VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR", VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR},
	{"VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR", VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR},
	{"VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR", VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR},
	{"VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR", VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR},
	{"VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR", VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR},
	{"VK_PERFORMANCE_COUNTER_STORAGE_MAX_ENUM_KHR", VK_PERFORMANCE_COUNTER_STORAGE_MAX_ENUM_KHR}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPerformanceCounterStorageKHR string: " + formatStr);
		}
	}

	VkPhysicalDeviceType Constants::stringToVkPhysicalDeviceType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPhysicalDeviceType> formatMap = { {"VK_PHYSICAL_DEVICE_TYPE_OTHER", VK_PHYSICAL_DEVICE_TYPE_OTHER},
	{"VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU", VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU},
	{"VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU", VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU},
	{"VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU", VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU},
	{"VK_PHYSICAL_DEVICE_TYPE_CPU", VK_PHYSICAL_DEVICE_TYPE_CPU},
	{"VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM", VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPhysicalDeviceType string: " + formatStr);
		}
	}
	VkPipelineBindPoint Constants::stringToVkPipelineBindPoint(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPipelineBindPoint> formatMap = { {"VK_PIPELINE_BIND_POINT_GRAPHICS", VK_PIPELINE_BIND_POINT_GRAPHICS},
	{"VK_PIPELINE_BIND_POINT_COMPUTE", VK_PIPELINE_BIND_POINT_COMPUTE},
	{"VK_PIPELINE_BIND_POINT_RAY_TRACING_NV", VK_PIPELINE_BIND_POINT_RAY_TRACING_NV},
	{"VK_PIPELINE_BIND_POINT_MAX_ENUM", VK_PIPELINE_BIND_POINT_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPipelineBindPoint string: " + formatStr);
		}
	}
	VkPipelineCacheHeaderVersion Constants::stringToVkPipelineCacheHeaderVersion(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPipelineCacheHeaderVersion> formatMap = { {"VK_PIPELINE_CACHE_HEADER_VERSION_ONE", VK_PIPELINE_CACHE_HEADER_VERSION_ONE},
	{"VK_PIPELINE_CACHE_HEADER_VERSION_MAX_ENUM", VK_PIPELINE_CACHE_HEADER_VERSION_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPipelineCacheHeaderVersion string: " + formatStr);
		}
	}

	VkPipelineCreateFlagBits Constants::stringToVkPipelineCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPipelineCreateFlagBits> formatMap = { {"VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT", VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT},
	{"VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT", VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT},
	{"VK_PIPELINE_CREATE_DERIVATIVE_BIT", VK_PIPELINE_CREATE_DERIVATIVE_BIT},
	{"VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT", VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT},
	{"VK_PIPELINE_CREATE_DISPATCH_BASE_BIT", VK_PIPELINE_CREATE_DISPATCH_BASE_BIT},
	{"VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV", VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV},
	{"VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR", VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR},
	{"VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR", VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR},
	{"VK_PIPELINE_CREATE_DISPATCH_BASE", VK_PIPELINE_CREATE_DISPATCH_BASE},
	{"VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR", VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR},
	{"VK_PIPELINE_CREATE_DISPATCH_BASE_KHR", VK_PIPELINE_CREATE_DISPATCH_BASE_KHR},
	{"VK_PIPELINE_CREATE_FLAG_BITS_MAX_ENUM", VK_PIPELINE_CREATE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPipelineCreateFlagBits string: " + formatStr);
		}
	}
	VkPipelineCreationFeedbackFlagBitsEXT Constants::stringToVkPipelineCreationFeedbackFlagBitsEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPipelineCreationFeedbackFlagBitsEXT> formatMap = { {"VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT_EXT", VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT_EXT},
	{"VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT_EXT", VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT_EXT},
	{"VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT_EXT", VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT_EXT}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPipelineCreationFeedbackFlagBitsEXT string: " + formatStr);
		}
	}
	VkPipelineExecutableStatisticFormatKHR Constants::stringToVkPipelineExecutableStatisticFormatKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPipelineExecutableStatisticFormatKHR> formatMap = { {"VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR", VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR},
	{"VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR", VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR},
	{"VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR", VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR},
	{"VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR", VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR},
	{"VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_MAX_ENUM_KHR", VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_MAX_ENUM_KHR}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPipelineExecutableStatisticFormatKHR string: " + formatStr);
		}
	}
	VkPipelineShaderStageCreateFlagBits Constants::stringToVkPipelineShaderStageCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPipelineShaderStageCreateFlagBits> formatMap = { {"VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT", VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT},
	{"VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT", VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT},
	{"VK_PIPELINE_SHADER_STAGE_CREATE_FLAG_BITS_MAX_ENUM", VK_PIPELINE_SHADER_STAGE_CREATE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPipelineShaderStageCreateFlagBits string: " + formatStr);
		}
	}
	VkPipelineStageFlagBits Constants::stringToVkPipelineStageFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPipelineStageFlagBits> formatMap = { {"VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT", VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT},
	{"VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT", VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT},
	{"VK_PIPELINE_STAGE_VERTEX_INPUT_BIT", VK_PIPELINE_STAGE_VERTEX_INPUT_BIT},
	{"VK_PIPELINE_STAGE_VERTEX_SHADER_BIT", VK_PIPELINE_STAGE_VERTEX_SHADER_BIT},
	{"VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT", VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT},
	{"VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT", VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT},
	{"VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT", VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT},
	{"VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT", VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT},
	{"VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT", VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT},
	{"VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT", VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT},
	{"VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT", VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT},
	{"VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT", VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT},
	{"VK_PIPELINE_STAGE_TRANSFER_BIT", VK_PIPELINE_STAGE_TRANSFER_BIT},
	{"VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT", VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT},
	{"VK_PIPELINE_STAGE_HOST_BIT", VK_PIPELINE_STAGE_HOST_BIT},
	{"VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT", VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT},
	{"VK_PIPELINE_STAGE_ALL_COMMANDS_BIT", VK_PIPELINE_STAGE_ALL_COMMANDS_BIT},
	{"VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT", VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT},
	{"VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT", VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT},
	{"VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV", VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV},
	{"VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV", VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV},
	{"VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV", VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV},
	{"VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV", VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV},
	{"VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV", VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV},
	{"VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT", VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT},
	{"VK_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM", VK_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPipelineStageFlagBits string: " + formatStr);
		}
	}
	VkPointClippingBehavior Constants::stringToVkPointClippingBehavior(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPointClippingBehavior> formatMap = {
			  {"VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES", VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES},
	{"VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY", VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY},
	{"VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES_KHR", VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES_KHR},
	{"VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY_KHR", VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY_KHR},
	{"VK_POINT_CLIPPING_BEHAVIOR_MAX_ENUM", VK_POINT_CLIPPING_BEHAVIOR_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPointClippingBehavior string: " + formatStr);
		}
	}
	VkPolygonMode Constants::stringToVkPolygonMode(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPolygonMode> formatMap = { {"VK_POLYGON_MODE_FILL", VK_POLYGON_MODE_FILL},
	{"VK_POLYGON_MODE_LINE", VK_POLYGON_MODE_LINE},
	{"VK_POLYGON_MODE_POINT", VK_POLYGON_MODE_POINT},
	{"VK_POLYGON_MODE_FILL_RECTANGLE_NV", VK_POLYGON_MODE_FILL_RECTANGLE_NV},
	{"VK_POLYGON_MODE_MAX_ENUM", VK_POLYGON_MODE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPolygonMode string: " + formatStr);
		}
	}
	VkPresentModeKHR Constants::stringToVkPresentModeKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPresentModeKHR> formatMap = { {"VK_PRESENT_MODE_IMMEDIATE_KHR", VK_PRESENT_MODE_IMMEDIATE_KHR},
	{"VK_PRESENT_MODE_MAILBOX_KHR", VK_PRESENT_MODE_MAILBOX_KHR},
	{"VK_PRESENT_MODE_FIFO_KHR", VK_PRESENT_MODE_FIFO_KHR},
	{"VK_PRESENT_MODE_FIFO_RELAXED_KHR", VK_PRESENT_MODE_FIFO_RELAXED_KHR},
	{"VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR", VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR},
	{"VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR", VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR},
	{"VK_PRESENT_MODE_MAX_ENUM_KHR", VK_PRESENT_MODE_MAX_ENUM_KHR}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPresentModeKHR string: " + formatStr);
		}
	}
	VkPrimitiveTopology Constants::stringToVkPrimitiveTopology(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkPrimitiveTopology> formatMap = { {"VK_PRIMITIVE_TOPOLOGY_POINT_LIST", VK_PRIMITIVE_TOPOLOGY_POINT_LIST},
	{"VK_PRIMITIVE_TOPOLOGY_LINE_LIST", VK_PRIMITIVE_TOPOLOGY_LINE_LIST},
	{"VK_PRIMITIVE_TOPOLOGY_LINE_STRIP", VK_PRIMITIVE_TOPOLOGY_LINE_STRIP},
	{"VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST", VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST},
	{"VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP", VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP},
	{"VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN", VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN},
	{"VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY", VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY},
	{"VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY", VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY},
	{"VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY", VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY},
	{"VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY", VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY},
	{"VK_PRIMITIVE_TOPOLOGY_PATCH_LIST", VK_PRIMITIVE_TOPOLOGY_PATCH_LIST},
	{"VK_PRIMITIVE_TOPOLOGY_MAX_ENUM", VK_PRIMITIVE_TOPOLOGY_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkPrimitiveTopology string: " + formatStr);
		}
	}
	VkQueryControlFlagBits Constants::stringToVkQueryControlFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkQueryControlFlagBits> formatMap = { {"VK_QUERY_CONTROL_PRECISE_BIT", VK_QUERY_CONTROL_PRECISE_BIT},
	{"VK_QUERY_CONTROL_FLAG_BITS_MAX_ENUM", VK_QUERY_CONTROL_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkQueryControlFlagBits string: " + formatStr);
		}
	}
	VkQueryPipelineStatisticFlagBits Constants::stringToVkQueryPipelineStatisticFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkQueryPipelineStatisticFlagBits> formatMap = { {"VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT", VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT", VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT", VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT", VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT", VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT", VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT", VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT", VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT", VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT", VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT", VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT},
	{"VK_QUERY_PIPELINE_STATISTIC_FLAG_BITS_MAX_ENUM", VK_QUERY_PIPELINE_STATISTIC_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkQueryPipelineStatisticFlagBits string: " + formatStr);
		}
	}

	VkQueryResultFlagBits Constants::stringToVkQueryResultFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkQueryResultFlagBits> formatMap = { {"VK_QUERY_RESULT_64_BIT", VK_QUERY_RESULT_64_BIT},
	{"VK_QUERY_RESULT_WAIT_BIT", VK_QUERY_RESULT_WAIT_BIT},
	{"VK_QUERY_RESULT_WITH_AVAILABILITY_BIT", VK_QUERY_RESULT_WITH_AVAILABILITY_BIT},
	{"VK_QUERY_RESULT_PARTIAL_BIT", VK_QUERY_RESULT_PARTIAL_BIT},
	{"VK_QUERY_RESULT_FLAG_BITS_MAX_ENUM", VK_QUERY_RESULT_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkQueryResultFlagBits string: " + formatStr);
		}
	}
	VkQueryType Constants::stringToVkQueryType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkQueryType> formatMap = { {"VK_QUERY_TYPE_OCCLUSION", VK_QUERY_TYPE_OCCLUSION},
	{"VK_QUERY_TYPE_PIPELINE_STATISTICS", VK_QUERY_TYPE_PIPELINE_STATISTICS},
	{"VK_QUERY_TYPE_TIMESTAMP", VK_QUERY_TYPE_TIMESTAMP},
	{"VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT", VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT},
	{"VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR", VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR},
	{"VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV", VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV},
	{"VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL", VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL},
	{"VK_QUERY_TYPE_MAX_ENUM", VK_QUERY_TYPE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkQueryType string: " + formatStr);
		}
	}
	VkQueueFlagBits Constants::stringToVkQueueFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkQueueFlagBits> formatMap = { {"VK_QUEUE_GRAPHICS_BIT", VK_QUEUE_GRAPHICS_BIT},
	{"VK_QUEUE_COMPUTE_BIT", VK_QUEUE_COMPUTE_BIT},
	{"VK_QUEUE_TRANSFER_BIT", VK_QUEUE_TRANSFER_BIT},
	{"VK_QUEUE_SPARSE_BINDING_BIT", VK_QUEUE_SPARSE_BINDING_BIT},
	{"VK_QUEUE_PROTECTED_BIT", VK_QUEUE_PROTECTED_BIT},
	{"VK_QUEUE_FLAG_BITS_MAX_ENUM", VK_QUEUE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkQueueFlagBits string: " + formatStr);
		}
	}
	VkQueueGlobalPriorityEXT Constants::stringToVkQueueGlobalPriorityEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkQueueGlobalPriorityEXT> formatMap = { {"VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT", VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT},
	{"VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_EXT", VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_EXT},
	{"VK_QUEUE_GLOBAL_PRIORITY_HIGH_EXT", VK_QUEUE_GLOBAL_PRIORITY_HIGH_EXT},
	{"VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT", VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkQueueGlobalPriorityEXT string: " + formatStr);
		}
	}

	VkResolveModeFlagBits Constants::stringToVkResolveModeFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkResolveModeFlagBits> formatMap = { {"VK_RESOLVE_MODE_NONE", VK_RESOLVE_MODE_NONE},
	{"VK_RESOLVE_MODE_SAMPLE_ZERO_BIT", VK_RESOLVE_MODE_SAMPLE_ZERO_BIT},
	{"VK_RESOLVE_MODE_AVERAGE_BIT", VK_RESOLVE_MODE_AVERAGE_BIT},
	{"VK_RESOLVE_MODE_MIN_BIT", VK_RESOLVE_MODE_MIN_BIT},
	{"VK_RESOLVE_MODE_MAX_BIT", VK_RESOLVE_MODE_MAX_BIT},
	{"VK_RESOLVE_MODE_NONE_KHR", VK_RESOLVE_MODE_NONE_KHR},
	{"VK_RESOLVE_MODE_SAMPLE_ZERO_BIT_KHR", VK_RESOLVE_MODE_SAMPLE_ZERO_BIT_KHR},
	{"VK_RESOLVE_MODE_AVERAGE_BIT_KHR", VK_RESOLVE_MODE_AVERAGE_BIT_KHR},
	{"VK_RESOLVE_MODE_MIN_BIT_KHR", VK_RESOLVE_MODE_MIN_BIT_KHR},
	{"VK_RESOLVE_MODE_MAX_BIT_KHR", VK_RESOLVE_MODE_MAX_BIT_KHR},
	{"VK_RESOLVE_MODE_FLAG_BITS_MAX_ENUM", VK_RESOLVE_MODE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkResolveModeFlagBits string: " + formatStr);
		}
	}
	VkResult Constants::stringToVkResult(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkResult> formatMap = { {"VK_SUCCESS", VK_SUCCESS},
	{"VK_NOT_READY", VK_NOT_READY},
	{"VK_TIMEOUT", VK_TIMEOUT},
	{"VK_EVENT_SET", VK_EVENT_SET},
	{"VK_EVENT_RESET", VK_EVENT_RESET},
	{"VK_INCOMPLETE", VK_INCOMPLETE},
	{"VK_ERROR_OUT_OF_HOST_MEMORY", VK_ERROR_OUT_OF_HOST_MEMORY},
	{"VK_ERROR_OUT_OF_DEVICE_MEMORY", VK_ERROR_OUT_OF_DEVICE_MEMORY},
	{"VK_ERROR_INITIALIZATION_FAILED", VK_ERROR_INITIALIZATION_FAILED},
	{"VK_ERROR_DEVICE_LOST", VK_ERROR_DEVICE_LOST},
	{"VK_ERROR_MEMORY_MAP_FAILED", VK_ERROR_MEMORY_MAP_FAILED},
	{"VK_ERROR_LAYER_NOT_PRESENT", VK_ERROR_LAYER_NOT_PRESENT},
	{"VK_ERROR_EXTENSION_NOT_PRESENT", VK_ERROR_EXTENSION_NOT_PRESENT},
	{"VK_ERROR_FEATURE_NOT_PRESENT", VK_ERROR_FEATURE_NOT_PRESENT},
	{"VK_ERROR_INCOMPATIBLE_DRIVER", VK_ERROR_INCOMPATIBLE_DRIVER},
	{"VK_ERROR_TOO_MANY_OBJECTS", VK_ERROR_TOO_MANY_OBJECTS},
	{"VK_ERROR_FORMAT_NOT_SUPPORTED", VK_ERROR_FORMAT_NOT_SUPPORTED},
	{"VK_ERROR_FRAGMENTED_POOL", VK_ERROR_FRAGMENTED_POOL},
	{"VK_ERROR_UNKNOWN", VK_ERROR_UNKNOWN},
	{"VK_ERROR_OUT_OF_POOL_MEMORY", VK_ERROR_OUT_OF_POOL_MEMORY},
	{"VK_ERROR_INVALID_EXTERNAL_HANDLE", VK_ERROR_INVALID_EXTERNAL_HANDLE},
	{"VK_ERROR_FRAGMENTATION", VK_ERROR_FRAGMENTATION},
	{"VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS", VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS},
	{"VK_ERROR_SURFACE_LOST_KHR", VK_ERROR_SURFACE_LOST_KHR},
	{"VK_ERROR_NATIVE_WINDOW_IN_USE_KHR", VK_ERROR_NATIVE_WINDOW_IN_USE_KHR},
	{"VK_SUBOPTIMAL_KHR", VK_SUBOPTIMAL_KHR},
	{"VK_ERROR_OUT_OF_DATE_KHR", VK_ERROR_OUT_OF_DATE_KHR},
	{"VK_ERROR_INCOMPATIBLE_DISPLAY_KHR", VK_ERROR_INCOMPATIBLE_DISPLAY_KHR},
	{"VK_ERROR_VALIDATION_FAILED_EXT", VK_ERROR_VALIDATION_FAILED_EXT},
	{"VK_ERROR_INVALID_SHADER_NV", VK_ERROR_INVALID_SHADER_NV},
	{"VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT", VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT},
	{"VK_ERROR_NOT_PERMITTED_EXT", VK_ERROR_NOT_PERMITTED_EXT},
	{"VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT", VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT},
	{"VK_ERROR_OUT_OF_POOL_MEMORY_KHR", VK_ERROR_OUT_OF_POOL_MEMORY_KHR},
	{"VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR", VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR},
	{"VK_ERROR_FRAGMENTATION_EXT", VK_ERROR_FRAGMENTATION_EXT},
	{"VK_ERROR_INVALID_DEVICE_ADDRESS_EXT", VK_ERROR_INVALID_DEVICE_ADDRESS_EXT},
	{"VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR", VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR},
	{"VK_RESULT_MAX_ENUM", VK_RESULT_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkResult string: " + formatStr);
		}
	}
	VkSampleCountFlagBits Constants::stringToVkSampleCountFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSampleCountFlagBits> formatMap = { {"VK_SAMPLE_COUNT_1_BIT", VK_SAMPLE_COUNT_1_BIT},
	{"VK_SAMPLE_COUNT_2_BIT", VK_SAMPLE_COUNT_2_BIT},
	{"VK_SAMPLE_COUNT_4_BIT", VK_SAMPLE_COUNT_4_BIT},
	{"VK_SAMPLE_COUNT_8_BIT", VK_SAMPLE_COUNT_8_BIT},
	{"VK_SAMPLE_COUNT_16_BIT", VK_SAMPLE_COUNT_16_BIT},
	{"VK_SAMPLE_COUNT_32_BIT", VK_SAMPLE_COUNT_32_BIT},
	{"VK_SAMPLE_COUNT_64_BIT", VK_SAMPLE_COUNT_64_BIT},
	{"VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM", VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSampleCountFlagBits string: " + formatStr);
		}
	}
	VkSamplerAddressMode Constants::stringToVkSamplerAddressMode(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSamplerAddressMode> formatMap = {
			{"VK_SAMPLER_ADDRESS_MODE_REPEAT", VK_SAMPLER_ADDRESS_MODE_REPEAT},
	{"VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT", VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT},
	{"VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE", VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE},
	{"VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER", VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER},
	{"VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE", VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE},
	{"VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE_KHR", VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE_KHR},
	{"VK_SAMPLER_ADDRESS_MODE_MAX_ENUM", VK_SAMPLER_ADDRESS_MODE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSamplerAddressMode string: " + formatStr);
		}
	}
	VkSamplerCreateFlagBits Constants::stringToVkSamplerCreateFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSamplerCreateFlagBits> formatMap = {
			  {"VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT", VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT},
	{"VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT", VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT},
	{"VK_SAMPLER_CREATE_FLAG_BITS_MAX_ENUM", VK_SAMPLER_CREATE_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSamplerCreateFlagBits string: " + formatStr);
		}
	}
	VkSamplerMipmapMode Constants::stringToVkSamplerMipmapMode(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSamplerMipmapMode> formatMap = { {"VK_SAMPLER_MIPMAP_MODE_NEAREST", VK_SAMPLER_MIPMAP_MODE_NEAREST},
	{"VK_SAMPLER_MIPMAP_MODE_LINEAR", VK_SAMPLER_MIPMAP_MODE_LINEAR},
	{"VK_SAMPLER_MIPMAP_MODE_MAX_ENUM", VK_SAMPLER_MIPMAP_MODE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSamplerMipmapMode string: " + formatStr);
		}
	}
	VkSamplerReductionMode Constants::stringToVkSamplerReductionMode(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSamplerReductionMode> formatMap = { {"VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE", VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE},
	{"VK_SAMPLER_REDUCTION_MODE_MIN", VK_SAMPLER_REDUCTION_MODE_MIN},
	{"VK_SAMPLER_REDUCTION_MODE_MAX", VK_SAMPLER_REDUCTION_MODE_MAX},
	{"VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_EXT", VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_EXT},
	{"VK_SAMPLER_REDUCTION_MODE_MIN_EXT", VK_SAMPLER_REDUCTION_MODE_MIN_EXT},
	{"VK_SAMPLER_REDUCTION_MODE_MAX_EXT", VK_SAMPLER_REDUCTION_MODE_MAX_EXT},
	{"VK_SAMPLER_REDUCTION_MODE_MAX_ENUM", VK_SAMPLER_REDUCTION_MODE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSamplerReductionMode string: " + formatStr);
		}
	}
	VkSamplerYcbcrModelConversion Constants::stringToVkSamplerYcbcrModelConversion(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSamplerYcbcrModelConversion> formatMap = { {"VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY", VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY", VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709", VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601", VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020", VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY_KHR", VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY_KHR},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY_KHR", VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY_KHR},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709_KHR", VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709_KHR},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601_KHR", VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601_KHR},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020_KHR", VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020_KHR},
	{"VK_SAMPLER_YCBCR_MODEL_CONVERSION_MAX_ENUM", VK_SAMPLER_YCBCR_MODEL_CONVERSION_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSamplerYcbcrModelConversion string: " + formatStr);
		}
	}
	VkSamplerYcbcrRange Constants::stringToVkSamplerYcbcrRange(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSamplerYcbcrRange> formatMap = {
			  {"VK_SAMPLER_YCBCR_RANGE_ITU_FULL", VK_SAMPLER_YCBCR_RANGE_ITU_FULL},
	{"VK_SAMPLER_YCBCR_RANGE_ITU_NARROW", VK_SAMPLER_YCBCR_RANGE_ITU_NARROW},
	{"VK_SAMPLER_YCBCR_RANGE_ITU_FULL_KHR", VK_SAMPLER_YCBCR_RANGE_ITU_FULL_KHR},
	{"VK_SAMPLER_YCBCR_RANGE_ITU_NARROW_KHR", VK_SAMPLER_YCBCR_RANGE_ITU_NARROW_KHR},
	{"VK_SAMPLER_YCBCR_RANGE_MAX_ENUM", VK_SAMPLER_YCBCR_RANGE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSamplerYcbcrRange string: " + formatStr);
		}
	}

	VkSemaphoreImportFlagBits Constants::stringToVkSemaphoreImportFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSemaphoreImportFlagBits> formatMap = { {"VK_SEMAPHORE_IMPORT_TEMPORARY_BIT", VK_SEMAPHORE_IMPORT_TEMPORARY_BIT},
	{"VK_SEMAPHORE_IMPORT_TEMPORARY_BIT_KHR", VK_SEMAPHORE_IMPORT_TEMPORARY_BIT_KHR},
	{"VK_SEMAPHORE_IMPORT_FLAG_BITS_MAX_ENUM", VK_SEMAPHORE_IMPORT_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSemaphoreImportFlagBits string: " + formatStr);
		}
	}
	VkSemaphoreType Constants::stringToVkSemaphoreType(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSemaphoreType> formatMap = { {"VK_SEMAPHORE_TYPE_BINARY", VK_SEMAPHORE_TYPE_BINARY},
	{"VK_SEMAPHORE_TYPE_TIMELINE", VK_SEMAPHORE_TYPE_TIMELINE},
	{"VK_SEMAPHORE_TYPE_BINARY_KHR", VK_SEMAPHORE_TYPE_BINARY_KHR},
	{"VK_SEMAPHORE_TYPE_TIMELINE_KHR", VK_SEMAPHORE_TYPE_TIMELINE_KHR},
	{"VK_SEMAPHORE_TYPE_MAX_ENUM", VK_SEMAPHORE_TYPE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSemaphoreType string: " + formatStr);
		}
	}
	VkSemaphoreWaitFlagBits Constants::stringToVkSemaphoreWaitFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSemaphoreWaitFlagBits> formatMap = { {"VK_SEMAPHORE_WAIT_ANY_BIT", VK_SEMAPHORE_WAIT_ANY_BIT},
	{"VK_SEMAPHORE_WAIT_ANY_BIT_KHR", VK_SEMAPHORE_WAIT_ANY_BIT_KHR},
	{"VK_SEMAPHORE_WAIT_FLAG_BITS_MAX_ENUM", VK_SEMAPHORE_WAIT_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSemaphoreWaitFlagBits string: " + formatStr);
		}
	}

	VkShaderFloatControlsIndependence Constants::stringToVkShaderFloatControlsIndependence(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkShaderFloatControlsIndependence> formatMap = { {"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY", VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY},
	{"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL", VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL},
	{"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE", VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE},
	{"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY_KHR", VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY_KHR},
	{"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL_KHR", VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL_KHR},
	{"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE_KHR", VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE_KHR},
	{"VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_MAX_ENUM", VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkShaderFloatControlsIndependence string: " + formatStr);
		}
	}

	VkShaderStageFlagBits Constants::stringToVkShaderStageFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkShaderStageFlagBits> formatMap = { {"VK_SHADER_STAGE_VERTEX_BIT", VK_SHADER_STAGE_VERTEX_BIT},
	{"VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT", VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT},
	{"VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT", VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT},
	{"VK_SHADER_STAGE_GEOMETRY_BIT", VK_SHADER_STAGE_GEOMETRY_BIT},
	{"VK_SHADER_STAGE_FRAGMENT_BIT", VK_SHADER_STAGE_FRAGMENT_BIT},
	{"VK_SHADER_STAGE_COMPUTE_BIT", VK_SHADER_STAGE_COMPUTE_BIT},
	{"VK_SHADER_STAGE_ALL_GRAPHICS", VK_SHADER_STAGE_ALL_GRAPHICS},
	{"VK_SHADER_STAGE_ALL", VK_SHADER_STAGE_ALL},
	{"VK_SHADER_STAGE_RAYGEN_BIT_NV", VK_SHADER_STAGE_RAYGEN_BIT_NV},
	{"VK_SHADER_STAGE_ANY_HIT_BIT_NV", VK_SHADER_STAGE_ANY_HIT_BIT_NV},
	{"VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV", VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV},
	{"VK_SHADER_STAGE_MISS_BIT_NV", VK_SHADER_STAGE_MISS_BIT_NV},
	{"VK_SHADER_STAGE_INTERSECTION_BIT_NV", VK_SHADER_STAGE_INTERSECTION_BIT_NV},
	{"VK_SHADER_STAGE_CALLABLE_BIT_NV", VK_SHADER_STAGE_CALLABLE_BIT_NV},
	{"VK_SHADER_STAGE_TASK_BIT_NV", VK_SHADER_STAGE_TASK_BIT_NV},
	{"VK_SHADER_STAGE_MESH_BIT_NV", VK_SHADER_STAGE_MESH_BIT_NV},
	{"VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM", VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkShaderStageFlagBits string: " + formatStr);
		}
	}


	VkSharingMode Constants::stringToVkSharingMode(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSharingMode> formatMap = {
			   {"VK_SHARING_MODE_EXCLUSIVE", VK_SHARING_MODE_EXCLUSIVE},
	{"VK_SHARING_MODE_CONCURRENT", VK_SHARING_MODE_CONCURRENT},
	{"VK_SHARING_MODE_MAX_ENUM", VK_SHARING_MODE_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSharingMode string: " + formatStr);
		}
	}
	VkSparseImageFormatFlagBits Constants::stringToVkSparseImageFormatFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSparseImageFormatFlagBits> formatMap = { {"VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT", VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT},
	{"VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT", VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT},
	{"VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT", VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT},
	{"VK_SPARSE_IMAGE_FORMAT_FLAG_BITS_MAX_ENUM", VK_SPARSE_IMAGE_FORMAT_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSparseImageFormatFlagBits string: " + formatStr);
		}
	}
	VkSparseMemoryBindFlagBits Constants::stringToVkSparseMemoryBindFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSparseMemoryBindFlagBits> formatMap = { {"VK_SPARSE_MEMORY_BIND_METADATA_BIT", VK_SPARSE_MEMORY_BIND_METADATA_BIT},
	{"VK_SPARSE_MEMORY_BIND_FLAG_BITS_MAX_ENUM", VK_SPARSE_MEMORY_BIND_FLAG_BITS_MAX_ENUM}

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSparseMemoryBindFlagBits string: " + formatStr);
		}
	}
	VkStencilFaceFlagBits Constants::stringToVkStencilFaceFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkStencilFaceFlagBits> formatMap = { {"VK_STENCIL_FACE_FRONT_BIT", VK_STENCIL_FACE_FRONT_BIT},
	{"VK_STENCIL_FACE_BACK_BIT", VK_STENCIL_FACE_BACK_BIT},
	{"VK_STENCIL_FACE_FRONT_AND_BACK", VK_STENCIL_FACE_FRONT_AND_BACK},
	{"VK_STENCIL_FRONT_AND_BACK", VK_STENCIL_FRONT_AND_BACK},
	{"VK_STENCIL_FACE_FLAG_BITS_MAX_ENUM", VK_STENCIL_FACE_FLAG_BITS_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkStencilFaceFlagBits string: " + formatStr);
		}
	}
	VkStencilOp Constants::stringToVkStencilOp(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkStencilOp> formatMap = { {"VK_STENCIL_OP_KEEP", VK_STENCIL_OP_KEEP},
	{"VK_STENCIL_OP_ZERO", VK_STENCIL_OP_ZERO},
	{"VK_STENCIL_OP_REPLACE", VK_STENCIL_OP_REPLACE},
	{"VK_STENCIL_OP_INCREMENT_AND_CLAMP", VK_STENCIL_OP_INCREMENT_AND_CLAMP},
	{"VK_STENCIL_OP_DECREMENT_AND_CLAMP", VK_STENCIL_OP_DECREMENT_AND_CLAMP},
	{"VK_STENCIL_OP_INVERT", VK_STENCIL_OP_INVERT},
	{"VK_STENCIL_OP_INCREMENT_AND_WRAP", VK_STENCIL_OP_INCREMENT_AND_WRAP},
	{"VK_STENCIL_OP_DECREMENT_AND_WRAP", VK_STENCIL_OP_DECREMENT_AND_WRAP},
	{"VK_STENCIL_OP_MAX_ENUM", VK_STENCIL_OP_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkStencilOp string: " + formatStr);
		}
	}

	VkSubgroupFeatureFlagBits Constants::stringToVkSubgroupFeatureFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSubgroupFeatureFlagBits> formatMap = {
	{"VK_SUBGROUP_FEATURE_BASIC_BIT", VK_SUBGROUP_FEATURE_BASIC_BIT},
	{"VK_SUBGROUP_FEATURE_VOTE_BIT", VK_SUBGROUP_FEATURE_VOTE_BIT},
	{"VK_SUBGROUP_FEATURE_ARITHMETIC_BIT", VK_SUBGROUP_FEATURE_ARITHMETIC_BIT},
	{"VK_SUBGROUP_FEATURE_BALLOT_BIT", VK_SUBGROUP_FEATURE_BALLOT_BIT},
	{"VK_SUBGROUP_FEATURE_SHUFFLE_BIT", VK_SUBGROUP_FEATURE_SHUFFLE_BIT},
	{"VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT", VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT},
	{"VK_SUBGROUP_FEATURE_CLUSTERED_BIT", VK_SUBGROUP_FEATURE_CLUSTERED_BIT},
	{"VK_SUBGROUP_FEATURE_QUAD_BIT", VK_SUBGROUP_FEATURE_QUAD_BIT},
	{"VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV", VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV},
	{"VK_SUBGROUP_FEATURE_FLAG_BITS_MAX_ENUM", VK_SUBGROUP_FEATURE_FLAG_BITS_MAX_ENUM},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSubgroupFeatureFlagBits string: " + formatStr);
		}
	}
	VkSubpassContents Constants::stringToVkSubpassContents(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSubpassContents> formatMap = { { "VK_SUBPASS_CONTENTS_INLINE", VK_SUBPASS_CONTENTS_INLINE },
		{ "VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS", VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS },
		{ "VK_SUBPASS_CONTENTS_MAX_ENUM", VK_SUBPASS_CONTENTS_MAX_ENUM },

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSubpassContents string: " + formatStr);
		}
	}
	VkSubpassDescriptionFlagBits Constants::stringToVkSubpassDescriptionFlagBits(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSubpassDescriptionFlagBits> formatMap = { {"VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX", VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX},
	{"VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX", VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX},
	{"VK_SUBPASS_DESCRIPTION_FLAG_BITS_MAX_ENUM", VK_SUBPASS_DESCRIPTION_FLAG_BITS_MAX_ENUM},

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSubpassDescriptionFlagBits string: " + formatStr);
		}
	}
	VkSurfaceCounterFlagBitsEXT Constants::stringToVkSurfaceCounterFlagBitsEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSurfaceCounterFlagBitsEXT> formatMap = { {"VK_SURFACE_COUNTER_VBLANK_EXT", VK_SURFACE_COUNTER_VBLANK_EXT},
	{"VK_SURFACE_COUNTER_FLAG_BITS_MAX_ENUM_EXT", VK_SURFACE_COUNTER_FLAG_BITS_MAX_ENUM_EXT},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSurfaceCounterFlagBitsEXT string: " + formatStr);
		}
	}
	VkSurfaceTransformFlagBitsKHR Constants::stringToVkSurfaceTransformFlagBitsKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSurfaceTransformFlagBitsKHR> formatMap = { {"VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR", VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR},
	  {"VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR", VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR},
	{"VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR", VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR},
	{"VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR", VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR},
	{"VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR", VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR},
	{"VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR", VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR},
	{"VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR", VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR},
	{"VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR", VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR},
	{"VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR", VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR},
	{"VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR", VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR},

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSurfaceTransformFlagBitsKHR string: " + formatStr);
		}
	}
	VkSwapchainCreateFlagBitsKHR Constants::stringToVkSwapchainCreateFlagBitsKHR(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSwapchainCreateFlagBitsKHR> formatMap = {
			{"VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR", VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR},
	{"VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR", VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR},
	{"VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR", VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR},
	{"VK_SWAPCHAIN_CREATE_FLAG_BITS_MAX_ENUM_KHR", VK_SWAPCHAIN_CREATE_FLAG_BITS_MAX_ENUM_KHR},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSwapchainCreateFlagBitsKHR string: " + formatStr);
		}
	}


	VkSystemAllocationScope Constants::stringToVkSystemAllocationScope(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkSystemAllocationScope> formatMap = {
			   {"VK_SYSTEM_ALLOCATION_SCOPE_COMMAND", VK_SYSTEM_ALLOCATION_SCOPE_COMMAND},
	{"VK_SYSTEM_ALLOCATION_SCOPE_OBJECT", VK_SYSTEM_ALLOCATION_SCOPE_OBJECT},
	{"VK_SYSTEM_ALLOCATION_SCOPE_CACHE", VK_SYSTEM_ALLOCATION_SCOPE_CACHE},
	{"VK_SYSTEM_ALLOCATION_SCOPE_DEVICE", VK_SYSTEM_ALLOCATION_SCOPE_DEVICE},
	{"VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE", VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE},
	{"VK_SYSTEM_ALLOCATION_SCOPE_MAX_ENUM", VK_SYSTEM_ALLOCATION_SCOPE_MAX_ENUM},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkSystemAllocationScope string: " + formatStr);
		}
	}

	VkTessellationDomainOrigin Constants::stringToVkTessellationDomainOrigin(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkTessellationDomainOrigin> formatMap = {
	{"VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT", VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT},
	{"VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT", VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT},
	{"VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT_KHR", VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT_KHR},
	{"VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT_KHR", VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT_KHR},
	{"VK_TESSELLATION_DOMAIN_ORIGIN_MAX_ENUM", VK_TESSELLATION_DOMAIN_ORIGIN_MAX_ENUM},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkTessellationDomainOrigin string: " + formatStr);
		}
	}

	VkTimeDomainEXT Constants::stringToVkTimeDomainEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkTimeDomainEXT> formatMap = {
				 {"VK_TIME_DOMAIN_DEVICE_EXT", VK_TIME_DOMAIN_DEVICE_EXT},
	{"VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT", VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT},
	{"VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT", VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT},
	{"VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT", VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT},

		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkTimeDomainEXT string: " + formatStr);
		}
	}

	VkToolPurposeFlagBitsEXT Constants::stringToVkToolPurposeFlagBitsEXT(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkToolPurposeFlagBitsEXT> formatMap = { {"VK_TOOL_PURPOSE_VALIDATION_BIT_EXT", VK_TOOL_PURPOSE_VALIDATION_BIT_EXT},
	{"VK_TOOL_PURPOSE_PROFILING_BIT_EXT", VK_TOOL_PURPOSE_PROFILING_BIT_EXT},
	{"VK_TOOL_PURPOSE_TRACING_BIT_EXT", VK_TOOL_PURPOSE_TRACING_BIT_EXT},
	{"VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT_EXT", VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT_EXT},
	{"VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT_EXT", VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT_EXT},
	{"VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT", VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT},
	{"VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT", VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT},
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkToolPurposeFlagBitsEXT string: " + formatStr);
		}
	}



	VkVertexInputRate Constants::stringToVkVertexInputRate(const std::string& formatStr)
	{
		static std::unordered_map<std::string, VkVertexInputRate> formatMap = { {"VK_VERTEX_INPUT_RATE_VERTEX", VK_VERTEX_INPUT_RATE_VERTEX},
	{"VK_VERTEX_INPUT_RATE_INSTANCE", VK_VERTEX_INPUT_RATE_INSTANCE},
	{"VK_VERTEX_INPUT_RATE_MAX_ENUM", VK_VERTEX_INPUT_RATE_MAX_ENUM}
		};
		auto it = formatMap.find(formatStr);
		if (it != formatMap.end()) {
			return it->second;
		}
		else {
			throw std::runtime_error("Unrecognized VkVertexInputRate string: " + formatStr);
		}
	}

	*/
}
