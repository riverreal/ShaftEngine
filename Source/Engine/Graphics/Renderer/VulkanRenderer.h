#pragma once

#include "Renderer.h"
#include "../../System/Misc/EngineConfig.h"

namespace Shaft {

	struct QueueFamilyIndices 
	{
		int graphicsFamily = -1;

		bool isComplete() 
		{
			return graphicsFamily >= 0;
		}
	};
	class VulkanRenderer : public Renderer
	{
	public:
		VulkanRenderer(const RendererConfig& config);
		~VulkanRenderer();
		void Initialize(WindowHandle& windowHandle) override;
		void Draw() override;
		void Destroy() override;

	private:
		void CreateInstance();
		bool CheckValidationLayerSupport();
		std::vector<const char*> GetRequiredExtensions();

		void SetupDebugCallback();
		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData);
		VkResult CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
		void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);

		void PickPhysicalDevice();
		bool isDeviceSuitable(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

		void CreateLogicalDevice();
		
		
		



	private:
		//Vulkan objects
		VkInstance m_instance;
		VkDebugReportCallbackEXT m_callback;
		VkDevice m_device;

		const RendererConfig& m_config;
		bool m_isValidationEnabled;
		const std::vector<const char*> m_validationLayers;
		const std::vector<const char*> m_deviceExtensions;

		VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;

		VkQueue m_graphicsQueue;
	};
}