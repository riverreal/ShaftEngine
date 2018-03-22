#pragma once

#include "IComponent.h"
#include "../../Core.h"

namespace Shaft
{
	class Transform : public IComponent
	{
	public:
		Transform();
		~Transform();
		virtual void Initialize() override;
		int32 positionX;
	};
}