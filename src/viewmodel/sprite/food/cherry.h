#pragma once
#include "food.h"

class Cherry : public Food
{
private:
    void Func() override;
public:
    Cherry(int x, int y, std::vector<QPixmap *> frames);
};
