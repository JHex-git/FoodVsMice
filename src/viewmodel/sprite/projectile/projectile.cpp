#include "projectile.h"

Projectile::Projectile(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int velocity, int damage) :
    Sprite(x, y, frame_rate, frames), velocity(velocity), damage(damage) {}
