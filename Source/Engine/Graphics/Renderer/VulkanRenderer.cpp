#include "VulkanRenderer.h"
#include "../../System/Window/WindowHandle.h"

using namespace Shaft;

VulkanRenderer::VulkanRenderer(const RendererConfig& config)
	:m_validationLayers({ "VK_LAYER_LUNARG_standard_validation" }),
	m_deviceExtensions({ VK_KHR_SWAPCHAIN_EXTENSION_NAME }),
	m_config(config)
{
}

VulkanRenderer::~VulkanRenderer()
{
	Destroy();
}

void VulkanRenderer::Initialize(WindowHandle& windowHandle)
{
	m_isValidationEnabled = m_config.isValidationEnabled;
	CreateInstance();
}

void VulkanRenderer::Draw()
{

}

void VulkanRenderer::Destroy()
{
	vkDestroyInstance(m_instance, nullptr);
}

void Shaft::VulkanRenderer::CreateInstance()
{
	if (m_isValidationEnabled && !CheckValidationLayerSupport())
	{
		throw std::runtime_error("Required validation layers not available");
	}

	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = m_config.appInfo.appName.c_str();
	appInfo.applicationVersion = VK_MAKE_VERSION(m_config.appInfo.appVersion.major, m_config.appInfo.appVersion.minor, 
													m_config.appInfo.appVersion.patch);
	appInfo.pEngineName = m_config.engineName.c_str();
	appInfo.engineVersion = VK_MAKE_VERSION(m_config.engineVersion.major, m_config.engineVersion.minor, m_config.engineVersion.patch);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	auto extensions = GetRequiredExtensions();
	createInfo.enabledExtensionCount = static_cast<uint32>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();
	if (m_isValidationEnabled)
	{
		createInfo.enabledLayerCount = static_cast<uint32>(m_validationLayers.size());
		createInfo.ppEnabledLayerNames = m_validationLayers.data();
	}
	else
	{
		createInfo.enabledLayerCount = 0;
	}

	if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create instace");
	}
	else
	{
		if (m_isValidationEnabled)
		{
			std::cout << "Vulkan: Create Instance" << std::endl;
		}
	}
}

bool Shaft::VulkanRenderer::CheckValidationLayerSupport()
{
	uint32 layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : m_validationLayers)
	{
		bool layerFound = false;
		for (const auto& layerProperties : availableLayers)
		{
			if (strcmp(layerName, layerProperties.layerName) == 0)
			{
				layerFound = true;
				break;
			}
		}

		if (!layerFound)
		{
			return false;
		}
	}

	return true;
}

std::vector<const char*> Shaft::VulkanRenderer::GetRequiredExtensions()
{
	uint32 extensionCount = 0;
	const char ** extensions;
	std::vector<const char*> instanceExtensions = { VK_KHR_SURFACE_EXTENSION_NAME };

#if PLATFORM_WINDOWS
	instanceExtensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#elif PLATFORM_LINUX
	instanceExtensions.push_back(VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME);
#elif PLATFORM_MACOS
	instanceExtensions.push_back(VK_MVK_MACOS_SURFACE_EXTENSION_NAME);
#elif PLATFORM_ANDROID
	instanceExtensions.push_back(VK_KHR_ANDROID_SURFACE_EXTENSION_NAME);
#elif PLATFORM_IOS
	instanceExtensions.push_back(VK_MVK_IOS_SURFACE_EXTENSION_NAME);
#endif
	if (m_isValidationEnabled)
	{
		instanceExtensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
	}

	return instanceExtensions;
}
