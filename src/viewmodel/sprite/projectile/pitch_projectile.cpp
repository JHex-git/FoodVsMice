#include "pitch_projectile.h"
#include "../../../view/time_manager.h"

const float GRAVITY = 4000;
const float EPSILON = 0.05;

// velocity在这里表示纵向速度，向上为正
PitchProjectile::PitchProjectile(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage, Mouse* target, int low_bound_padding)
    : Projectile(x, y, delta_x, delta_y, frame_rate, frames, boom_index, velocity, damage), target(target)
{
    initial_velocity_y = velocity;
    low_bound = low_bound_padding + y;
}

void PitchProjectile::UpdateBehave()
{
    static int x;
    // 子弹上抛再到落下的总时间为2v_0/g, 剩下水平位移为(target.x - x)，时间为(-v_0-v)/g
    if (is_active)
    {
        if (!is_boom)
        {
            velocity += -GRAVITY * TimeManager::DELTA_TIME;

            if (target != nullptr)
            {
                if (abs(-initial_velocity_y - velocity) > EPSILON)
                    draw_item.x += ((x = target->GetX()) - draw_item.x) / (-initial_velocity_y - velocity) * -GRAVITY * TimeManager::DELTA_TIME;
            }
            else
            {
                if (abs(-initial_velocity_y - velocity) > EPSILON)
                    draw_item.x += (x - draw_item.x) / (-initial_velocity_y - velocity) * -GRAVITY * TimeManager::DELTA_TIME;
            }
            draw_item.y -= velocity * TimeManager::DELTA_TIME;
            if (draw_item.y > low_bound) // 低于最低点，就结束
            {
                DEBUG_INFO("destroy");
                if (target != nullptr)
                {
                    current_frame = bound - 1;
                    bound = frames.size();
                    is_boom = true;
                    target->TakeDamage(damage);
                }
            }
        }
        else
        {
            if ((uint32_t)current_frame == frames.size() - 1)
            {
                DEBUG_INFO("delete");
                is_active = false;
            }
        }
    }
}
