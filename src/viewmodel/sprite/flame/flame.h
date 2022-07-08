#pragma once
#include "../sprite.h"

class Flame : public Sprite
{
    friend class FlameManager;

private:
    bool is_dropping;
    bool is_exist; // 指示火苗存在时间过久引起的消失问题
    float drop_duration;
    float current_exist_time;
    int center_x;
    int center_y;

public:
    Flame(int x, int y);
    Flame(int x, int y, std::vector<QPixmap *> frames);

    void UpdateBehave() override;

    ~Flame();
};
