#pragma once
#include "../sprite.h"
#include "food_manager.h"
#include <QPixmap>

class Food : public Sprite
{
    friend class FoodManager;
private:

    int health;
    int func_start_index;
    int func_take_effect_index;
    int projectile_index;
    float cool_down_time;
    float current_cool_time; // 0是在冷却中

protected:
    int row;

    void Update() override;
    void UpdateBehave() override;
    
    // 植物的功能函数
    virtual bool Func() = 0;

public:
    Food(int x, int y, int health, float cool_down_time);

    Food(int x, int y, int delta_x, int delta_y, int row, std::vector<QPixmap *> frames, int projectile_index, int health, float cool_down_time);

    void TakeDamage(int damage);
};
