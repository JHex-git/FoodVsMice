#pragma once
#include "card.h"

class CherryCard : public Card
{
public:
    CherryCard(FoodType food_type, int x, int y, QPixmap *img);
};
