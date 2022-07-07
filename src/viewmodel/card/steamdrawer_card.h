#pragma once
#include "card.h"

class SteamDrawerCard : public Card
{
public:
    SteamDrawerCard(FoodType food_type, int x, int y, QPixmap *img);
};
