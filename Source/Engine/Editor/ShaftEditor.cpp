#include "ShaftEditor.h"
#include <imgui/imgui.h>
#include "../System/Input/Input.h"
#include "../System/Misc/EngineConfig.h"

#if SHAFT_EDITOR_ENABLED

using namespace Shaft;

ShaftEditor::ShaftEditor(const EngineConfig& config)
	:m_initialized(false),
	m_config(config)
{
}

ShaftEditor::~ShaftEditor()
{
	Destroy();
}

void ShaftEditor::Init()
{
	imguiCreate();
	m_initialized = true;
}

void Shaft::ShaftEditor::Draw()
{
	auto& mouseState = m_input->GetMouseState();
	imguiBeginFrame(mouseState.mouseX, mouseState.mouseY,
		(mouseState.buttons[MouseState::Left] ? IMGUI_MBUT_LEFT : 0) |
		(mouseState.buttons[MouseState::Right] ? IMGUI_MBUT_RIGHT : 0) |
		(mouseState.buttons[MouseState::Middle] ? IMGUI_MBUT_MIDDLE : 0),
		mouseState.mouseZ,
		m_config.windowConfig.width,
		m_config.windowConfig.height);

	EditorDraw();

	imguiEndFrame();
}

void Shaft::ShaftEditor::BindInput(Input* input)
{
	m_input = input;
}

void ShaftEditor::Destroy()
{
	if (m_initialized)
	{
		imguiDestroy();
	}
}

void Shaft::ShaftEditor::EditorDraw()
{
	if (ImGui::BeginMainMenuBar())
	{
		ImGui::Text("   | ");

		ImGui::SameLine();

		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Test"))
			{
				std::cout << "Editor: File > Test" << std::endl;
			}

			if (ImGui::MenuItem("Test 2"))
			{
				std::cout << "Editor: File > Test 2" << std::endl;
			}

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Window"))
		{
			if (ImGui::MenuItem("Test"))
			{
				std::cout << "Editor: Window > Test" << std::endl;
			}

			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}
}

#endif