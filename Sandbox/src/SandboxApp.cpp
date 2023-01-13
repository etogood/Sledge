#include <Sledge.h>

class ExampleLayer : public Sledge::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        SL_INFO("ExampleLayer::Update");
    }

    void OnEvent(Sledge::Event& e) override
    {
        SL_TRACE("{0}", e);
    }
};

class Sandbox : public Sledge::Application {
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Sledge::ImGuiLayer());
    }
    ~Sandbox() {}
};

Sledge::Application* Sledge::CreateApplication()
{
    return new Sandbox();
}