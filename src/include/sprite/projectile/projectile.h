#pragma once
#include "sprite/sprite.h"

class Projectile : public Sprite
{
public:
    Projectile(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int velocity, int damage);

    virtual void UpdateBehave() = 0;

protected:
    int velocity;
    int damage;
};