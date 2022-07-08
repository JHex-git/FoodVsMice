#pragma once
#include "food.h"

class SmallBread : public Food
{
public:
    bool CheckFunc() { return false; }

    void Func() {}

    SmallBread(int x, int y, int row, int column, std::vector<QPixmap *> frames);
};
