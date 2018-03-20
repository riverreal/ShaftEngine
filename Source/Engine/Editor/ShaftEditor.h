#pragma once

#include "../Core.h"

#if SHAFT_EDITOR_ENABLED
namespace Shaft
{
	class Input;
	struct EngineConfig;

	class ShaftEditor
	{
	public:
		ShaftEditor(const EngineConfig& config);
		~ShaftEditor();
		void Init();
		void Draw();
		void BindInput(Input* input);
	private:
		void Destroy();
		void EditorDraw();
	private:
		bool m_initialized;
		Input* m_input;
		const EngineConfig& m_config;
	};
}
#endif