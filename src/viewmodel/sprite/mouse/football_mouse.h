#pragma once
#include "mouse.h"

class FootballMouse : public Mouse
{
public:
    FootballMouse(int x, int y, std::vector<QPixmap *> frames);
};
