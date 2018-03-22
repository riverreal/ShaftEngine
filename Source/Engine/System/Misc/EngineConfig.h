#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	enum RendererType
	{
		Vulkan,
		Direct3D12,
		Direct3D11,
		OpenGL,
		OpenGLES,
		Metal
	};

	static bgfx::RendererType::Enum ConvertRendererTypeToBGFX(RendererType type)
	{
		if (type == Vulkan)
		{
			return bgfx::RendererType::Enum::Vulkan;
		}
		else if (type == Direct3D12)
		{
			return bgfx::RendererType::Enum::Direct3D12;
		}
		else if (type == Direct3D11)
		{
			return bgfx::RendererType::Enum::Direct3D11;
		}
		else if (type == OpenGL)
		{
			return bgfx::RendererType::Enum::OpenGL;
		}
		else if (type == OpenGLES)
		{
			return bgfx::RendererType::Enum::OpenGLES;
		}
		else if (type == Metal)
		{
			return bgfx::RendererType::Enum::Metal;
		}
		
		//Just in case
		return bgfx::RendererType::Enum::Direct3D11;
	}

	enum TargetOS
	{
		Windows,
		MacOS,
		IOS,
		Linux,
		Android
	};

	struct Version
	{
		Version()
			:major(0), minor(0), patch(0)
		{}

		Version(uint32 maj, uint32 min, uint32 pat)
			:major(maj), minor(min), patch(pat)
		{}

		uint32 major;
		uint32 minor;
		uint32 patch;
	};

	struct AppInfo
	{
		std::string appName;
		Version appVersion;
	};

	struct RendererConfig
	{
		RendererConfig()
			:engineName("DefaultEngine"),
			rendererType(Direct3D11),
			isValidationEnabled(true),
			width(DEFAULT_SCREEN_WIDTH),
			height(DEFAULT_SCREEN_HEIGHT)
		{}

		uint32 width;
		uint32 height;
		std::string engineName;
		bool isValidationEnabled;
		RendererType rendererType;
		AppInfo appInfo;
		Version engineVersion;
	};

	struct WindowConfig
	{
		WindowConfig() 
			:isResizeable(false),
			width(DEFAULT_SCREEN_WIDTH),
			height(DEFAULT_SCREEN_HEIGHT)
		{}

		uint32 width;
		uint32 height;
		bool isResizeable;
		AppInfo appInfo;
	};

	struct EngineConfig
	{
		EngineConfig()
			:buildTarget(Windows)
		{}

		AppInfo appInfo;
		TargetOS buildTarget;
		Version engineVersion;
		RendererConfig renderConfig;
		WindowConfig windowConfig;
	};
}
