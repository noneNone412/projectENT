#include "SetupManager.h"

namespace activeEngine {
	SetupManager::SetupManager(VulkanVariables* variables) :var(variables) {}




	void  SetupManager::set_vkDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessengerCreateInfoEXT& vkDebugUtilsMessengerCreateInfoEXT)
	{
		vkDebugUtilsMessengerCreateInfoEXT.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		vkDebugUtilsMessengerCreateInfoEXT.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		vkDebugUtilsMessengerCreateInfoEXT.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		vkDebugUtilsMessengerCreateInfoEXT.pfnUserCallback = debugCallback;
		vkDebugUtilsMessengerCreateInfoEXT.pUserData = nullptr; // Optional
	}

	void SetupManager::set_vkAllocationCallbacks(VkAllocationCallbacks& allocationCallbacks)
	{
		allocationCallbacks.pUserData = nullptr;  // Optional user data, can be null or a pointer to a tracking structure
		allocationCallbacks.pfnAllocation = customAlloc;
		allocationCallbacks.pfnReallocation = customRealloc;
		allocationCallbacks.pfnFree = customFree;
		allocationCallbacks.pfnInternalAllocation = nullptr;  // Optional, used for internal allocations tracking
		allocationCallbacks.pfnInternalFree = nullptr;  // Optional, used for internal free tracking
	}

	static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
		auto app = reinterpret_cast<SetupManager*>(glfwGetWindowUserPointer(window));
		app->framebufferResized = true;
		std::cout << "resized \n";

	}

	void SetupManager::create_glfwWindow(int WIDTH, int HEIGHT)
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		var->set_window(glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr));

		glfwSetWindowUserPointer(var->get_window(), this);
		glfwSetFramebufferSizeCallback(var->get_window(), framebufferResizeCallback);
		std::cout << "opened" << std::endl;
	}

	void SetupManager::enumerate_instanceExt()
	{
		// Fetch the number of extensions available
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		// Allocate space for extension details
		std::vector<VkExtensionProperties> extensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

		// List the extensions
		std::cout << "Available instance extensions:\n";
		for (const auto& extension : extensions) {
			std::cout << "\t" << extension.extensionName << " (version " << extension.specVersion << ")\n";
		}

	}

	bool SetupManager::check_vkInstanceExtensions()
	{

		return true;
	}

	void SetupManager::create_vkInstance()
	{
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_3;

		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;


		// add instance extensions
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
		std::vector<const char*> instance_extension(glfwExtensions, glfwExtensions + glfwExtensionCount);
		instance_extension.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

		createInfo.enabledExtensionCount = static_cast<uint32_t>(instance_extension.size());
		createInfo.ppEnabledExtensionNames = instance_extension.data();
		// setup custom memory allocator
		//var->set_vkAllocationCallbacks();
		// setup debug layer
		VkDebugUtilsMessengerCreateInfoEXT vkDebugUtilsMessengerCreateInfoEXT{};
		set_vkDebugUtilsMessengerCreateInfoEXT(vkDebugUtilsMessengerCreateInfoEXT);


		const std::vector<const char*> valiadation_extensions = { "VK_LAYER_KHRONOS_validation" };

		createInfo.enabledLayerCount = static_cast<uint32_t>(valiadation_extensions.size());
		createInfo.ppEnabledLayerNames = valiadation_extensions.data();
		createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&vkDebugUtilsMessengerCreateInfoEXT;


		set_vkAllocationCallbacks(*var->get_vkAllocationCallbacks());

		if (vkCreateInstance(&createInfo, var->get_vkAllocationCallbacks(), var->get_vkInstance()) != VK_SUCCESS) {
			throw std::runtime_error("failed to create instance!");
		}
		else {
			std::cout << "instance created\n";
		}

	}


	void SetupManager::setup_vkDebugLayer()
	{

		auto createDebugUtilsMessenger = reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(
			vkGetInstanceProcAddr(*var->get_vkInstance(), "vkCreateDebugUtilsMessengerEXT"));

		if (createDebugUtilsMessenger != nullptr) {
			VkDebugUtilsMessengerCreateInfoEXT vkDebugUtilsMessengerCreateInfoEXT{};
			set_vkDebugUtilsMessengerCreateInfoEXT(vkDebugUtilsMessengerCreateInfoEXT);
			if (createDebugUtilsMessenger(*var->get_vkInstance(), &vkDebugUtilsMessengerCreateInfoEXT, var->get_vkAllocationCallbacks(), &debugMessenger) != VK_SUCCESS) {
				std::cerr << "Failed to set up debug messenger!" << std::endl;
			}
			else {
				std::cout << "Debug messenger created!\n";
			}
		}



	}

	void SetupManager::create_vkSurface() {
		VkSurfaceKHR surface;
		if (glfwCreateWindowSurface(*var->get_vkInstance(), var->get_window(), var->get_vkAllocationCallbacks(), var->get_vkSurface()) != VK_SUCCESS) {
			std::cout << "surface created\n";
		}
	}

	void SetupManager::pick_vkPhysicalDevice() {
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(*var->get_vkInstance(), &deviceCount, nullptr);

		if (deviceCount == 0) {
			throw std::runtime_error("failed to find GPUs with Vulkan support!");
		}
		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(*var->get_vkInstance(), &deviceCount, devices.data());

		uint32_t extensionCount = 0;
		for (VkPhysicalDevice& device : devices) {
			uint32_t extensionCount2 = 0;
			vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount2, nullptr);
			if (extensionCount < extensionCount2) {
				extensionCount = extensionCount2;
				var->set_vkPhysicalDevice(device);
			}
		}
	}

	void SetupManager::enumerate_vkQueues() {
		uint32_t queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(var->get_vkPhysicalDevice(), &queueFamilyCount, nullptr);
		std::cout << "queueFamilyCount " << queueFamilyCount << "\n\n";
		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(var->get_vkPhysicalDevice(), &queueFamilyCount, queueFamilies.data());

		std::sort(queueFamilies.begin(), queueFamilies.end(), [](const VkQueueFamilyProperties& a, const VkQueueFamilyProperties& b) {
			return a.queueCount > b.queueCount; // Descending order
			});


		for (size_t i = 0; i < queueFamilies.size(); ++i) {
			std::cout << "Queue Family " << i << ":\n";
			std::cout << "  Queue Count: " << queueFamilies[i].queueCount << "\n";

			std::cout << "  Supported Operations: ";
			if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
				std::cout << "Graphics ";
			}
			if (queueFamilies[i].queueFlags & VK_QUEUE_COMPUTE_BIT) {
				std::cout << "Compute ";
			}
			if (queueFamilies[i].queueFlags & VK_QUEUE_TRANSFER_BIT) {
				std::cout << "Transfer ";
			}
			if (queueFamilies[i].queueFlags & VK_QUEUE_SPARSE_BINDING_BIT) {
				std::cout << "Sparse Binding ";
			}
			std::cout << "\n";

			std::cout << "  Timestamp Valid Bits: " << queueFamilies[i].timestampValidBits << "\n";
			std::cout << "  Min Image Transfer Granularity: "
				<< queueFamilies[i].minImageTransferGranularity.width << " x "
				<< queueFamilies[i].minImageTransferGranularity.height << " x "
				<< queueFamilies[i].minImageTransferGranularity.depth << "\n";
			std::cout << std::endl;
		}
	}

	void SetupManager::enumerate_vkDeviceExtensions() {
		uint32_t extensionCount = 0;
		vkEnumerateDeviceExtensionProperties(var->get_vkPhysicalDevice(), nullptr, &extensionCount, nullptr);

		// Allocate a vector to hold extension properties
		std::vector<VkExtensionProperties> extensions(extensionCount);

		// Query the actual extension properties
		vkEnumerateDeviceExtensionProperties(var->get_vkPhysicalDevice(), nullptr, &extensionCount, extensions.data());

		// Print out the available extensions
		std::cout << "Available device extensions:\n";
		for (const auto& extension : extensions) {
			std::cout << "\t" << extension.extensionName << " (Version: " << extension.specVersion << ")\n";
		}
	}

	void SetupManager::enumerate_vkDeviceFeatures()
	{
		VkPhysicalDeviceFeatures features;
		vkGetPhysicalDeviceFeatures(var->get_vkPhysicalDevice(), &features);

		std::cout << "Device Features:" << std::endl;

		std::cout << "  robustBufferAccess: " << (features.robustBufferAccess ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  fullDrawIndexUint32: " << (features.fullDrawIndexUint32 ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  imageCubeArray: " << (features.imageCubeArray ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  independentBlend: " << (features.independentBlend ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  geometryShader: " << (features.geometryShader ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  tessellationShader: " << (features.tessellationShader ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  sampleRateShading: " << (features.sampleRateShading ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  dualSrcBlend: " << (features.dualSrcBlend ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  logicOp: " << (features.logicOp ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  multiDrawIndirect: " << (features.multiDrawIndirect ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  drawIndirectFirstInstance: " << (features.drawIndirectFirstInstance ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  depthClamp: " << (features.depthClamp ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  depthBiasClamp: " << (features.depthBiasClamp ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  fillModeNonSolid: " << (features.fillModeNonSolid ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  depthBounds: " << (features.depthBounds ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  wideLines: " << (features.wideLines ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  largePoints: " << (features.largePoints ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  alphaToOne: " << (features.alphaToOne ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  multiViewport: " << (features.multiViewport ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  samplerAnisotropy: " << (features.samplerAnisotropy ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  textureCompressionETC2: " << (features.textureCompressionETC2 ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  textureCompressionASTC_LDR: " << (features.textureCompressionASTC_LDR ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  textureCompressionBC: " << (features.textureCompressionBC ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  occlusionQueryPrecise: " << (features.occlusionQueryPrecise ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  pipelineStatisticsQuery: " << (features.pipelineStatisticsQuery ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  vertexPipelineStoresAndAtomics: " << (features.vertexPipelineStoresAndAtomics ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  fragmentStoresAndAtomics: " << (features.fragmentStoresAndAtomics ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderTessellationAndGeometryPointSize: " << (features.shaderTessellationAndGeometryPointSize ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderImageGatherExtended: " << (features.shaderImageGatherExtended ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderStorageImageExtendedFormats: " << (features.shaderStorageImageExtendedFormats ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderStorageImageMultisample: " << (features.shaderStorageImageMultisample ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderStorageImageReadWithoutFormat: " << (features.shaderStorageImageReadWithoutFormat ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderStorageImageWriteWithoutFormat: " << (features.shaderStorageImageWriteWithoutFormat ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderUniformBufferArrayDynamicIndexing: " << (features.shaderUniformBufferArrayDynamicIndexing ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderSampledImageArrayDynamicIndexing: " << (features.shaderSampledImageArrayDynamicIndexing ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderStorageBufferArrayDynamicIndexing: " << (features.shaderStorageBufferArrayDynamicIndexing ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderStorageImageArrayDynamicIndexing: " << (features.shaderStorageImageArrayDynamicIndexing ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderClipDistance: " << (features.shaderClipDistance ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderCullDistance: " << (features.shaderCullDistance ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderFloat64: " << (features.shaderFloat64 ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderInt64: " << (features.shaderInt64 ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  shaderInt16: " << (features.shaderInt16 ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  sparseBinding: " << (features.sparseBinding ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  sparseResidencyBuffer: " << (features.sparseResidencyBuffer ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  sparseResidencyImage2D: " << (features.sparseResidencyImage2D ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  sparseResidencyImage3D: " << (features.sparseResidencyImage3D ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  sparseResidencyAliased: " << (features.sparseResidencyAliased ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  variableMultisampleRate: " << (features.variableMultisampleRate ? "Supported" : "Not Supported") << std::endl;
		std::cout << "  inheritedQueries: " << (features.inheritedQueries ? "Supported" : "Not Supported") << std::endl;

	}

	void SetupManager::create_vkLogicalDevice() {
		std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
		uint32_t queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(var->get_vkPhysicalDevice(), &queueFamilyCount, nullptr);
		std::cout << "queueFamilyCount " << queueFamilyCount << "\n\n";
		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(var->get_vkPhysicalDevice(), &queueFamilyCount, queueFamilies.data());

		float queuePriorityGap = 1.0f / static_cast<float>(queueFamilies.size());
		float queuePriority_ = 1.0f;
		//std::vector<float> queuePriorities(queueFamilies.size());

		size_t totalQueueCount = 0;
		for (const auto& family : queueFamilies) {
			totalQueueCount += family.queueCount;
		}

		// Resize the queuePriorities vector
		std::vector<float> queuePriorities(totalQueueCount);
		size_t priorityIndex = 0;

		// Assign priorities based on the queue families' index
		for (size_t i = 0; i < queueFamilies.size(); ++i) {
			for (size_t j = 0; j < queueFamilies[i].queueCount; ++j) {
				queuePriorities[priorityIndex++] = queuePriority_; // Assign the same priority to each queue
			}
			queuePriority_ -= queuePriorityGap; // Decrease for the next family
		}
		priorityIndex = 0; // Reset index for queueCreateInfos
		for (size_t i = 0; i < queueFamilies.size(); ++i) {
			VkDeviceQueueCreateInfo queueCreateInfo = {};
			queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueCreateInfo.queueFamilyIndex = i;
			queueCreateInfo.queueCount = queueFamilies[i].queueCount;
			queueCreateInfo.pQueuePriorities = &queuePriorities[priorityIndex]; // Point to the start of the priorities for this queue family

			queueCreateInfos.push_back(queueCreateInfo); // Store each queue create info in the vector
			priorityIndex += queueFamilies[i].queueCount; // Move the index forward for the next family
		}

		// Define physical device features (optional)
		VkPhysicalDeviceFeatures deviceFeatures = {}; // Initialize to zero or set desired features

		// Set up the logical device creation info
		VkDeviceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

		const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
		createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
		createInfo.ppEnabledExtensionNames = deviceExtensions.data();

		createInfo.pQueueCreateInfos = queueCreateInfos.data();
		createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
		createInfo.pEnabledFeatures = &deviceFeatures; // Pointer to device features

		// Create the logical device
		if (vkCreateDevice(var->get_vkPhysicalDevice(), &createInfo, nullptr, var->get_vkDevice()) != VK_SUCCESS) {
			throw std::runtime_error("failed to create logical device!");
		}
		else {
			std::cout << "logical device created\n";
		}

	}

	void SetupManager::enumerate_swapChainCapabilities() {

		// Query capabilities
		VkSurfaceCapabilitiesKHR capabilities;
		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &capabilities);

		// Query formats
		std::vector<VkSurfaceFormatKHR> formats;
		uint32_t formatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &formatCount, nullptr);
		if (formatCount != 0) {
			formats.resize(formatCount);
			vkGetPhysicalDeviceSurfaceFormatsKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &formatCount, formats.data());
		}

		// Query present modes
		std::vector<VkPresentModeKHR> presentModes;
		uint32_t presentModeCount;
		vkGetPhysicalDeviceSurfacePresentModesKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &presentModeCount, nullptr);
		if (presentModeCount != 0) {
			presentModes.resize(presentModeCount);
			vkGetPhysicalDeviceSurfacePresentModesKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &presentModeCount, presentModes.data());
		}

		std::cout << "Surface Capabilities:\n";
		std::cout << "  Min Image Count: " << capabilities.minImageCount << "\n";
		std::cout << "  Max Image Count: " << capabilities.maxImageCount << "\n";
		std::cout << "  CurrentExtent: " << capabilities.currentExtent.width << "x"
			<< capabilities.currentExtent.height << "\n";
		std::cout << "  Min Extent: " << capabilities.minImageExtent.width << "x"
			<< capabilities.minImageExtent.height << "\n";
		std::cout << "  Max Extent: " << capabilities.maxImageExtent.width << "x"
			<< capabilities.maxImageExtent.height << "\n";
		std::cout << "  Max Image Array Layers: " << capabilities.maxImageArrayLayers << "\n";
		std::cout << "  Supported Transforms: " << capabilities.currentTransform << "\n";
		std::cout << "  Supported Composite Alpha: " << capabilities.supportedCompositeAlpha << "\n";
		std::cout << "  Supported Usage Flags: " << capabilities.supportedUsageFlags << "\n";

		// Print surface formats
		std::cout << "Supported Surface Formats:\n";
		for (const auto& format : formats) {
			switch (format.format) {
			case VK_FORMAT_B8G8R8A8_SRGB: std::cout << "  Format: " << "VK_FORMAT_B8G8R8A8_SRGB\n";
			case VK_FORMAT_R8G8B8A8_SRGB: std::cout << "  Format: " << "VK_FORMAT_R8G8B8A8_SRGB\n";
				// Add other relevant formats here
			default: std::cout << "  Format: " << "Unknown Format (" + std::to_string(format.format) + ")\n";
			}
			switch (format.colorSpace) {
			case VK_COLOR_SPACE_SRGB_NONLINEAR_KHR: std::cout << "VK_COLOR_SPACE_SRGB_NONLINEAR_KHR\n";
				// Add other relevant color spaces here
			default:  std::cout << "Unknown Color Space (" + std::to_string(format.colorSpace) + ")\n";
			}
		}
		// Print present modes
		std::cout << "Supported Present Modes:\n";
		for (const auto& presentMode : presentModes) {
			switch (presentMode) {
			case VK_PRESENT_MODE_IMMEDIATE_KHR: std::cout << "VK_PRESENT_MODE_IMMEDIATE_KHR\n";
			case VK_PRESENT_MODE_MAILBOX_KHR: std::cout << "VK_PRESENT_MODE_MAILBOX_KHR\n";
			case VK_PRESENT_MODE_FIFO_KHR: std::cout << "VK_PRESENT_MODE_FIFO_KHR\n";
			case VK_PRESENT_MODE_FIFO_RELAXED_KHR: std::cout << "VK_PRESENT_MODE_FIFO_RELAXED_KHR\n";
			default: std::cout << "Unknown Present Mode (" + std::to_string(presentMode) + ")\n";
			}
		}
	}

	void SetupManager::create_vkSwapchain() {

		VkSurfaceFormatKHR surfaceFormat;
		VkPresentModeKHR presentMode;

		// Query capabilities
		VkSurfaceCapabilitiesKHR capabilities;
		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &capabilities);

		int width, height;
		glfwGetFramebufferSize(var->get_window(), &width, &height);
		VkExtent2D swapChainExtent = {
				static_cast<uint32_t>(width),
				static_cast<uint32_t>(height)
		};
		swapChainExtent.width = std::clamp(swapChainExtent.width, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
		swapChainExtent.height = std::clamp(swapChainExtent.height, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);

		var->set_vkExtent2D(swapChainExtent);
		// Query formats

		std::vector<VkSurfaceFormatKHR> formats;
		uint32_t formatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &formatCount, nullptr);
		if (formatCount != 0) {
			formats.resize(formatCount);
			vkGetPhysicalDeviceSurfaceFormatsKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &formatCount, formats.data());
		}
		for (const auto& format : formats) {
			if (format.format == VK_FORMAT_B8G8R8A8_SRGB && format.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
				surfaceFormat = format; // Return this format if available
			}
		}
		var->set_vkSurfaceFormat(surfaceFormat);

		// Query present modes
		std::vector<VkPresentModeKHR> presentModes;
		uint32_t presentModeCount;
		vkGetPhysicalDeviceSurfacePresentModesKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &presentModeCount, nullptr);
		if (presentModeCount != 0) {
			presentModes.resize(presentModeCount);
			vkGetPhysicalDeviceSurfacePresentModesKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &presentModeCount, presentModes.data());
		}
		for (const auto& mode : presentModes) {
			if (mode == VK_PRESENT_MODE_FIFO_KHR) {
				presentMode = mode; // FIFO is the default and safest choice
			}
		}
		// Step 2: Create the swap chain
		uint32_t imageCount = capabilities.minImageCount + 1;
		if (capabilities.maxImageCount > 0 && imageCount > capabilities.maxImageCount) {
			imageCount = capabilities.maxImageCount;
		}

		VkSwapchainCreateInfoKHR swapChainInfo = {};
		swapChainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapChainInfo.surface = *var->get_vkSurface();
		swapChainInfo.minImageCount = imageCount;
		swapChainInfo.imageFormat = surfaceFormat.format;
		swapChainInfo.imageColorSpace = surfaceFormat.colorSpace;
		swapChainInfo.imageExtent = swapChainExtent;
		swapChainInfo.imageArrayLayers = 1;
		swapChainInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

		// Step 3: Queue Family Indices
		uint32_t graphicsFamily = 0;
		uint32_t presentFamily = 0;

		std::vector<uint32_t> queueFamilyIndices = { graphicsFamily, presentFamily }; // Replace with your actual indices
		if (graphicsFamily != presentFamily) {
			swapChainInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
			swapChainInfo.queueFamilyIndexCount = static_cast<uint32_t>(queueFamilyIndices.size());
			swapChainInfo.pQueueFamilyIndices = queueFamilyIndices.data();
		}
		else {
			swapChainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
			swapChainInfo.queueFamilyIndexCount = 0; // Optional
			swapChainInfo.pQueueFamilyIndices = nullptr; // Optional
		}

		// Step 4: Specify pre-transform and composite alpha
		swapChainInfo.preTransform = capabilities.currentTransform;
		swapChainInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR; // Opaque background
		swapChainInfo.presentMode = presentMode;
		swapChainInfo.clipped = VK_TRUE;
		swapChainInfo.oldSwapchain = VK_NULL_HANDLE; // For the initial creation

		// Step 5: Create the swap chain
		if (vkCreateSwapchainKHR(*var->get_vkDevice(), &swapChainInfo, var->get_vkAllocationCallbacks(), var->get_vkSwapchainKHR()) != VK_SUCCESS) {
			throw std::runtime_error("failed to create swap chain!");
		}
		else {
			std::cout << "swapchain created " << var->get_vkSwapchainKHR() << "\n";
		}

	}

	void SetupManager::create_vkImageViews() {
		// Declare the vector to hold swap chain images
		std::vector<VkImage> swapChainImages;

		// After creating the swap chain
		uint32_t imageCount;

		// Step 1: Get the number of swap chain images
		vkGetSwapchainImagesKHR(*var->get_vkDevice(), *var->get_vkSwapchainKHR(), &imageCount, nullptr); // First call to get the count
		swapChainImages.resize(imageCount); // Resize the vector to hold the images

		// Step 2: Retrieve the actual swap chain images
		if (vkGetSwapchainImagesKHR(*var->get_vkDevice(), *var->get_vkSwapchainKHR(), &imageCount, swapChainImages.data()) != VK_SUCCESS) {
			throw std::runtime_error("failed to get swap chain images!");
		}

		var->resize_swapChainImageViews(swapChainImages.size());
		for (size_t i = 0; i < swapChainImages.size(); i++) {
			VkImageViewCreateInfo viewInfo = {};
			viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
			viewInfo.image = swapChainImages[i];
			viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
			viewInfo.format = VK_FORMAT_B8G8R8A8_SRGB;
			viewInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
			viewInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
			viewInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
			viewInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;

			viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
			viewInfo.subresourceRange.baseMipLevel = 0;
			viewInfo.subresourceRange.levelCount = 1; // No mipmaps for swap chain images
			viewInfo.subresourceRange.baseArrayLayer = 0;
			viewInfo.subresourceRange.layerCount = 1; // 2D image

			if (vkCreateImageView(*var->get_vkDevice(), &viewInfo, var->get_vkAllocationCallbacks(), &var->get_swapChainImageViews()[i]) != VK_SUCCESS) {
				throw std::runtime_error("failed to create image view!");
			}
			else {
				std::cout << "ImageView created " << var->get_swapChainImageViews()[i] << "\n";
			}
		}
	}

	void SetupManager::iterateMemoryType() {
		VkPhysicalDeviceMemoryProperties memProperties;
		vkGetPhysicalDeviceMemoryProperties(var->get_vkPhysicalDevice(), &memProperties);

		std::cout << "Memory Types:" << std::endl;
		for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
			VkMemoryType memoryType = memProperties.memoryTypes[i];
			std::cout << "Memory Type " << i << ": " << std::endl;
			std::cout << "  Heap Index: " << memoryType.heapIndex << std::endl;
			std::cout << "  Property Flags: " << memoryType.propertyFlags << std::endl;
		}

		std::cout << "Memory Heaps:" << std::endl;
		for (uint32_t i = 0; i < memProperties.memoryHeapCount; i++) {
			VkMemoryHeap memoryHeap = memProperties.memoryHeaps[i];
			std::cout << "Memory Heap " << i << ": " << std::endl;
			std::cout << "  Size: " << memoryHeap.size / (1024 * 1024) << " MB" << std::endl;
			std::cout << "  Flags: " << memoryHeap.flags << std::endl;
		}
	}
	void SetupManager::create_vkRenderPass() {
		VkSurfaceFormatKHR surfaceFormat;
		std::vector<VkSurfaceFormatKHR> formats;
		uint32_t formatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &formatCount, nullptr);
		if (formatCount != 0) {
			formats.resize(formatCount);
			vkGetPhysicalDeviceSurfaceFormatsKHR(var->get_vkPhysicalDevice(), *var->get_vkSurface(), &formatCount, formats.data());
		}
		for (const auto& format : formats) {
			if (format.format == VK_FORMAT_B8G8R8A8_SRGB && format.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
				surfaceFormat = format; // Return this format if available
			}
		}

		VkAttachmentDescription colorAttachment{};
		colorAttachment.format = surfaceFormat.format;
		colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
		colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
		colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
		colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

		VkAttachmentReference colorAttachmentRef{};
		colorAttachmentRef.attachment = 0;
		colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

		VkSubpassDescription subpass{};
		subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
		subpass.colorAttachmentCount = 1;
		subpass.pColorAttachments = &colorAttachmentRef;

		VkSubpassDependency dependency{};
		dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
		dependency.dstSubpass = 0;
		dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		dependency.srcAccessMask = 0;
		dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

		VkRenderPassCreateInfo renderPassInfo{};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		renderPassInfo.attachmentCount = 1;
		renderPassInfo.pAttachments = &colorAttachment;
		renderPassInfo.subpassCount = 1;
		renderPassInfo.pSubpasses = &subpass;
		renderPassInfo.dependencyCount = 1;
		renderPassInfo.pDependencies = &dependency;

		if (vkCreateRenderPass(*var->get_vkDevice(), &renderPassInfo, nullptr, &var->get_vkRenderPass()) != VK_SUCCESS) {
			throw std::runtime_error("failed to create render pass!");
		}
		else {
			std::cout << "RenderPass created!\n";
		}
	}

	void SetupManager::create_vkFramebuffer()
	{
		var->get_swapChainFramebuffers().resize(var->get_swapChainImageViews().size());
		std::cout << "Swapchain size " << var->get_swapChainImageViews().size() << std::endl;
		int width, height;
		glfwGetFramebufferSize(var->get_window(), &width, &height);

		VkExtent2D extent = {};
		extent.width = static_cast<uint32_t>(width);
		extent.height = static_cast<uint32_t>(height);
		
		for (size_t i = 0; i < var->get_swapChainImageViews().size(); i++) {
			VkImageView attachments[] = {
				var->get_swapChainImageViews()[i]
			};

			VkFramebufferCreateInfo framebufferInfo{};
			framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
			framebufferInfo.renderPass = var->get_vkRenderPass();
			framebufferInfo.attachmentCount = 1;
			framebufferInfo.pAttachments = attachments;
			framebufferInfo.width =(float) extent.width;
			framebufferInfo.height =(float) extent.height;
			framebufferInfo.layers = 1;

			if (vkCreateFramebuffer(*var->get_vkDevice(), &framebufferInfo, nullptr, &var->get_swapChainFramebuffers()[i]) != VK_SUCCESS) {
				throw std::runtime_error("failed to create framebuffer!");
			}
			else {
				std::cout << "Framebuffers created \n";
			}
		}
	}

	void SetupManager::inflate_deviceLimits()
	{
		VkPhysicalDeviceProperties deviceProperties;
		vkGetPhysicalDeviceProperties(var->get_vkPhysicalDevice(), &deviceProperties);

		VkPhysicalDeviceLimits limits = deviceProperties.limits;
		std::cout << "Max Uniform Buffers per Descriptor Set: " << limits.maxPerStageDescriptorUniformBuffers << std::endl;
		std::cout << "Max Sampled Images per Descriptor Set: " << limits.maxPerStageDescriptorSampledImages << std::endl;
		std::cout << "Max Descriptor Sets: " << limits.maxBoundDescriptorSets << std::endl;

		var->set_vkPhysicalDeviceProperties(deviceProperties);
	}

	void SetupManager::iterate_deviceLimits() {
		VkPhysicalDeviceLimits limits = var->get_vkPhysicalDeviceProperties().limits;
		// Step 3: Print or use the relevant limits
		std::cout << "Max Uniform Buffers per Descriptor Set: " << limits.maxPerStageDescriptorUniformBuffers << std::endl;
		std::cout << "Max Sampled Images per Descriptor Set: " << limits.maxPerStageDescriptorSampledImages << std::endl;
		std::cout << "Max Descriptor Sets: " << limits.maxBoundDescriptorSets << std::endl;

		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(*var->get_vkInstance(), &deviceCount, nullptr);

		if (deviceCount == 0) {
			throw std::runtime_error("failed to find GPUs with Vulkan support!");
		}
		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(*var->get_vkInstance(), &deviceCount, devices.data());

		uint32_t extensionCount = 0;
		VkPhysicalDevice dd;
		for (VkPhysicalDevice& device : devices) {
			dd = device;
			break;
		}
		VkPhysicalDeviceProperties deviceProperties;
		vkGetPhysicalDeviceProperties(dd, &deviceProperties);
		VkPhysicalDeviceLimits limits2 = deviceProperties.limits;
		std::cout << "Max Descriptor Sets: " << limits2.maxBoundDescriptorSets << std::endl;
		std::cout << "Max Storage Buffer Range: " << limits2.maxStorageBufferRange << std::endl;
	}
	// public methods
	void SetupManager::setup() {
		create_glfwWindow(800, 400);
		var->set_width(800);
		var->set_height(400);
		if (!check_vkInstanceExtensions()) {
			throw std::runtime_error("Instance Extensions not found");
		}
		// create instance
		enumerate_instanceExt();
		create_vkInstance();
		setup_vkDebugLayer();
		create_vkSurface();
		pick_vkPhysicalDevice();
		iterateMemoryType();
		//enumerate_vkQueues();
		//enumerate_vkDeviceExtensions();
		//enumerate_vkDeviceFeatures();
		create_vkLogicalDevice();
		enumerate_swapChainCapabilities();
		create_vkSwapchain();
		create_vkImageViews();

		create_vkRenderPass();
		create_vkFramebuffer();

		inflate_deviceLimits();

		iterate_deviceLimits();

	}

	void SetupManager::destroy() {
		// swapchain

		for (auto imageView : var->get_swapChainImageViews()) {
			std::cout << "Destroying image view: " << imageView << std::endl;
			vkDestroyImageView(*var->get_vkDevice(), imageView, var->get_vkAllocationCallbacks());

		}
		var->clear_swapChainImageViews();

		vkDestroySwapchainKHR(*var->get_vkDevice(), *var->get_vkSwapchainKHR(), var->get_vkAllocationCallbacks());

		vkDestroySurfaceKHR(*var->get_vkInstance(), *var->get_vkSurface(), var->get_vkAllocationCallbacks());
		// Destroy logical device
		vkDestroyDevice(*var->get_vkDevice(), var->get_vkAllocationCallbacks());

		// Destroy Vulkan instance

		auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(*var->get_vkInstance(), "vkDestroyDebugUtilsMessengerEXT");
		if (func != nullptr) {
			func(*var->get_vkInstance(), debugMessenger, var->get_vkAllocationCallbacks());
		}
		vkDestroyInstance(*var->get_vkInstance(), var->get_vkAllocationCallbacks());

	}
	void SetupManager::handle_window_resize()
	{
		int width, height;
		glfwGetWindowSize(var->get_window(), &width, &height);
		var->set_width(width);
		var->set_height(height);
	}
}
