#include "sprite/projectile/horizontal_projectile.h"
#include "time_manager.h"

void HorizontalProjectile::UpdateBehave()
{
    x += velocity * TimeManager::DELTA_TIME;
}