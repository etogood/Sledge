#pragma once

#include "Sledge/Layer.h"

#include "Sledge/Events/ApplicationEvent.h"
#include "Sledge/Events/KeyEvent.h"
#include "Sledge/Events/MouseEvent.h"

namespace Sledge
{
	class SLEDGE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;
	private:
		bool  OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool  OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool  OnMouseMovedEvent(MouseMovedEvent& e);
		bool  OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool  OnKeyPressedEvent(KeyPressedEvent& e);
		bool  OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool  OnKeyTypedEvent(KeyTypedEvent& e);
		bool  OnWindowResizedEvent(WindowResizeEvent& e);
	private:
		float m_Time = 0.0f;
	};
}
