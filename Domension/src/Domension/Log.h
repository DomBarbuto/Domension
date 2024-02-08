#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Domension 
{
	class DOM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_pCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_pClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> m_pCoreLogger;
		static std::shared_ptr<spdlog::logger> m_pClientLogger;
	};

}

// Core log macros
#define DOM_CORE_TRACE(...)		::Domension::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DOM_CORE_INFO(...)		::Domension::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DOM_CORE_WARN(...)		::Domension::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DOM_CORE_ERROR(...)		::Domension::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DOM_CORE_FATAL(...)		::Domension::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DOM_TRACE(...)		::Domension::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DOM_INFO(...)		::Domension::Log::GetClientLogger()->info(__VA_ARGS__)
#define DOM_WARN(...)		::Domension::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DOM_ERROR(...)		::Domension::Log::GetClientLogger()->error(__VA_ARGS__)
#define DOM_FATAL(...)		::Domension::Log::GetClientLogger()->fatal(__VA_ARGS__)

