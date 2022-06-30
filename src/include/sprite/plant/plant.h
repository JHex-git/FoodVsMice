#pragma once
#include "sprite/sprite.h"

class Plant : public Sprite
{
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
    Plant(int x, int y, int health, float cool_down_time);

    Plant(int x, int y, std::vector<IMAGE *> frames, int health, float cool_down_time);
};