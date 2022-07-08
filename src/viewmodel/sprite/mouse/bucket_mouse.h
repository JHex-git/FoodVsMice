#pragma once
#include "mouse.h"

class BucketMouse : public Mouse
{
public:
    BucketMouse(int x, int y);

    BucketMouse(int x, int y, int row, std::vector<QPixmap *> frames, FoodManager *food_manager);

};
