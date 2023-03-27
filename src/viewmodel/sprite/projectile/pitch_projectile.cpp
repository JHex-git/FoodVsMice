#include "pitch_projectile.h"
#include "../../../common/time_manager.h"
#include "../../../common/debug.h"

const float GRAVITY = 1000;
const float EPSILON = 0.05;

// velocity在这里表示纵向速度，向上为正
PitchProjectile::PitchProjectile(int x, int y, int delta_x, int delta_y, int muzzle_padding_x, int muzzle_padding_y, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage, Mouse* target, int low_bound_padding)
    : Projectile(x - muzzle_padding_x, y - muzzle_padding_y, delta_x, delta_y, frame_rate, frames, boom_index, velocity, damage), target(target)
{
    initial_velocity_y = velocity;
    low_bound = low_bound_padding + y;
}

void PitchProjectile::UpdateBehave()
{
    DEBUG_INFO("Before PitchProjectile");
    static int x;
    // 子弹上抛再到落下的总时间为2v_0/g, 剩下水平位移为(target.x - x)，时间为(-v_0-v)/g
    if (is_active)
    {
        if (!is_boom)
        {
            velocity += -GRAVITY * TimeManager::DELTA_TIME;

            if (target != nullptr && target->is_active)
            {
                if (abs(-initial_velocity_y - velocity) > EPSILON)
                {
                    int delta;
                    delta = ((x = target->GetX()) - center_x) / (-initial_velocity_y - velocity) * -GRAVITY * TimeManager::DELTA_TIME;
                    center_x += delta;
                    sprite_item.x += delta;
                }
            }
            else
            {
                if (abs(-initial_velocity_y - velocity) > EPSILON)
                {
                    int delta = (x - center_x) / (-initial_velocity_y - velocity) * -GRAVITY * TimeManager::DELTA_TIME;
                    center_x += delta;
                    sprite_item.x += delta;
                }
            }

            center_y -= velocity * TimeManager::DELTA_TIME;
            sprite_item.y -= velocity * TimeManager::DELTA_TIME;
            if (center_y > low_bound) // 低于最低点，就结束
            {
                if (target != nullptr)
                {
                    current_frame = bound - 1;
                    bound = frames.size();
                    is_boom = true;

                    if (target->is_active)
                    {
                        target->TakeDamage(damage);
                    }
                }
            }
        }
        else
        {
            if ((uint32_t)current_frame == frames.size() - 1)
            {
                is_active = false;
            }
        }
    }
}
