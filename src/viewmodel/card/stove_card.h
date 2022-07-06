#pragma once
#include "card.h"
#include "../../common/debug.h"

const float STOVE_COOLDOWN_TIME = 100;
const int STOVE_FLAME_COST = 50;
const int STOVE_DELTA_X = -15;
const int STOVE_DELTA_Y = 13;

class StoveCard : public Card
{
public:
    StoveCard(FoodType food_type, int x, int y, QPixmap *img)
        : Card(food_type, x, y, STOVE_DELTA_X, STOVE_DELTA_Y, img, STOVE_COOLDOWN_TIME, STOVE_FLAME_COST) {}
};
