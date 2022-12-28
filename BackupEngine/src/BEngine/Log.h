#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace BEngine {

	class BENGINE_API Log
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
#define EN_CORE_TRACE(...)    BEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EN_CORE_INFO(...)     BEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EN_CORE_WARN(...)     BEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EN_CORE_ERROR(...)    BEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EN_CORE_CRITICAL(...) BEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define EN_TRACE(...)         BEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EN_INFO(...)          BEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define EN_WARN(...)          BEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EN_ERROR(...)         BEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define EN_CRITICAL(...)      BEngine::Log::GetClientLogger()->critical(__VA_ARGS__)