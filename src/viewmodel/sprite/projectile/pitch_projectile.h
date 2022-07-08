#pragma once
#include "projectile.h"
#include "../mouse/mouse.h"

class PitchProjectile : public Projectile
{
private:
    Mouse *target;
    float initial_velocity_y;
    int low_bound;
public:
    PitchProjectile(int x, int y, int delta_x, int delta_y, int muzzle_padding_x, int muzzle_padding_y, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage, Mouse* target, int low_bound_padding);

    void UpdateBehave() override;

};

