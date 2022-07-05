#include "projectile.h"

Projectile::Projectile(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames, int velocity, int damage) :
    Sprite(x, y, delta_x, delta_y, frame_rate, frames), velocity(velocity), damage(damage) {}
