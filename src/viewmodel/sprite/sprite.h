#pragma once

#include <vector>
#include "../../common/sprite_item.h"
#include <QPixmap>

class Sprite
{
protected:
    int current_frame;
    float frame_rate;   // 帧切换的速率
    float frame_accum;  // 每次增加frame_rate的量，大于1时会切换到下一帧
    std::vector<QPixmap *> frames;
    SpriteItem sprite_item;

public:
    Sprite(int x, int y, float frame_rate);
    Sprite(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames);
   
    virtual ~Sprite() = default;
    // 添加图片帧
    void AddFrame(QPixmap *frame);

    // 更新图像并更新行为
    virtual void Update();

    virtual void UpdateBehave() = 0;
};
