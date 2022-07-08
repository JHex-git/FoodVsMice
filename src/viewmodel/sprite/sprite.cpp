#include "sprite.h"
#include <iostream>

// be avoided
Sprite::Sprite(int x, int y, float frame_rate) : frame_rate(frame_rate)
{
    current_frame = 0;
    frame_accum = 0;
    sprite_item.x = x;
    sprite_item.y = y;
}

Sprite::Sprite(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames) :
    frame_rate(frame_rate), frames(frames)
{
    current_frame = 0;
    frame_accum = 0;
    sprite_item.x = x - delta_x;
    sprite_item.y = y - delta_y;
    sprite_item.img = frames[current_frame];
};

void Sprite::AddFrame(QPixmap *frame)
{
    frames.push_back(frame);
}

void Sprite::Update()
{
    frame_accum += frame_rate;
    if (frame_accum >= 1)
    {
        current_frame = (current_frame + 1) % frames.size();
        frame_accum = 0;
        sprite_item.img = frames[current_frame];
    }
    UpdateBehave();
}
