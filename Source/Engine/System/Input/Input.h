#pragma once

#include <Shaft/Core.h>
#include "MouseState.h"
#include "KeyState.h"

namespace Shaft
{
	class Input
	{
	public:
		Input();
		~Input();

		MouseState& GetMouseState();
		KeyState& GetKeyState();

	private:

	private:
		MouseState m_mouseState;
		KeyState m_keyState;
	};
}