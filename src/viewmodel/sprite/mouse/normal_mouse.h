#pragma once
#include "mouse.h"

class NormalMouse : public Mouse
{
public:
    NormalMouse(int x, int y, int row, std::vector<QPixmap *> frames, FoodManager *food_manager);
};

