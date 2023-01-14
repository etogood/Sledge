#pragma once

#if SL_PLATFORM_WINDOWS

extern Sledge::Application* Sledge::CreateApplication();

int main(int argc, char** argv) {
	Sledge::Log::Init();
	SL_CORE_INFO("Initialized CORE Log!");
	SL_INFO("Initialized APP Log!");

	auto app = Sledge::CreateApplication();
	app->Run();
	delete app;
}
#endif