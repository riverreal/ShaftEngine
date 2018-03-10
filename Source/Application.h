#pragma once

#include "Engine/Core.h"

namespace Shaft {
	class Engine;

	class Application
	{
	public:
		Application();
		~Application();
		void Initialize();
		void Run();

	private:
		std::unique_ptr<Engine> m_engine;
	};
}