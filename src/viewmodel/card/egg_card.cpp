#include "egg_card.h"

const int DELTA_X = -10;
const int DELTA_Y = 23;
const float COOLDOWN_TIME = 3;
const int FLAME_COST = 80;

EggCard::EggCard(FoodType food_type, int x, int y, QPixmap *img)
    : Card(food_type, x, y, DELTA_X, DELTA_Y, img, COOLDOWN_TIME, FLAME_COST) {}
