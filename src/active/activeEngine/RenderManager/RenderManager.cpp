#include "RenderManager.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../../../external files/stb/stb_image_write.h"

namespace activeEngine {

	RenderManager::RenderManager(VulkanVariables* vulkanVariables) :var(vulkanVariables), resourceManager(vulkanVariables) {

	}

	std::vector<char> RenderManager::readShader(const std::string& filename)
	{
		std::string path = std::string(SOURCE_DIR) + "/src/active/activeShaders/compiled/" + filename;
		std::ifstream file(path, std::ios::ate | std::ios::binary);

		if (!file.is_open()) {
			throw std::runtime_error("failed to open file!");
		}

		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	VkShaderModule RenderManager::create_vkShaderModule(const std::string& filename)
	{
		std::string path = std::string(SOURCE_DIR) + "/src/active/activeShaders/compiled/" + filename;
		std::ifstream file(path, std::ios::ate | std::ios::binary);
		if (!file.is_open()) {
			throw std::runtime_error("failed to open file!");
		}
		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);
		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();

		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = buffer.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(buffer.data());  // The shader bytecode

		VkShaderModule shaderModule;
		// Create the shader module
		if (vkCreateShaderModule(*var->get_vkDevice(), &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("failed to create shader module!");
		}
		else {
			std::cout << "shader module created : " << filename << "\n";
		}

		return shaderModule;
	}

	void RenderManager::create_graphicsPipeline()
	{
		VkShaderModule computeShader = create_vkShaderModule("compute/final_output.comp.spv");
		VkShaderModule fragmentShader = create_vkShaderModule("fragment/final_output.frag.spv");
		VkShaderModule vertexShader = create_vkShaderModule("vertex/final_output.vert.spv");

		VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
		vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
		vertShaderStageInfo.module = vertexShader;
		vertShaderStageInfo.pName = "main";

		VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
		fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		fragShaderStageInfo.module = fragmentShader;
		fragShaderStageInfo.pName = "main";

		VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };


	}

	void RenderManager::create_finalShaders(
		VkShaderModule computeShader,
		VkShaderModule fragmentShader,
		VkShaderModule vertexShader)
	{
		VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
		vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
		vertShaderStageInfo.module = vertexShader;
		vertShaderStageInfo.pName = "main";
		VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
		fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		fragShaderStageInfo.module = fragmentShader;
		fragShaderStageInfo.pName = "main";
		VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };

		VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
		vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		vertexInputInfo.vertexBindingDescriptionCount = 0;
		vertexInputInfo.pVertexBindingDescriptions = nullptr; // Optional
		vertexInputInfo.vertexAttributeDescriptionCount = 0;
		vertexInputInfo.pVertexAttributeDescriptions = nullptr; // Optional

		VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
		inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		inputAssembly.primitiveRestartEnable = VK_FALSE;

		VkExtent2D swapChainExtent;
		// If the current extent is undefined, you can manually set it based on your window size
		int width, height;
		glfwGetFramebufferSize(var->get_window(), &width, &height);
		swapChainExtent.width = static_cast<uint32_t>(width);
		swapChainExtent.height = static_cast<uint32_t>(height);

		VkViewport viewport{};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = (float)swapChainExtent.width;
		viewport.height = (float)swapChainExtent.height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		VkRect2D scissor{};
		scissor.offset = { 0, 0 };
		scissor.extent = swapChainExtent;

		VkPipelineViewportStateCreateInfo viewportState{};
		viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewportState.viewportCount = 1;
		viewportState.pViewports = &viewport;
		viewportState.scissorCount = 1;
		viewportState.pScissors = &scissor;

		VkPipelineRasterizationStateCreateInfo rasterizer{};
		rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		rasterizer.depthClampEnable = VK_FALSE;
		rasterizer.lineWidth = 1.0f;
		rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
		rasterizer.frontFace = VK_FRONT_FACE_CLOCKWISE;
		rasterizer.depthBiasEnable = VK_FALSE;
		rasterizer.depthBiasConstantFactor = 0.0f; // Optional
		rasterizer.depthBiasClamp = 0.0f; // Optional
		rasterizer.depthBiasSlopeFactor = 0.0f; // Optional

		VkPipelineMultisampleStateCreateInfo multisampling{};
		multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisampling.sampleShadingEnable = VK_FALSE;
		multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
		multisampling.minSampleShading = 1.0f; // Optional
		multisampling.pSampleMask = nullptr; // Optional
		multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
		multisampling.alphaToOneEnable = VK_FALSE; // Optional

