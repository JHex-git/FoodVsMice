#pragma once
#include "card.h"

class SuperEggCard : public Card
{
public:
    SuperEggCard(FoodType food_type, int x, int y, QPixmap *img);
};
