#pragma once
#include "projectile.h"

class HorizontalProjectile : Projectile
{
private:
    static const int DELTA_X = 1;
    static const int DELTA_Y = 1;
public:
    HorizontalProjectile(int x, int y, float frame_rate, std::vector<QPixmap *> frames, int velocity, int damage) :
        Projectile(x, y, DELTA_X, DELTA_Y, frame_rate, frames, velocity, damage) {}
    
    void UpdateBehave() override;
};
