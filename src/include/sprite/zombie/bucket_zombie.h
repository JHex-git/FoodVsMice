#pragma once
#include "sprite/zombie/zombie.h"

class BucketZombie : public Zombie
{
private:
    static const int DAMAGE = 20;

public:
    BucketZombie(int x, int y, float frame_rate, int health, int velocity);

    BucketZombie(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int health, int velocity);
};