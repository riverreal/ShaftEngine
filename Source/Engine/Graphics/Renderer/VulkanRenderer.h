#pragma once

#include "Renderer.h"
#include "../../System/Misc/EngineConfig.h"

namespace Shaft {
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

	private:
		//Vulkan objects
		VkInstance m_instance;

		const RendererConfig& m_config;
		bool m_isValidationEnabled;
		const std::vector<const char*> m_validationLayers;
		const std::vector<const char*> m_deviceExtensions;
	};
}