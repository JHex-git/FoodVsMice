#include "steamdrawer_card.h"

const int DELTA_X = -28;
const int DELTA_Y = -17;
const float COOLDOWN_TIME = 5;
const int FLAME_COST = 50;

SteamDrawerCard::SteamDrawerCard(FoodType food_type, int x, int y, QPixmap *img)
    : Card(food_type, x, y, DELTA_X, DELTA_Y, img, COOLDOWN_TIME, FLAME_COST) {}
