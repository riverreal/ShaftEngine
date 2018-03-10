#pragma once

namespace Shaft {
	class Renderer
	{
	public:
		~Renderer() {};
		virtual void Initialize() = 0;
		virtual void Draw() = 0;
		virtual void Destroy() = 0;
	};
}