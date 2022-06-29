#include "sprite.h"

Sprite::Sprite(int x, int y) : x(x), y(y){}

Sprite::Sprite(int x, int y, std::vector<IMAGE *> frames) : 
    x(x), y(y), frames(frames) {};


void Sprite::AddFrame(IMAGE *frame)
{
    frames.push_back(frame);
}

void Sprite::Update()
{
    current_frame = (current_frame + 1) % frames.size();
    UpdateBehave();
}
