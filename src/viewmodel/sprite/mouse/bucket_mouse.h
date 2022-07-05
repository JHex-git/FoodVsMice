#pragma once
#include "mouse.h"

class BucketMouse : public Mouse
{
private:
    static const int DAMAGE = 20;
    static constexpr float FRAME_RATE = 1;
    static const int HEALTH = 100;
    static const int VELOCITY = 20;
    static const int DELTA_X = 1;
    static const int DELTA_Y = 1;

public:
    BucketMouse(int x, int y);

    BucketMouse(int x, int y, std::vector<QPixmap *> frames);

};
