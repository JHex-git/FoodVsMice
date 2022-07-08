#include "mouse.h"
#include "../../../view/time_manager.h"

Mouse::Mouse(int x, int y, float frame_rate, int health, int velocity, int damage) :
    Sprite(x, y, frame_rate), health(health), velocity(velocity), damage(damage) {}

Mouse::Mouse(int x, int y, int delta_x, int delta_y, int row, int left_padding, int right_padding, float frame_rate, std::vector<QPixmap *> frames, int health, int velocity, int damage, float attack_interval, FoodManager *food_manager) :
        Sprite(x, y, delta_x, delta_y, frame_rate, frames), health(health), velocity(velocity), damage(damage), row(row), left_padding(left_padding), right_padding(right_padding), attack_interval(attack_interval), food_manager(food_manager)
{
    current_waiting_attack_time = attack_interval;
    center_x = x;
    center_y = y;
}

void Mouse::UpdateBehave()
{
        current_waiting_attack_time += TimeManager::DELTA_TIME;
        Food *food = food_manager->GetRightMostFood(center_x, row);
        if (food != nullptr)
        {
            if (food->GetCenterX() >= center_x - left_padding) // 面前有食物
            {
                if (current_waiting_attack_time >= attack_interval) // 攻击冷却完毕
                {
                    food->TakeDamage(damage);
                    current_waiting_attack_time = 0; // 开始冷却
                }
            }
            else
            {
                center_x -= velocity * TimeManager::DELTA_TIME;
                draw_item.x -= velocity * TimeManager::DELTA_TIME;
                current_waiting_attack_time = attack_interval; // 重置攻击冷却
            }
        }
        else
        {
            center_x -= velocity * TimeManager::DELTA_TIME;
            draw_item.x -= velocity * TimeManager::DELTA_TIME;
            current_waiting_attack_time = attack_interval; // 重置攻击冷却
        }
}

void Mouse::TakeDamage(int damage)
{
    health -= damage;
}
