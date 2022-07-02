#pragma once
#include "sprite/projectile/projectile.h"

class HorizontalProjectile : Projectile
{
public:
    HorizontalProjectile(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int velocity, int damage) :
        Projectile(x, y, frame_rate, frames, velocity, damage) {}
    
    void UpdateBehave() override;
};