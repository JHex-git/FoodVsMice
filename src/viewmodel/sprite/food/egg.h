#pragma once
#include "food.h"

class Egg : public Food
{
private:
    void Func() override;
public:
    Egg(int x, int y, std::vector<QPixmap *> frames);
};
