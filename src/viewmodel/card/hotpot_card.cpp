#include "hotpot_card.h"

const int DELTA_X = -15;
const int DELTA_Y = 13;
const float COOLDOWN_TIME = 100;
const int FLAME_COST = 50;

HotpotCard::HotpotCard(FoodType food_type, int x, int y, QPixmap *img)
    : Card(food_type, x, y, DELTA_X, DELTA_Y, img, COOLDOWN_TIME, FLAME_COST) {}
