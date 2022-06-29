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
    static const float FRAME_RATE = 1;

    bool is_dropping;
    bool is_exist; // 指示阳光存在时间过久引起的消失问题
    float drop_duration;
    float current_exist_time;

public:
    Sun(int x, int y);
    Sun(int x, int y, std::vector<IMAGE *> frames);

    void UpdateBehave() override;

    ~Sun();
};