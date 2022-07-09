#pragma once
#include <ctime>

class TimeManager
{
public:
    static constexpr float DELTA_TIME = 0.02;
    static void Init();
    float GetCurrentSecond();

private:
    static clock_t start_time;
};
