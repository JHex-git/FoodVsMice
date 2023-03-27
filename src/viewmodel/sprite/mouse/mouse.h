#pragma once
#include "../sprite.h"
#include "../../../common/enums.h"
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
    bool is_eating;
//    bool is_active;
    int anim_up_bound;
    int anim_down_bound;
    FoodManager *food_manager;
    MouseType type;

protected:
    int health;
    int center_x;
    int center_y;
    int left_padding;
    int right_padding;

public:
    bool is_active;

    Mouse(int x, int y, float frame_rate, int health, int velocity, int damage);

    Mouse(int x, int y, int delta_x, int delta_y, int row, int left_padding, int right_padding, float frame_rate, std::vector<QPixmap *> frames, int health, int velocity, int damage, float attack_interval, FoodManager* food_manager);

    virtual ~Mouse() = default;

    void Reset(int x, int y, int row);

    virtual void Update();

    virtual void UpdateBehave();

    virtual void TakeDamage(int damage);

    inline int GetX() { return center_x; }
    inline int GetRightX() { return center_x + right_padding; }

    inline MouseType GetType() { return type; }
};
