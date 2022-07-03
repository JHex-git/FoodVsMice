#pragma once
#include "projectile.h"

class HorizontalProjectile : Projectile
{
public:
    HorizontalProjectile(int x, int y, float frame_rate, std::vector<QPixmap *> frames, int velocity, int damage) :
        Projectile(x, y, frame_rate, frames, velocity, damage) {}
    
    void UpdateBehave() override;
};
