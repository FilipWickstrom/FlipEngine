#pragma once
#include <memory>
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>

/*
	Color meaning:
	* White:			Trace
	* Green:			Info
	* Yellow:			Warning
	* Red:				Error
	* Red background:	Fatal/Critical error
*/

namespace Flip
{
	class Logger
	{
	public:
		static std::shared_ptr<spdlog::logger>& GetEngineLogger();
		static std::shared_ptr<spdlog::logger>& GetAppLogger();

	private:
		// Singleton standards
		Logger();
		~Logger() = default;
		Logger(Logger const&) = delete;
		Logger(Logger const&&) = delete;
		Logger& operator=(Logger const&) = delete;
		Logger& operator=(Logger const&&) = delete;
		static auto& Get();

	private:
		std::shared_ptr<spdlog::logger> m_EngineLogger;
		std::shared_ptr<spdlog::logger> m_AppLogger;

	};
}

/*
	The logger API that can be used
*/
#define LOG_ENGINE_TRACE(...)   SPDLOG_LOGGER_TRACE(	Flip::Logger::GetEngineLogger(),	__VA_ARGS__) 
#define LOG_ENGINE_INFO(...)	SPDLOG_LOGGER_INFO(		Flip::Logger::GetEngineLogger(),	__VA_ARGS__) 
#define LOG_ENGINE_WARN(...)	SPDLOG_LOGGER_WARN(		Flip::Logger::GetEngineLogger(),	__VA_ARGS__) 
#define LOG_ENGINE_ERROR(...)	SPDLOG_LOGGER_ERROR(	Flip::Logger::GetEngineLogger(),	__VA_ARGS__) 
#define LOG_ENGINE_FATAL(...)	SPDLOG_LOGGER_CRITICAL(	Flip::Logger::GetEngineLogger(),	__VA_ARGS__) 

#define LOG_TRACE(...)			SPDLOG_LOGGER_TRACE(	Flip::Logger::GetAppLogger(),		__VA_ARGS__)
#define LOG_INFO(...)			SPDLOG_LOGGER_INFO(		Flip::Logger::GetAppLogger(),		__VA_ARGS__)
#define LOG_WARN(...)			SPDLOG_LOGGER_WARN(		Flip::Logger::GetAppLogger(),		__VA_ARGS__)
#define LOG_ERROR(...)			SPDLOG_LOGGER_ERROR(	Flip::Logger::GetAppLogger(),		__VA_ARGS__)
#define LOG_FATAL(...)			SPDLOG_LOGGER_CRITICAL(	Flip::Logger::GetAppLogger(),		__VA_ARGS__)

// Destribution build should not use any of the logging
#ifdef FE_DIST
	#define LOG_ENGINE_TRACE
	#define LOG_ENGINE_INFO
	#define LOG_ENGINE_WARN
	#define LOG_ENGINE_ERROR
	#define LOG_ENGINE_FATAL

	#define LOG_TRACE
	#define LOG_INFO
	#define LOG_WARN
	#define LOG_ERROR
	#define LOG_FATAL
#endif
