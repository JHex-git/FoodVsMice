#pragma once
#include "mouse.h"

class BucketMouse : public Mouse
{
public:
    BucketMouse(int x, int y);

    BucketMouse(int x, int y, std::vector<QPixmap *> frames);

};
