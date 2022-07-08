#include "small_bread_card.h"

const int DELTA_X = -25;
const int DELTA_Y = -23;
const float COOLDOWN_TIME = 15;
const int FLAME_COST = 50;

SmallBreadCard::SmallBreadCard(FoodType food_type, int x, int y, QPixmap *img)
    : Card(food_type, x, y, DELTA_X, DELTA_Y, img, COOLDOWN_TIME, FLAME_COST) {}
