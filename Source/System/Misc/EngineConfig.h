#pragma once

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

	struct EngineConfig
	{
		RendererType rendererType;
		TargetOS buildTarget;
	};
}
