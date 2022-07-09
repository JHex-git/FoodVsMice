#pragma once
#include <ctime>

class TimeManager
{
public:
    static constexpr float DELTA_TIME = 0.05;
    static void Init();
    static void UpdateTime();
    float GetCurrentSecond();

private:
    static float start_time;
    static float current_time;
};
