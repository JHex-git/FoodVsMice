#pragma once
#include "projectile.h"

class HorizontalProjectile : Projectile
{
public:
    HorizontalProjectile(int x, int y, float frame_rate, std::vector<QPixmap *> frames, int velocity, int damage);
    
    void UpdateBehave() override;
};
