#include "horizontal_projectile.h"
#include "../../../view/time_manager.h"

const int PROJECTILE_RIGHT_BOUND = 1000;

HorizontalProjectile::HorizontalProjectile(int x, int y, int delta_x, int delta_y, int row, int len, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage, MouseManager *mouse_manager)
    : Projectile(x, y, delta_x, delta_y, frame_rate, frames, boom_index, velocity, damage), mouse_manager(mouse_manager), row(row), len(len) {}

void HorizontalProjectile::UpdateBehave()
{
    if (is_active)
    {
        if (draw_item.x >= PROJECTILE_RIGHT_BOUND) is_active = false;
        else if (!is_boom)
        {
            draw_item.x += velocity * TimeManager::DELTA_TIME;
            Mouse *mouse = mouse_manager->GetLeftestMouse(draw_item.x, row);
            if (mouse != nullptr && mouse->GetX() < draw_item.x + len)
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
}