		VkPipelineColorBlendAttachmentState colorBlendAttachment{};
		colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
		colorBlendAttachment.blendEnable = VK_FALSE;
		colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
		colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
		colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD; // Optional
		colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
		colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
		colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD; // Optional

		VkPipelineColorBlendStateCreateInfo colorBlending{};
		colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		colorBlending.logicOpEnable = VK_FALSE;
		colorBlending.logicOp = VK_LOGIC_OP_COPY; // Optional
		colorBlending.attachmentCount = 1;
		colorBlending.pAttachments = &colorBlendAttachment;
		colorBlending.blendConstants[0] = 0.0f; // Optional
		colorBlending.blendConstants[1] = 0.0f; // Optional
		colorBlending.blendConstants[2] = 0.0f; // Optional
		colorBlending.blendConstants[3] = 0.0f; // Optional

		VkPipelineLayout pipelineLayout;

		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0; // Optional
		pipelineLayoutInfo.pSetLayouts = nullptr; // Optional
		pipelineLayoutInfo.pushConstantRangeCount = 0; // Optional
		pipelineLayoutInfo.pPushConstantRanges = nullptr; // Optional

		if (vkCreatePipelineLayout(*var->get_vkDevice(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("failed to create pipeline layout!");
		}
		else {
			std::cout << "pipeline layout created";
		}

		/*
		// Uniform Buffer for ImageSizeData
		VkDescriptorSetLayoutBinding uboLayoutBinding = {};
		uboLayoutBinding.binding = 0;
		uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		uboLayoutBinding.descriptorCount = 1;
		uboLayoutBinding.stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;
		uboLayoutBinding.pImmutableSamplers = nullptr;

		// Storage Buffer for inputColors[]
		VkDescriptorSetLayoutBinding ssboLayoutBinding = {};
		ssboLayoutBinding.binding = 1;
		ssboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		ssboLayoutBinding.descriptorCount = 1;
		ssboLayoutBinding.stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;
		ssboLayoutBinding.pImmutableSamplers = nullptr;

		// Image for outputImage
		VkDescriptorSetLayoutBinding imageLayoutBinding = {};
		imageLayoutBinding.binding = 2;
		imageLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
		imageLayoutBinding.descriptorCount = 1;
		imageLayoutBinding.stageFlags = VK_SHADER_STAGE_COMPUTE_BIT;
		imageLayoutBinding.pImmutableSamplers = nullptr;

		// Combine the bindings into a descriptor set layout
		std::array<VkDescriptorSetLayoutBinding, 3> bindings = { uboLayoutBinding, ssboLayoutBinding, imageLayoutBinding };
		VkDescriptorSetLayoutCreateInfo layoutInfo = {};
		layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
		layoutInfo.pBindings = bindings.data();

		VkDescriptorSetLayout descriptorSetLayout;
		if (vkCreateDescriptorSetLayout(*var->get_vkDevice(), &layoutInfo, nullptr, &descriptorSetLayout) != VK_SUCCESS) {
			std::cout << "failed to create descriptor set layout! \n";
		}
		else {
			std::cout << "Descriptor set layout created \n";
		}


		// Create the Pipeline Layout
		VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 1;  // One descriptor set layout
		pipelineLayoutInfo.pSetLayouts = &descriptorSetLayout;
		pipelineLayoutInfo.pushConstantRangeCount = 0;  // No push constants in this example

		VkPipelineLayout pipelineLayout;
		if (vkCreatePipelineLayout(*var->get_vkDevice(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			std::cout << "failed to create pipeline layout! \n";
		}
		else {
			std::cout << "pipeline layout created \n";
		}

		// Attach to the Compute Pipeline

		if (computeShader == VK_NULL_HANDLE) {
			std::cerr << "computeShader is null!" << std::endl;
			// Handle error (clean up and return)
		}
		else {
			std::cout << "NOt NULLL\n";
		}
		VkPipelineShaderStageCreateInfo shaderStageInfo = {};
		shaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		shaderStageInfo.stage = VK_SHADER_STAGE_COMPUTE_BIT;  // Specify this is a compute shader
		shaderStageInfo.module = computeShader;          // Your compiled compute shader module
		shaderStageInfo.pName = "main";                         // Entry point name in the shader


		VkComputePipelineCreateInfo computePipelineInfo = {};
		computePipelineInfo.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
		computePipelineInfo.stage = shaderStageInfo;  // Add your compute shader stage info
		computePipelineInfo.layout = pipelineLayout;


		VkPipeline computePipeline;
		if (vkCreateComputePipelines(*var->get_vkDevice(), VK_NULL_HANDLE, 1, &computePipelineInfo, nullptr, &computePipeline) != VK_SUCCESS) {
			std::cout << "failed to create compute pipeline! \n";
		}
		else {
			std::cout << "compute shader created \n";
		}
		*/

		/*
		VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
		vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		vertexInputInfo.vertexBindingDescriptionCount = 0;
		vertexInputInfo.pVertexBindingDescriptions = nullptr;
		vertexInputInfo.vertexAttributeDescriptionCount = 0;
		vertexInputInfo.pVertexAttributeDescriptions = nullptr;

		VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
		inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN; // To draw quad from 4 vertices
		inputAssembly.primitiveRestartEnable = VK_FALSE;

		VkExtent2D swapchainExtent;
		// If the current extent is undefined, you can manually set it based on your window size
		int width, height;
		glfwGetFramebufferSize(var->get_window(), &width, &height);
		swapchainExtent.width = static_cast<uint32_t>(width);
		swapchainExtent.height = static_cast<uint32_t>(height);

		VkViewport viewport{};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = (float)swapchainExtent.width;
		viewport.height = (float)swapchainExtent.height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		VkRect2D scissor{};
		scissor.offset = { 0, 0 };
		scissor.extent =swapchainExtent;

		VkPipelineViewportStateCreateInfo viewportState{};
		viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewportState.viewportCount = 1;
		viewportState.pViewports = &viewport;
		viewportState.scissorCount = 1;
		viewportState.pScissors = &scissor;

		VkPipelineRasterizationStateCreateInfo rasterizer{};
		rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		rasterizer.depthClampEnable = VK_FALSE;
		rasterizer.rasterizerDiscardEnable = VK_FALSE;
		rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
		rasterizer.lineWidth = 1.0f;
		rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
		rasterizer.frontFace = VK_FRONT_FACE_CLOCKWISE;
		rasterizer.depthBiasEnable = VK_FALSE;

		VkPipelineMultisampleStateCreateInfo multisampling{};
		multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisampling.sampleShadingEnable = VK_FALSE;
		multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

		VkPipelineColorBlendAttachmentState colorBlendAttachment{};
		colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
		colorBlendAttachment.blendEnable = VK_FALSE;

		VkPipelineColorBlendStateCreateInfo colorBlending{};
		colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		colorBlending.logicOpEnable = VK_FALSE;
		colorBlending.attachmentCount = 1;
		colorBlending.pAttachments = &colorBlendAttachment;

		VkPipelineLayoutCreateInfo pipelineLayoutInfo2{};
		pipelineLayoutInfo2.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo2.setLayoutCount = 0;
		pipelineLayoutInfo2.pSetLayouts = nullptr;
		pipelineLayoutInfo2.pushConstantRangeCount = 0;
		pipelineLayoutInfo2.pPushConstantRanges = nullptr;

		VkPipelineLayout pipelineLayout2;
		if (vkCreatePipelineLayout(*var->get_vkDevice(), &pipelineLayoutInfo2, nullptr, &pipelineLayout2) != VK_SUCCESS) {
			throw std::runtime_error("failed to create pipeline layout!");
		}


		// fragment shader
		VkDescriptorSetLayoutBinding samplerLayoutBinding{};
		samplerLayoutBinding.binding = 0;
		samplerLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		samplerLayoutBinding.descriptorCount = 1;
		samplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
		samplerLayoutBinding.pImmutableSamplers = nullptr; // Optional

		VkDescriptorSetLayoutCreateInfo layoutInfo{};
		layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		layoutInfo.bindingCount = 1;
		layoutInfo.pBindings = &samplerLayoutBinding;

		VkDescriptorSetLayout descriptorSetLayout;
		if (vkCreateDescriptorSetLayout(*var->get_vkDevice(), &layoutInfo, nullptr, &descriptorSetLayout) != VK_SUCCESS) {
			throw std::runtime_error("failed to create descriptor set layout!");
		}

		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 1; // Using one descriptor set layout
		pipelineLayoutInfo.pSetLayouts = &descriptorSetLayout;
		pipelineLayoutInfo.pushConstantRangeCount = 0; // No push constants

		VkPipelineLayout pipelineLayout;
		if (vkCreatePipelineLayout(*var->get_vkDevice(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("failed to create pipeline layout!");
		}
		VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
		fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		fragShaderStageInfo.module = fragmentShader; // Load SPIR-V module for fragment shader
		fragShaderStageInfo.pName = "main";

		// Assuming you also have a vertex shader, create similar VkPipelineShaderStageCreateInfo
		// for that and link both shader stages in the pipeline create info.

		VkGraphicsPipelineCreateInfo pipelineInfo2{};
		pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineInfo.stageCount = 2; // Vertex and fragment shader stages
		pipelineInfo.pStages = shaderStages; // Array with shader stage info

		// Setup other stages like input assembly, rasterization, color blending, etc.

		pipelineInfo.layout = pipelineLayout;

		if (vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &graphicsPipeline) != VK_SUCCESS) {
			throw std::runtime_error("failed to create graphics pipeline!");
		}

		VkDescriptorSetAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		allocInfo.descriptorPool = descriptorPool;
		allocInfo.descriptorSetCount = 1;
		allocInfo.pSetLayouts = &descriptorSetLayout;

		VkDescriptorSet descriptorSet;
		if (vkAllocateDescriptorSets(device, &allocInfo, &descriptorSet) != VK_SUCCESS) {
			throw std::runtime_error("failed to allocate descriptor set!");
		}

		VkDescriptorImageInfo imageInfo{};
		imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
		imageInfo.imageView = textureImageView; // Image view for your texture
		imageInfo.sampler = textureSampler;

		VkWriteDescriptorSet descriptorWrite{};
		descriptorWrite.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrite.dstSet = descriptorSet;
		descriptorWrite.dstBinding = 0;
		descriptorWrite.dstArrayElement = 0;
		descriptorWrite.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		descriptorWrite.descriptorCount = 1;
		descriptorWrite.pImageInfo = &imageInfo;

		vkUpdateDescriptorSets(device, 1, &descriptorWrite, 0, nullptr);
		*/
	}

	void RenderManager::draw() {}
	void RenderManager::updateMapChunks()
	{
	}
	void RenderManager::updateVulkanObjects()
	{
	}
	void RenderManager::updateGameFiles()
	{
	}

	void RenderManager::set_loadScreen()
	{

	}
	bool RenderManager::mainLoop() {
		return !glfwWindowShouldClose(var->get_window());
	}
	void RenderManager::begin() {
		glfwPollEvents();
	}
	void RenderManager::wait()
	{
		vkDeviceWaitIdle(*var->get_vkDevice());
	}
	void RenderManager::drawFrame()
	{
		//camera->update();
		draw();
	}
	void RenderManager::reset()
	{
	}
}





namespace activeEngine {
	Camera* RenderManager::camera = nullptr; // Definition within the namespace

