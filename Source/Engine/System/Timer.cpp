#include "Timer.h"
#include <chrono>

using namespace std::chrono_literals;
using namespace Shaft;

Shaft::Timer::Timer()
{
}

Shaft::Timer::~Timer()
{
}

void Shaft::Timer::TimeStart()
{
	m_startTime = Clock::now();
}

void Shaft::Timer::Tick()
{
	auto delta = Clock::now() - m_startTime;
	auto d = std::chrono::duration_cast<std::chrono::duration<float, std::ratio<1,1>>>(delta);
	m_deltaTime = static_cast<float>(d.count());

	TimeStart();
}

float Shaft::Timer::GetDeltaTime()
{
	return m_deltaTime;
}
