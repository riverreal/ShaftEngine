#pragma once

#include "../../Core.h"

namespace Shaft
{
	enum RendererType
	{
		Vulkan,
		DirectX,
		OpenGL
	};

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
			rendererType(Vulkan),
			isValidationEnabled(true)
		{}

		std::string engineName;
		bool isValidationEnabled;
		RendererType rendererType;
		AppInfo appInfo;
		Version engineVersion;
	};

	struct WindowConfig
	{
		WindowConfig() 
			:isResizeable(false)
		{}

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
