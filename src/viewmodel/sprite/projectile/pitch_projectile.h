#pragma once
#include "projectile.h"
#include "../mouse/mouse.h"

class PitchProjectile : public Projectile
{
private:
    Mouse *target;
    float initial_velocity_y;
public:
    PitchProjectile(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames, int velocity, int damage, Mouse* target);

    void UpdateBehave() override;

};

