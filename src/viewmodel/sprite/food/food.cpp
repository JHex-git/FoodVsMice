#include "food.h"
#include "../../../view/time_manager.h"

Food::Food(int x, int y, int health, float cool_down_time) : 
    Sprite(x, y, FRAME_RATE), health(health), cool_down_time(cool_down_time)
{
    current_cool_time = 0;
}

Food::Food(int x, int y, int delta_x, int delta_y, std::vector<QPixmap *> frames, int health, float cool_down_time) :
    Sprite(x, y, delta_x, delta_y, FRAME_RATE, frames), health(health), cool_down_time(cool_down_time)
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
