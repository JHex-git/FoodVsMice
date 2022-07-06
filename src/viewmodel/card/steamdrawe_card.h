#pragma once
#include "card.h"
#include "../../common/debug.h"

const float STEAM_DRAWER_COOLDOWN_TIME = 100;
const int STEAM_DRAWER_FLAME_COST = 50;
const int STEAM_DRAWER_DELTA_X = 1;
const int STEAM_DRAWER_DELTA_Y = 2;

class SteamDrawerCard : public Card
{
public:
    SteamDrawerCard(FoodType food_type, int x, int y, QPixmap *img)
        : Card(food_type, x, y, STEAM_DRAWER_DELTA_X, STEAM_DRAWER_DELTA_Y, img, STEAM_DRAWER_COOLDOWN_TIME, STEAM_DRAWER_FLAME_COST) {}
};
