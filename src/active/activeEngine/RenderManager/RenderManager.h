#pragma once 
#include "../../activeConstants/constants.h"
#include "../Camera/Camera.h"
#include "../VulkanVariables/VulkanVariables.h"
#include "../ResourceManager/ResourceManager.h"

namespace activeEngine {
	class RenderManager {
	private:
		VulkanVariables* var;
		ResourceManager	resourceManager;
	public:
		RenderManager(VulkanVariables* vulkanVariables);
	private:
		static Camera* camera;
	private: 
		std::vector<char> readShader(const std::string& filename);
		VkShaderModule create_vkShaderModule(const std::string& filename);
		
		void create_graphicsPipeline();
		void create_finalShaders(
			VkShaderModule computeShader,
			VkShaderModule fragmentShader,
			VkShaderModule vertexShader);

		void draw();
		void updateMapChunks();
		void updateVulkanObjects();
		void updateGameFiles();
		void set_camera();
		glm::vec2 WorldToScreen(const glm::vec3& worldPosition,
			const glm::mat4& viewMatrix,
			const glm::mat4& projectionMatrix,
			float screenWidth,
			float screenHeight);
		void camera_object_distance(const glm::mat4& viewMatrix, const glm::vec3& worldPosition);
	public:
		void set_loadScreen();
		bool mainLoop();
		void begin();
		void wait();
		void drawFrame();
		void reset();
		void setup();
	private:
		// input
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	public:
		Camera* getCamera();
	};
}