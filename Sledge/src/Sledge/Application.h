#pragma once

#include "Core.h"
#include "Window.h"

#include "Sledge/LayerStack.h"
#include "Sledge/Events/Event.h"
#include "Sledge/Events/ApplicationEvent.h"

#include "Sledge/ImGui/ImGuiLayer.h"

namespace Sledge {
    class SLEDGE_API Application {
        public:
        
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        inline static Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application* s_Instance;
    };

    //To be defined in CLIENT
    Application* CreateApplication();

}
