#include "EnginePCH.h"
#include "Timer.h"

Timer::Timer()
{
	m_IsRunning = false;
}

void Timer::Start()
{
	m_IsRunning = true;
	m_StartTime = std::chrono::high_resolution_clock::now();
}

void Timer::Stop()
{
	m_IsRunning = false;
	m_EndTime = std::chrono::high_resolution_clock::now();
}

double Timer::GetMilliseconds()
{
	std::chrono::time_point<std::chrono::high_resolution_clock> endtime;

	if (m_IsRunning)
	{
		endtime = std::chrono::high_resolution_clock::now();
	}
	else
	{
		endtime = m_EndTime;
	}

	return std::chrono::duration<double, std::milli>(endtime - m_StartTime).count();
}

double Timer::GetSeconds()
{
	return GetMilliseconds() / 1000.0;
}
