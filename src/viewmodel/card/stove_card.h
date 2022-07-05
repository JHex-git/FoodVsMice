#pragma once
#include "card.h"
#include "../../common/debug.h"

const float COOLDOWN_TIME = 100;
class StoveCard : public Card
{
private:
    static const int DELTA_X = 1;
    static const int DELTA_Y = 2;
    static const int FLAME_COST = 50;
public:
    StoveCard(FoodType food_type, int x, int y, QPixmap *img)
        : Card(food_type, x, y, DELTA_X, DELTA_Y, img, COOLDOWN_TIME, FLAME_COST) {}
};
