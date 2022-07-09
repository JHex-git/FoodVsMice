#include "time_manager.h"

float TimeManager::start_time;
float TimeManager::current_time;

void TimeManager::Init()
{
    current_time = start_time = 0;
}

float TimeManager::GetCurrentSecond()
{
    return current_time - start_time;
}

void TimeManager::UpdateTime()
{
    current_time += DELTA_TIME;
}
