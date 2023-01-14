#include "slpch.h"
#include "Application.h"

#include <glad/glad.h>

#include "Input.h"

namespace Sledge{

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        SL_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback( BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }


    void Application::OnEvent(Event& e)
    {

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));


        SL_CORE_TRACE("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.m_Handled)
                break;
        }
    }


    void Application::Run(){
        WindowResizeEvent e(1280, 720);
        SL_TRACE(e);
        glClearColor(1, 0, 1, 1);

        auto time = 0;
        while(m_Running)
        {
            
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();
            time++;
            if (time % 60 == 0)
            {
                auto [x, y] = Input::GetMousePosition();
                SL_CORE_TRACE("{0}, {1}", x, y);
            }

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}