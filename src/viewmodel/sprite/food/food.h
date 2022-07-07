#pragma once
#include "../sprite.h"
#include "food_manager.h"
#include <QPixmap>

class Food : public Sprite
{
    friend class FoodManager;
private:

    int health;
    float cool_down_time;
    float current_cool_time;

protected:
    int row;

    void UpdateBehave() override;
    
    // 植物的功能函数
    virtual bool Func() = 0;

public:
    Food(int x, int y, int health, float cool_down_time);

    Food(int x, int y, int delta_x, int delta_y, int row, std::vector<QPixmap *> frames, int health, float cool_down_time);

    void TakeDamage(int damage);
};
