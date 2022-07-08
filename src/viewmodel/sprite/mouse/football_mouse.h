#pragma once
#include "mouse.h"

class FootballMouse : public Mouse
{
public:
    FootballMouse(int x, int y, int row, std::vector<QPixmap *> frames, FoodManager *food_manager);
};
