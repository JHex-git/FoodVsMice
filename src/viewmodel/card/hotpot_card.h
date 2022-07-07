#pragma once
#include "card.h"

class HotpotCard : public Card
{
public:
    HotpotCard(FoodType food_type, int x, int y, QPixmap *img);
};
