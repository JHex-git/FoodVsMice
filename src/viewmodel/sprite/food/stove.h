#pragma once
#include "food.h"
#include "../flame/flame_manager.h"

class Stove : public Food
{
private:
    bool CheckFunc() override;
    void Func() override;

    static const int COOL_DOWN_TIME;
    static const int FLAME_PADDING_X;
    static const int FLAME_PADDING_Y;
    static const int HEALTH;
    static const int DELTA_X;
    static const int DELTA_Y;

    FlameManager *flame_manager;

public:
    Stove(int x, int y, FlameManager *flame_manager);

    Stove(int x, int y, int row, int column, std::vector<QPixmap *> frames, FlameManager *flame_manager);
};
