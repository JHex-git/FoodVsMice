#pragma once
#include "sprite/sprite.h"
#include "sprite/food/food_manager.h"

// class FoodManager; // 前向声明

class Food : public Sprite
{
    friend class FoodManager;
private:
    static constexpr float FRAME_RATE = 1;

    int health;
    float cool_down_time;
    float current_cool_time;

protected:
    void UpdateBehave() override;
    
    // 植物的功能函数
    virtual void Func() = 0;

public:
    Food(int x, int y, int health, float cool_down_time);

    Food(int x, int y, std::vector<IMAGE *> frames, int health, float cool_down_time);

    void TakeDamage(int damage);
};