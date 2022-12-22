#pragma once
#include <chrono>

class Timer
{
public:
	Timer();
	~Timer() = default;

	void Start();
	void Stop();
	double GetMilliseconds();
	double GetSeconds();

private:
	bool m_IsRunning;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_EndTime;
};