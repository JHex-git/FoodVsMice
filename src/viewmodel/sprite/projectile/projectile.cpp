#include "projectile.h"

Projectile::Projectile(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage) :
    Sprite(x, y, delta_x, delta_y, frame_rate, frames), velocity(velocity), damage(damage), boom_index(boom_index)
{
    is_active = true;
    is_boom = false;
    bound = boom_index;
}

void Projectile::Update()
{
    frame_accum += frame_rate;
    if (frame_accum >= 1)
    {
        current_frame = (current_frame + 1) % bound;
//        current_frame = 8;
        frame_accum = 0;
        sprite_item.img = frames[current_frame];
    }
    UpdateBehave();
}
