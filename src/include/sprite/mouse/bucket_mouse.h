#pragma once
#include "sprite/mouse/mouse.h"

class BucketMouse : public Mouse
{
private:
    static const int DAMAGE = 20;

public:
    BucketMouse(int x, int y, float frame_rate, int health, int velocity);

    BucketMouse(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int health, int velocity);

};