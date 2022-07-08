#pragma once
#include "card.h"

class SmallBreadCard : public Card
{
public:
    SmallBreadCard(FoodType food_type, int x, int y, QPixmap *img);
};
