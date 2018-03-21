#pragma once

#include "../Core.h"

namespace Shaft
{
	class Actor
	{
	public:
		Actor();
		~Actor();
		void SetName(std::string name);
		const std::string& GetName() const;
		void AddChild(Actor* child);
		const std::vector<Actor*>& GetChilren() const;
		void SetParent(Actor* parent);

	private:
		Actor* m_parent;
		std::vector<Actor*> m_children;
		std::string m_name;
	};
}