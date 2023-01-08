#include <Sledge.h>

class Sandbox : public Sledge::Application {
public:
    Sandbox() {}
    ~Sandbox() {}
};

int main(){
	const auto sandbox = new Sandbox();
    sandbox->run();
    delete sandbox;
}