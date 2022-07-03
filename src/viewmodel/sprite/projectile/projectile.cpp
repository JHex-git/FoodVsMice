#include "projectile.h"

Projectile::Projectile(int x, int y, float frame_rate, std::vector<QPixmap *> frames, int velocity, int damage) :
    Sprite(x, y, frame_rate, frames), velocity(velocity), damage(damage) {}
