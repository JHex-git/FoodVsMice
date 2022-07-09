#include "cherry_card.h"

const int DELTA_X = -30;
const int DELTA_Y = -8;
const float COOLDOWN_TIME = 5;
const int FLAME_COST = 100;

CherryCard::CherryCard(FoodType food_type, int x, int y, QPixmap *img)
    : Card(food_type, x, y, DELTA_X, DELTA_Y, img, COOLDOWN_TIME, FLAME_COST) {}
