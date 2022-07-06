#pragma once
#include "card.h"
#include "../../common/debug.h"

const float HOTPOT_COOLDOWN_TIME = 100;
const int HOTPOT_FLAME_COST = 50;
const int HOTPOT_DELTA_X = -15;
const int HOTPOT_DELTA_Y = 13;

class HotpotCard : public Card
{
public:
    HotpotCard(FoodType food_type, int x, int y, QPixmap *img)
        : Card(food_type, x, y, HOTPOT_DELTA_X, HOTPOT_DELTA_Y, img, HOTPOT_COOLDOWN_TIME, HOTPOT_FLAME_COST) {}
};
