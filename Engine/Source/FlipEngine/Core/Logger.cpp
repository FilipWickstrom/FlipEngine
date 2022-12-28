#include "EnginePCH.h"
#include "Logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

Flip::Logger::Logger()
{
	// Specialize how the output should be.
	// [Time] App/Engine 'The message' in File.cpp(line number)
	spdlog::set_pattern("%^[%T] %-8n '%v' in %s(%#) %$");

	// Create 2 loggers
	m_EngineLogger	= spdlog::stdout_color_mt("ENGINE");
	m_AppLogger		= spdlog::stdout_color_mt("APP");

	m_EngineLogger->set_level(spdlog::level::trace);
	m_AppLogger->set_level(spdlog::level::trace);
}

auto& Flip::Logger::Get()
{
	static Logger instance;
	return instance;
}

std::shared_ptr<spdlog::logger>& Flip::Logger::GetEngineLogger()
{
	return Get().m_EngineLogger;
}

std::shared_ptr<spdlog::logger>& Flip::Logger::GetAppLogger()
{
	return Get().m_AppLogger;
}
