#pragma once
#include "sprite/sprite.h"
#include <vector>
class Zombie : public Sprite
{
private:
    int health;
    int velocity;
    int damage;

public:
    Zombie(int x, int y, float frame_rate, int health, int velocity, int damage);

    Zombie(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int health, int velocity, int damage);

    void UpdateBehave() = 0;
};