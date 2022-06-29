#pragma once
#include "sprite/sprite.h"

class Sun : public Sprite
{
    friend class SunManager;

private:
    const float DURATION = 1;
    const float MIN_DROP_DURATION = 1;
    const float MAX_DROP_DURATION = 5;
    const int DROP_VELOCITY = 1;
    static const int PADDING_X = 1;
    static const int PADDING_Y = 1;

    bool is_dropping;
    bool is_exist; // 指示阳光存在时间过久引起的消失问题
    float drop_duration;
    float current_exist_time;

public:
    // 太阳花生成太阳时需要该接口
    Sun(int x, int y);

    void UpdateBehave() override;

    ~Sun();
};