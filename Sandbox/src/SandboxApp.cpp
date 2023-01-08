#include <Sledge.h>

class Sandbox : public Sledge::Application {
public:
    Sandbox() {}
    ~Sandbox() {}
};

Sledge::Application* Sledge::CreateApplication()
{
    return new Sandbox();
}