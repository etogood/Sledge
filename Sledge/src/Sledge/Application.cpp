#include "slpch.h"
#include "Application.h"

#include "Sledge/Events/ApplicationEvent.h"
#include "Sledge/Log.h"

namespace Sledge{

    Application::Application()
    {
	    
    }
    Application::~Application()
    {
	    
    }


    void Application::Run(){
        WindowResizeEvent e(1280, 720);
        SL_TRACE(e);

        while(true);
    }
}