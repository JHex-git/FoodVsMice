#include "food.h"
#include "../../../view/time_manager.h"

const float FRAME_RATE = 1;
Food::Food(int x, int y, int health, float cool_down_time) :
    Sprite(x, y, FRAME_RATE), health(health), cool_down_time(cool_down_time)
{
    current_cool_time = 0;
}

Food::Food(int x, int y, int delta_x, int delta_y, int row, std::vector<QPixmap *> frames, int projectile_index, int health, float cool_down_time) :
    Sprite(x, y, delta_x, delta_y, FRAME_RATE, frames), row(row), health(health), cool_down_time(cool_down_time), projectile_index(projectile_index)
{
    current_cool_time = 0;
}

void Food::Update()
{
    frame_accum += frame_rate;
    if (frame_accum >= 1)
    {
        current_frame = (current_frame + 1) % projectile_index;
        frame_accum = 0;
        draw_item.img = frames[current_frame];
    }
    UpdateBehave();
}

void Food::UpdateBehave()
{
    current_cool_time += TimeManager::DELTA_TIME;
    if (current_cool_time >= cool_down_time)
    {
        if (Func())
        {
            current_cool_time = 0;
        }
    }
}

void Food::TakeDamage(int damage)
{
    health -= damage;
}
