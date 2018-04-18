#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_

#include <chrono>

namespace Shaft
{
	class Timer
	{
	public:
		Timer();
		~Timer();

		using Clock = std::chrono::high_resolution_clock;
		using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;

		void TimeStart();
		void Tick();
		float GetDeltaTime();

	private:
		float m_deltaTime;
		TimePoint m_startTime;

	};
}

#endif //_TIMER_H_
