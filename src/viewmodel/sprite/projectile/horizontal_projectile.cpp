#include "horizontal_projectile.h"
#include "../../../view/time_manager.h"

const int DELTA_X = 1;
const int DELTA_Y = 1;
HorizontalProjectile::HorizontalProjectile(int x, int y, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage)
    : Projectile(x, y, DELTA_X, DELTA_Y, frame_rate, frames, boom_index, velocity, damage) { }

void HorizontalProjectile::UpdateBehave()
{
    draw_item.x += velocity * TimeManager::DELTA_TIME;
}
