#include "horizontal_projectile.h"
#include "../../../view/time_manager.h"

void HorizontalProjectile::UpdateBehave()
{
    draw_item.x += velocity * TimeManager::DELTA_TIME;
}
