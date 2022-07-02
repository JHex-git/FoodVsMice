#include "sprite/mouse/bucket_mouse.h"

BucketMouse::BucketMouse(int x, int y, float frame_rate, int health, int velocity) :
    Mouse(x, y, frame_rate, health, velocity, DAMAGE) {}

BucketMouse::BucketMouse(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int health, int velocity) :
    Mouse(x, y, frame_rate, frames, health, velocity, DAMAGE) {}