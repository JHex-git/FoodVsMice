#pragma once
#include "food.h"
#include "../flame/flame_manager.h"

class Stove : public Food
{
private:
    bool CheckFunc() override;
    void Func() override;

    FlameManager *flame_manager;

public:
    Stove(int x, int y, float frame_rate, FlameManager *flame_manager);

    Stove(int x, int y, int row, int column, std::vector<QPixmap *> frames, FlameManager *flame_manager);
};
