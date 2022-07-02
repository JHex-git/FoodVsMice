#pragma once
#include "sprite/mouse/mouse.h"

class BucketMouse : public Mouse
{
private:
    static const int DAMAGE = 20;
    static constexpr float FRAME_RATE = 1;
    static const int HEALTH = 100;
    static const int VELOCITY = 20;

public:
    BucketMouse(int x, int y);

    BucketMouse(int x, int y, std::vector<IMAGE *> frames);

};