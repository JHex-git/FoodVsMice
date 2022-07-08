#pragma once
#include "../sprite.h"
#include "mouse_manager.h"
#include <vector>

class MouseManager; // forward declaration
class FoodManager;

class Mouse : public Sprite
{
    friend class MouseManager;

private:
    int velocity;
    int damage;
    int row;
    float attack_interval;
    float current_waiting_attack_time; // 0表示刚进入冷却
    FoodManager *food_manager;

protected:
    int health;
    int center_x;
    int center_y;
    int left_padding;
    int right_padding;

public:
    Mouse(int x, int y, float frame_rate, int health, int velocity, int damage);

    Mouse(int x, int y, int delta_x, int delta_y, int row, int left_padding, int right_padding, float frame_rate, std::vector<QPixmap *> frames, int health, int velocity, int damage, float attack_interval, FoodManager* food_manager);

    virtual void UpdateBehave();

    virtual void TakeDamage(int damage);

    inline int GetX() { return center_x; }
    inline int GetRightX() { return center_x + right_padding; }
};
