#pragma once
#include "card.h"

class FishCard : public Card
{
public:
    FishCard(FoodType food_type, int x, int y, QPixmap *img);
};

