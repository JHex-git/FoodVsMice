#pragma once
#include <ctime>

class TimeManager
{
public:
    static constexpr float DELTA_TIME = 0.02;
    void Init();
    float GetCurrentSecond();

private:
    clock_t start_time;
};
