#pragma once
#include "../sprite.h"
#include "../../../common/map_transform.h"
#include "food_manager.h"
#include <QPixmap>

class Food : public Sprite
{
    friend class FoodManager;
private:

    int health;
    int func_start_index;
    int func_take_effect_index;
    bool start_func;
    int projectile_index;
    float cool_down_time;
    float current_cool_time; // 0是在冷却中

protected:
    int center_x;
    int center_y;
    int row;
    int column;
    int left_padding;
    int right_padding;

    void Update() override;
    void UpdateBehave() override;
    
    virtual bool CheckFunc() = 0;
    // 植物的功能函数
    virtual void Func() = 0;

public:
    Food(int x, int y, int health, float frame_rate, float cool_down_time);

    Food(int x, int y, int delta_x, int delta_y, int row, int column, int left_padding, int right_padding, float frame_rate, std::vector<QPixmap *> frames, int func_start_index, int func_take_effect_index, int projectile_index, int health, float cool_down_time);

    virtual ~Food() = default;

    void TakeDamage(int damage);

    int GetCenterX() { return MapTransform::Matrix2Viewport(row, column).first + MapTransform::GRID_WIDTH / 2; }
};
