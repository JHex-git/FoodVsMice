#include "card/card.h"

Card::Card(FoodType food_type, IMAGE *pic, float cooldown_time, int flame_cost) : food_type(food_type), pic(pic), cooldown_time(cooldown_time), flame_cost(flame_cost)
{
    wait_cooldown_time = 0;
}