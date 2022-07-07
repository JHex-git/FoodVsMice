#pragma once
#include "card.h"

class StoveCard : public Card
{
public:
    StoveCard(FoodType food_type, int x, int y, QPixmap *img);
};
