#include "mouse.h"
#include "../food/food.h"
#include "../../../common/time_manager.h"
#include "../../../common/debug.h"
const int EAT_START = 8;

Mouse::Mouse(int x, int y, float frame_rate, int health, int velocity, int damage) :
    Sprite(x, y, frame_rate), health(health), velocity(velocity), damage(damage) {}

Mouse::Mouse(int x, int y, int delta_x, int delta_y, int row, int left_padding, int right_padding, float frame_rate, std::vector<QPixmap *> frames, int health, int velocity, int damage, float attack_interval, FoodManager *food_manager) :
        Sprite(x, y, delta_x, delta_y, frame_rate, frames), health(health), velocity(velocity), damage(damage), row(row), left_padding(left_padding), right_padding(right_padding), attack_interval(attack_interval), food_manager(food_manager)
{
    current_waiting_attack_time = attack_interval;
    center_x = x;
    center_y = y;
    is_eating = false;
    is_active = true;
    anim_up_bound = EAT_START;
    anim_down_bound = 0;
}

void Mouse::Reset(int x, int y, int row)
{
    current_frame = 0;
    current_waiting_attack_time = attack_interval;
    sprite_item.x -= center_x;
    sprite_item.y -= center_y;
    center_x = x;
    center_y = y;
    sprite_item.x += center_x;
    sprite_item.y += center_y;
    this->row = row;
    anim_down_bound = 0;
    anim_up_bound = EAT_START;
    is_eating = false;
    is_active = true;
}

void Mouse::UpdateBehave()
{
    current_waiting_attack_time += TimeManager::DELTA_TIME;
    Food *food = food_manager->GetRightMostFood(center_x, row);
    if (food != nullptr)
    {
        if (food->GetCenterX() >= center_x - left_padding) // 面前有食物
        {
            if (!is_eating)
            {
                is_eating = true;
                current_frame = EAT_START - 1;
                anim_down_bound = EAT_START;
                anim_up_bound = frames.size();
            }
            if (current_waiting_attack_time >= attack_interval) // 攻击冷却完毕
            {
                food->TakeDamage(damage);
                current_waiting_attack_time = 0; // 开始冷却
            }
        }
        else
        {
            if (is_eating)
            {
                is_eating = false;
                current_waiting_attack_time = -1;
                anim_down_bound = 0;
                anim_up_bound = EAT_START;
            }
            center_x -= velocity * TimeManager::DELTA_TIME;
            sprite_item.x -= velocity * TimeManager::DELTA_TIME;
            current_waiting_attack_time = attack_interval; // 重置攻击冷却
        }
    }
    else
    {
        if (is_eating)
        {
            is_eating = false;
            current_waiting_attack_time = -1;
            anim_down_bound = 0;
            anim_up_bound = EAT_START;
        }
        center_x -= velocity * TimeManager::DELTA_TIME;
        sprite_item.x -= velocity * TimeManager::DELTA_TIME;
        current_waiting_attack_time = attack_interval; // 重置攻击冷却
    }
}

void Mouse::Update()
{
    frame_accum += frame_rate;
    if (frame_accum >= 1)
    {
        current_frame = (current_frame + 1) % anim_up_bound;
        if (current_frame == 0) current_frame = anim_down_bound;
        frame_accum = 0;
        sprite_item.img = frames[current_frame];
    }
    UpdateBehave();
}

void Mouse::TakeDamage(int damage)
{
    health -= damage;
    if (health <= 0) is_active = false;
}
