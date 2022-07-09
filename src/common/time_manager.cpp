#include "time_manager.h"


clock_t TimeManager::start_time;

void TimeManager::Init()
{
    start_time = clock();
}

float TimeManager::GetCurrentSecond()
{
    return (float)(clock() - start_time) / CLOCKS_PER_SEC;
}
