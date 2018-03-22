#pragma once

#include <Shaft/Core.h>

namespace Shaft
{
	struct MouseState
	{
		enum MouseButton
		{
			None,
			Left,
			Right,
			Middle,
			Max
		};

		MouseState()
			:mouseX(0),mouseY(0),mouseZ(0)
		{
			for (uint32f i = 0; i < MouseButton::Max; ++i)
			{
				buttons[i] = false;
			}
		}

		uint32 mouseX;
		uint32 mouseY;
		uint32 mouseZ;
		bool buttons[MouseButton::Max];
	};
}