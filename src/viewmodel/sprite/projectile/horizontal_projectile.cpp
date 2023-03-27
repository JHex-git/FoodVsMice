#include "horizontal_projectile.h"
#include "../../../common/time_manager.h"
#include "../../../common/debug.h"

const int PROJECTILE_RIGHT_BOUND = 1000;

HorizontalProjectile::HorizontalProjectile(int x, int y, int delta_x, int delta_y, int muzzle_padding_x, int muzzle_padding_y, int row, int len, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage, MouseManager *mouse_manager)
    : Projectile(x - muzzle_padding_x, y - muzzle_padding_y, delta_x, delta_y, frame_rate, frames, boom_index, velocity, damage), mouse_manager(mouse_manager), row(row), len(len){}

void HorizontalProjectile::UpdateBehave()
{
    DEBUG_INFO("Before Horizontal");
    if (is_active)
    {
        if (center_x >= PROJECTILE_RIGHT_BOUND) is_active = false;
        else if (!is_boom)
        {
            center_x += velocity * TimeManager::DELTA_TIME;
            sprite_item.x += velocity * TimeManager::DELTA_TIME;
            Mouse *mouse = mouse_manager->GetLeftestMouse(center_x, row);
            if (mouse != nullptr && abs(center_x - mouse->GetX()) < 20)
            {
                current_frame = bound - 1;
                bound = frames.size();
                is_boom = true;
                mouse->TakeDamage(damage);
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
    DEBUG_INFO("After Horizontal");
}
