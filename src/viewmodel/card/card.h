#pragma once
#include "../../common/enums.h"
#include "../../common/sprite_item.h"
#include <QPixmap>
class Card
{
    friend class FoodManager;
public:
    Card(FoodType food_type, int x, int y, int delta_x, int delta_y, QPixmap *img, float cooldown_time, int flame_cost);

    void Update();

    bool Use();
private:
    FoodType food_type;
    SpriteItem card_img;
    float cooldown_ratio; // 0为冷却好，1为刚进入冷却
    float cooldown_time;
    float wait_cooldown_time; // 0表示已经冷却好了
    int flame_cost;

    static const int MASK_DELTA_X = 1;
    static const int MASK_DELTA_Y = 1;
};
