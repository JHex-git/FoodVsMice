#pragma once
#include "mouse.h"

class NormalMouse : public Mouse
{
public:
    NormalMouse(int x, int y, std::vector<QPixmap *> frames);
};

