#pragma once
#include <chrono>

namespace Flip
{
	class Timer
	{
	public:
		Timer();
		~Timer() = default;

		void Start();
		void Stop();
		double GetMicroseconds();
		double GetMilliseconds();
		double GetSeconds();

	private:
		bool m_IsRunning;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_EndTime;
	};
}