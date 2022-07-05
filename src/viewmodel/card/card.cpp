#include "card.h"
#include "../../view/time_manager.h"
#include "../../common/debug.h"
Card::Card(FoodType food_type, int x, int y, int delta_x, int delta_y, QPixmap *img, float cooldown_time, int flame_cost) : food_type(food_type), cooldown_time(cooldown_time), flame_cost(flame_cost)
{
    card_img.img = img;
    card_img.x = x - delta_x;
    card_img.y = y - delta_y;

    // TODO: modify mask img here
    mask_img.img = new QPixmap();
    mask_img.x = x - MASK_DELTA_X;
    mask_img.y = y - MASK_DELTA_Y;
    wait_cooldown_time = 0;
//    DEBUG_INFO(cooldown_time);
//    DEBUG_INFO(this->cooldown_time);
}

void Card::Update()
{
    // TODO: update mask
    if (wait_cooldown_time > 0)
    {
        wait_cooldown_time -= TimeManager::DELTA_TIME;
    }
}

bool Card::Use()
{
    if (wait_cooldown_time <= 0)
    {
        DEBUG_INFO("Use");
        wait_cooldown_time = cooldown_time;
        DEBUG_INFO(wait_cooldown_time);
        return true;
    }
    return false;
}
