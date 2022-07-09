#include "card.h"
#include "../../common/time_manager.h"
Card::Card(FoodType food_type, int x, int y, int delta_x, int delta_y, QPixmap *img, float cooldown_time, int flame_cost) : food_type(food_type), cooldown_time(cooldown_time), flame_cost(flame_cost)
{
    card_img.img = img;
    card_img.x = x - delta_x;
    card_img.y = y - delta_y;

    wait_cooldown_time = 0;
    cooldown_ratio = 0;
}

void Card::Update()
{
    if (wait_cooldown_time > 0)
    {
        wait_cooldown_time -= TimeManager::DELTA_TIME;
        if (wait_cooldown_time < 0) wait_cooldown_time = 0;
        cooldown_ratio = wait_cooldown_time / cooldown_time;
    }
}

bool Card::Use()
{
    if (wait_cooldown_time <= 0)
    {
        wait_cooldown_time = cooldown_time;
        cooldown_ratio = 1;
        return true;
    }
    return false;
}
