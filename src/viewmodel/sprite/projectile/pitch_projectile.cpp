#include "pitch_projectile.h"
#include "../../../view/time_manager.h"

const float GRAVITY = 9.8;

// velocity在这里表示纵向速度，向上为正
PitchProjectile::PitchProjectile(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames, int velocity, int damage, Mouse* target)
    : Projectile(x, y, delta_x, delta_y, frame_rate, frames, velocity, damage), target(target)
{
    initial_velocity_y = velocity;
}

void PitchProjectile::UpdateBehave()
{
    // 子弹上抛再到落下的总时间为2v_0/g, 剩下水平位移为(target.x - x)，时间为(-v_0-v)/g
    if (target->GetX() >= draw_item.x)
    {
        velocity -= GRAVITY * TimeManager::DELTA_TIME;
        draw_item.x += (target->GetX() - draw_item.x) / (-initial_velocity_y - velocity) * GRAVITY * TimeManager::DELTA_TIME;
        draw_item.y -= velocity * TimeManager::DELTA_TIME;
    }
    else
    {
        is_active = false;
    }
}
