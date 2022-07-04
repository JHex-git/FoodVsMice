#pragma once

#include <vector>
#include "../../common/common.h"
#include "../../common/draw_item.h"
#include <QPainter>

// TODO: 更新图像是否要单拎出来
class Sprite
{
private:
    std::vector<QPixmap *> frames;
    int current_frame;
    float frame_rate;   // 帧切换的速率
    float frame_accum;  // 每次增加frame_rate的量，大于1时会切换到下一帧

protected:
    int x, y;

public:
    Sprite(int x, int y, float frame_rate);
    Sprite(int x, int y, float frame_rate, std::vector<QPixmap *> frames);
   
    // 添加图片帧
    void AddFrame(QPixmap *frame);

    // 更新图像并更新行为
    void Update();

    virtual void UpdateBehave() = 0;
};