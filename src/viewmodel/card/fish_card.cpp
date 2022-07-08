#include "fish_card.h"

const int DELTA_X = -23;
const int DELTA_Y = -15;
const float COOLDOWN_TIME = 15;
const int FLAME_COST = 300;

FishCard::FishCard(FoodType food_type, int x, int y, QPixmap *img)
    : Card(food_type, x, y, DELTA_X, DELTA_Y, img, COOLDOWN_TIME, FLAME_COST) {}
