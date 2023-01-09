#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Sledge
{
	class SLEDGE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SL_CORE_TRACE(...)	::Sledge::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SL_CORE_INFO(...)	::Sledge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SL_CORE_WARN(...)	::Sledge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SL_CORE_ERROR(...)	::Sledge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SL_CORE_FATAL(...)	::Sledge::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros

#define SL_TRACE(...)		::Sledge::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SL_INFO(...)		::Sledge::Log::GetClientLogger()->info(__VA_ARGS__)
#define SL_WARN(...)		::Sledge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SL_ERROR(...)		::Sledge::Log::GetClientLogger()->error(__VA_ARGS__)
#define SL_FATAL(...)		::Sledge::Log::GetClientLogger()->fatal(__VA_ARGS__)