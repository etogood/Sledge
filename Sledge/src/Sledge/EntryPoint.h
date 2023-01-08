#pragma once

#ifdef SL_PLATFORM_WINDOWS

extern Sledge::Application* Sledge::CreateApplication();

int main(int argc, char** argv) {
	Sledge::Log::Init();
	SL_CORE_WARN("Initialized Log!");
	SL_INFO("Hello!);

	auto app = Sledge::CreateApplication();
	app->Run();
	delete app;
}

#endif