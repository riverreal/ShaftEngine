#pragma once

#include "../../Core.h"
#include "MouseState.h"

namespace Shaft
{
	class Input
	{
	public:
		Input();
		~Input();

		MouseState& GetMouseState();

	private:

	private:
		MouseState m_mouseState;
	};
}