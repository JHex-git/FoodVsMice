#pragma once
#include "../../common/enums.h"

class Card
{
public:
    Card(FoodType food_type, IMAGE *pic, float cooldown_time, int flame_cost);

private:
    FoodType food_type;
    IMAGE *pic;
    float cooldown_time;
    float wait_cooldown_time; // 0表示已经冷却好了
    int flame_cost;
};
