#pragma once
#include "card.h"

class EggCard : public Card
{
public:
    EggCard(FoodType food_type, int x, int y, QPixmap *img);
};
