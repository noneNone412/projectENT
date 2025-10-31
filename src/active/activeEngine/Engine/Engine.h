#pragma once 
#include "../SetupManager/SetupManager.h"
#include "../RenderManager/RenderManager.h"
#include "../VulkanVariables/VulkanVariables.h"


namespace activeEngine {
	struct stage_0 {
		VkDescriptorSet descriptorSet;
		VkPipeline pipeline;

	};
	struct stage_1 {
	};
	struct stage_2 {
	};
	struct stage_n {
		VkDescriptorSet descriptorSet;
		VkPipeline pipeline[2];
	};

	class Engine {
	private:
		SetupManager setupManager;
		RenderManager renderManager;
	public:
		Engine(VulkanVariables* variables);
	private:
		float deltaTime=0;
		double lastFrameTime=0;
	private:
		void update_time();
		void draw();
		void updateMapChunks();
		void updateVulkanObjects();
		void updateGameFiles();
		void set_loadingScreen();
		void drawFrame();
		void reset();
	public:
		void start();
		void run();
		void stop();
	};
}