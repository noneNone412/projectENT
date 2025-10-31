#pragma once
#include "../passiveConstants/constants.h"

namespace passiveEngine {
	class instruction_reader {};
	class VulkanVariables {};

	class SetupManager :private instruction_reader {
	private:
		VulkanVariables* var;
	public:
		SetupManager(VulkanVariables* variables);
	};

	class RenderManager :private instruction_reader {
	private:
		VulkanVariables* var;
	public:
		RenderManager(VulkanVariables* variables);
	};

	class ResourceManager :private instruction_reader {
	private:
		VulkanVariables* var;
	public:
		ResourceManager(VulkanVariables* variables);
	};

	class Engine {
	private:
		SetupManager setupManager;
		ResourceManager resourceManager;
		RenderManager renderManager;
	public:
		Engine(VulkanVariables *variables);
	};
}