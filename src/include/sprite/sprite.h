#pragma once

#include <vector>
#include <graphics.h>
#include "misc/common.h"

// TODO: 更新图像是否要单拎出来
class Sprite
{
private:
    std::vector<IMAGE *> frames;
    int current_frame;

protected:
    int x, y;

public:
    Sprite() {};
    Sprite(int x, int y);
    Sprite(int x, int y, std::vector<IMAGE *> frames);
   
    // 添加图片帧
    void AddFrame(IMAGE *frame);

    // 更新图像并更新行为
    void Update();

    virtual void UpdateBehave() = 0;
};
