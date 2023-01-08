#pragma once

#include "Core.h"

namespace Sledge {
    class SLEDGE_API Application {
        public:
        
        Application() = default;
        virtual ~Application() = default;

        void run();
    };
}