	void RenderManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);  // Close window on ESC key press
		}

		if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
			std::cout << "W" << std::endl;
		}

		if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
			std::cout << "S" << std::endl;
		}

		if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
			std::cout << "A" << std::endl;
		}

		if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
			std::cout << "D" << std::endl;
		}
	}
	void RenderManager::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
			std::cout << "Left mouse button pressed" << std::endl;
		}
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
			std::cout << "Left mouse button released" << std::endl;
		}
		// Handle other buttons as needed
	}
	void RenderManager::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		//std::cout << "Mouse position: (" << xpos << ", " << ypos << ")" << std::endl;
		 // Calculate the offset from the last mouse position

		double xOffset = xpos - camera->lastX;
		double yOffset = camera->lastY - ypos; // Reversed since y-coordinates go from bottom to top

		// Update last position to the current one
		camera->lastX = xpos;
		camera->lastY = ypos;

		// Apply mouse sensitivity mouseSensitivity=0.1f
		xOffset *= 0.1f;
		yOffset *= 0.1f;

		// Rotate the camera by applying the offsets (yaw and pitch)
		glm::vec3 rotationDelta = glm::vec3(yOffset, xOffset, 0.0f); // Adjust X for pitch, Y for yaw
		camera->rotate(rotationDelta);

		// print camera matrix
	   // std::cout << "Rotation: (" << camera->rotation.x << ", "<< camera->rotation.y << ", " << camera->rotation.z << ")" << std::endl;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				std::cout << camera->matrices.view[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "\n\n";
	}

	void RenderManager::set_camera() {

		camera = new Camera();
		// set camera position x and y
		camera->setCamera(camera->CameraType::firstperson);
		// Set the key callback
		glfwSetKeyCallback(var->get_window(), keyCallback);
		// set mouse callback
		glfwSetMouseButtonCallback(var->get_window(), mouse_button_callback);
		// cursor
		glfwSetCursorPosCallback(var->get_window(), cursor_position_callback);
		// hide the cursor
		glfwSetInputMode(var->get_window(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}

	void randomPixelImage() {
		const int width = 1920;  // Full HD width
		const int height = 1080; // Full HD height
		const int channels = 3;   // RGB
		std::random_device rd;
		std::mt19937 gen(rd());  // Mersenne Twister engine
		// Define the distribution range
		for (int master = 0; master < 2; master++) {
			std::uniform_int_distribution<int> distrib(0, master + 1);
			std::vector<unsigned char> imageData(width * height * channels, 255);
			for (int j = 0; j < height; j++) {
				for (int i = 0; i < width; i++) {
					imageData[(j * width + i) * channels + 0] = distrib(gen); // Red
					imageData[(j * width + i) * channels + 1] = distrib(gen); // Green
					imageData[(j * width + i) * channels + 2] = distrib(gen); // Blue
				}
			}
			// Save the image as PNG
			std::string filename = "output" + std::to_string(master) + ".png";
			if (stbi_write_png(filename.c_str(), width, height, channels, imageData.data(), width * channels)) {
				std::cout << "Image saved as output2.png" << std::endl;
			}
			else {
				std::cerr << "Failed to save image" << std::endl;
			}
		}


	}
	void kucch(std::vector<glm::vec2> ff) {
		const int width = 1920;  // Full HD width
		const int height = 1080; // Full HD height
		const int channels = 3;   // RGB

		// Allocate memory for the image
		std::vector<unsigned char> imageData(width * height * channels, 255); // Initialize to white

		// Set pixel (960, 540) to black (RGB: 0, 0, 0)


		for (int i = 0; i < ff.size(); i++) {
			int x = ff[i].x;
			int y = ff[i].y;
			std::cout << x << ", " << y << std::endl;
			// Set the pixel color (for RGB)
			imageData[(y * width + x) * channels + 0] = 255; // Red
			imageData[(y * width + x) * channels + 1] = 0; // Green
			imageData[(y * width + x) * channels + 2] = 255; // Blue

			// Set the pixel color (for RGB)
			imageData[((y + 1) * width + x) * channels + 0] = 255; // Red
			imageData[((y + 1) * width + x) * channels + 1] = 0; // Green
			imageData[((y + 1) * width + x) * channels + 2] = 255; // Blue
			// Set the pixel color (for RGB)
			imageData[(y * width + (x + 1)) * channels + 0] = 255; // Red
			imageData[(y * width + (x + 1)) * channels + 1] = 0; // Green
			imageData[(y * width + (x + 1)) * channels + 2] = 255; // Blue
			// Set the pixel color (for RGB)
			imageData[((y + 1) * width + (x + 1)) * channels + 0] = 255; // Red
			imageData[((y + 1) * width + (x + 1)) * channels + 1] = 255; // Green
			imageData[((y + 1) * width + (x + 1)) * channels + 2] = 255; // Blue

			// Set the pixel color (for RGB)
			imageData[((y + 2) * width + x) * channels + 0] = 255; // Red
			imageData[((y + 2) * width + x) * channels + 1] = 0; // Green
			imageData[((y + 2) * width + x) * channels + 2] = 255; // Blue
			// Set the pixel color (for RGB)
			imageData[(y * width + (x + 2)) * channels + 0] = 255; // Red
			imageData[(y * width + (x + 2)) * channels + 1] = 0; // Green
			imageData[(y * width + (x + 2)) * channels + 2] = 255; // Blue
			// Set the pixel color (for RGB)
			imageData[((y + 2) * width + (x + 2)) * channels + 0] = 255; // Red
			imageData[((y + 2) * width + (x + 2)) * channels + 1] = 0; // Green
			imageData[((y + 2) * width + (x + 2)) * channels + 2] = 255; // Blue

			// Set the pixel color (for RGB)
			imageData[((y + 3) * width + x) * channels + 0] = 255; // Red
			imageData[((y + 3) * width + x) * channels + 1] = 0; // Green
			imageData[((y + 3) * width + x) * channels + 2] = 255; // Blue
			// Set the pixel color (for RGB)
			imageData[(y * width + (x + 3)) * channels + 0] = 255; // Red
			imageData[(y * width + (x + 3)) * channels + 1] = 0; // Green
			imageData[(y * width + (x + 3)) * channels + 2] = 255; // Blue
			// Set the pixel color (for RGB)
			imageData[((y + 3) * width + (x + 3)) * channels + 0] = 255; // Red
			imageData[((y + 3) * width + (x + 3)) * channels + 1] = 0; // Green
			imageData[((y + 3) * width + (x + 3)) * channels + 2] = 255; // Blue
		}
		// Save the image as PNG
		if (stbi_write_png("output.png", width, height, channels, imageData.data(), width * channels)) {
			std::cout << "Image saved as output.png" << std::endl;
		}
		else {
			std::cerr << "Failed to save image" << std::endl;
		}


	}
	void RenderManager::camera_object_distance(const glm::mat4& viewMatrix, const glm::vec3& worldPosition) {
		glm::mat4 inverseViewMatrix = glm::inverse(viewMatrix);  // Inverse of the view matrix
		glm::vec3 cameraPosition = glm::vec3(inverseViewMatrix[3]);  // Extract position

		glm::vec3 objectPosition = worldPosition;     // Get the object's position in world space

		// Calculate distance between the camera and the object
		float distance = glm::distance(cameraPosition, objectPosition);
	}

	glm::vec2 RenderManager::WorldToScreen(const glm::vec3& worldPosition,
		const glm::mat4& viewMatrix,
		const glm::mat4& projectionMatrix,
		float screenWidth,
		float screenHeight) {
		// 1. Convert to view space
		glm::vec4 viewPosition = viewMatrix * glm::vec4(worldPosition, 1.0f);
		// 2. Convert to clip space
		glm::vec4 clipPosition = projectionMatrix * viewPosition;
		if (clipPosition.w <= 0.0f) {
			std::cerr << "Warning: clipPosition.w is zero or negative, cannot project to screen" << std::endl;
			return glm::vec2(NAN, NAN);  // Return NaN or handle this case in another way
		}
		// 3. Normalize the clip space coordinates
		glm::vec3 ndcPosition = glm::vec3(clipPosition) / clipPosition.w;
		// 4. Convert NDC to screen coordinates
		float screenX = (ndcPosition.x + 1.0f) * 0.5f * screenWidth;
		float screenY = (1.0f - (ndcPosition.y + 1.0f) * 0.5f) * screenHeight; // Invert Y if needed

		return glm::vec2(screenX, screenY);
	}

	void RenderManager::setup() {
		resourceManager.setup();
		create_graphicsPipeline();

		camera = new Camera();
		// set camera position x and y
		camera->setCamera(camera->CameraType::lookat);
		camera->setPosition(glm::vec3(0.0f, 0.0f, -2.5f));
		camera->setRotation(glm::vec3(0.0f));
		camera->setPerspective(60.0f, (float)1920 / (float)1080, 1.0f, 256.0f);
		camera->updateMatricesIfNeeded();

		std::vector<glm::vec3> vertexData;

		vertexData.push_back(glm::vec3(1.0f, 1.0f, 0.0f));   // Center of the screen (z = 2.0)
		vertexData.push_back(glm::vec3(-1.0f, 1.0f, 0.0f));   // Top-right part of the screen (z = 2.0)
		vertexData.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				std::cout << camera->matrices.view[i][j] << " ";
			}
			std::cout << std::endl; // Newline after each row
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				std::cout << camera->matrices.perspective[i][j] << " ";
			}
			std::cout << std::endl; // Newline after each row
		}
		std::vector<glm::vec2> ff;
		for (int tt = 0; tt < vertexData.size(); tt++) {
			glm::vec2 onn = WorldToScreen(
				vertexData[tt],
				camera->matrices.view,
				camera->matrices.perspective,
				(float)1920,
				(float)1080
			);
			ff.push_back(onn);
			std::cout << "glm::vec2: (" << onn.x << ", " << onn.y << ")" << std::endl;
		}

		kucch(ff);

		randomPixelImage();

		//create_finalShaders(computeShader, fragmentShader, vertexShader);
		// Disable the cursor (locks the cursor in the window)
		//glfwSetInputMode(var->get_window(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	Camera* RenderManager::getCamera() {
		return camera;
	}

}
