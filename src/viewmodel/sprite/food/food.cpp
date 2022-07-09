#include "food.h"
#include "../../../common/time_manager.h"

Food::Food(int x, int y, int health, float frame_rate, float cool_down_time) :
    Sprite(x, y, frame_rate), health(health), cool_down_time(cool_down_time)
{
    center_x = x;
    center_y = y;
    current_cool_time = 0;
}

Food::Food(int x, int y, int delta_x, int delta_y, int row, int column, int left_padding, int right_padding, float frame_rate, std::vector<QPixmap *> frames, int func_start_index, int func_take_effect_index, int projectile_index, int health, float cool_down_time) :
    Sprite(x, y, delta_x, delta_y, frame_rate, frames), row(row), column(column), left_padding(left_padding), right_padding(right_padding), health(health), cool_down_time(cool_down_time), projectile_index(projectile_index), func_start_index(func_start_index), func_take_effect_index(func_take_effect_index)
{
    center_x = x;
    center_y = y;
    start_func = false;
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
        sprite_item.img = frames[current_frame];
    }
    UpdateBehave();
}

void Food::UpdateBehave()
{
    current_cool_time += TimeManager::DELTA_TIME;
    if (current_cool_time >= cool_down_time)
    {
        // 开始前摇
        if (!start_func && CheckFunc())
        {
//            current_frame = func_start_index - 1; // 重置
            start_func = true;
        }

        // 前摇结束，真正生效
        if (start_func && current_frame == func_take_effect_index - 1)
        {
            Func();
        }

        // 后摇结束
        if (start_func && current_frame == projectile_index - 1)
        {
            current_cool_time = 0;
            start_func = false;
        }
    }
}

void Food::TakeDamage(int damage)
{
    health -= damage;
}
