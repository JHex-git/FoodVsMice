#pragma once
#include "food.h"
#include "../flame/flame_manager.h"

class Stove : public Food
{
private:
    void Func() override;

    static const int COOL_DOWN_TIME;
    static const int FLAME_PADDING_X;
    static const int FLAME_PADDING_Y;
    static const int HEALTH;

    FlameManager *flame_manager;

public:
    Stove(int x, int y, FlameManager *flame_manager);

    Stove(int x, int y, std::vector<IMAGE *> frames, FlameManager *flame_manager);
};
