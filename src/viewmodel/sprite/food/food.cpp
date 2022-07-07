#include "food.h"
#include "../../../view/time_manager.h"

const float FRAME_RATE = 1;
Food::Food(int x, int y, int health, float cool_down_time) :
    Sprite(x, y, FRAME_RATE), health(health), cool_down_time(cool_down_time)
{
    current_cool_time = 0;
}

Food::Food(int x, int y, int delta_x, int delta_y, int row, std::vector<QPixmap *> frames, int func_start_index, int func_take_effect_index, int projectile_index, int health, float cool_down_time) :
    Sprite(x, y, delta_x, delta_y, FRAME_RATE, frames), row(row), health(health), cool_down_time(cool_down_time), projectile_index(projectile_index), func_start_index(func_start_index), func_take_effect_index(func_take_effect_index)
{
    current_cool_time = 0;
}

void Food::Update()
{
    frame_accum += frame_rate;
    if (frame_accum >= 1)
    {
        if (start_func)
            current_frame = (current_frame + 1) % projectile_index;
        else
            current_frame = (current_frame + 1) % func_start_index;
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
        if (!start_func && CheckFunc())
        {
            // 开始前摇
//            current_frame = func_start_index - 1; // 重置
            start_func = true;
        }
        if (start_func && current_frame == func_take_effect_index - 1)
        {
            // 前摇结束，真正生效
            Func();
            current_cool_time = 0;
            start_func = false;
        }
    }
}

void Food::TakeDamage(int damage)
{
    health -= damage;
}
