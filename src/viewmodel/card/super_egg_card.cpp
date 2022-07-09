#include "super_egg_card.h"

const int DELTA_X = 0;
const int DELTA_Y = 20;
const float COOLDOWN_TIME = 15;
const int FLAME_COST = 350;

SuperEggCard::SuperEggCard(FoodType food_type, int x, int y, QPixmap *img)
    : Card(food_type, x, y, DELTA_X, DELTA_Y, img, COOLDOWN_TIME, FLAME_COST) {}
