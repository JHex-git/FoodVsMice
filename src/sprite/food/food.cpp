#include "sprite/food/food.h"
#include "time_manager.h"

Food::Food(int x, int y, int health, float cool_down_time) : 
    Sprite(x, y, FRAME_RATE), health(health), cool_down_time(cool_down_time)
{
    current_cool_time = 0;
}

Food::Food(int x, int y, std::vector<IMAGE *> frames, int health, float cool_down_time) : 
    Sprite(x, y, FRAME_RATE, frames), health(health), cool_down_time(cool_down_time)
{
    current_cool_time = 0;
}

void Food::UpdateBehave()
{
    current_cool_time += TimeManager::DELTA_TIME;
    if (current_cool_time >= cool_down_time)
    {
        current_cool_time = 0;
        Func();
    }
}

void Food::TakeDamage(int damage)
{
    health -= damage;
}