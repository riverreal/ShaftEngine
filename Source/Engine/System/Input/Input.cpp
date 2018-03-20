#include "Input.h"

using namespace Shaft;

Shaft::Input::Input()
{
}

Shaft::Input::~Input()
{
}

MouseState & Shaft::Input::GetMouseState()
{
	return m_mouseState;
}
