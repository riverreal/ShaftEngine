#pragma once

#include "../../Core.h"

namespace Shaft
{
	struct KeyState
	{
		enum Key
		{
			Esc,
			Return,
			Tab,
			Backspace,
			Space,
			Up,
			Down,
			Left,
			Right,
			PageUp,
			PageDown,
			Home,
			End,
			Print,
			Plus,
			Minus,
			Comma,
			Period,
			Slash,
			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,
			NumPad0,
			NumPad1,
			NumPad2,
			NumPad3,
			NumPad4,
			NumPad5,
			NumPad6,
			NumPad7,
			NumPad8,
			NumPad9,
			Key0,
			Key1,
			Key2,
			Key3,
			Key4,
			Key5,
			Key6,
			Key7,
			Key8,
			Key9,
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			Max
		};

		KeyState()
		{
			for (uint32f i = 0; i < Key::Max; ++i)
			{
				keys[i] = false;
			}
		}
		bool keys[Key::Max];
	};
}