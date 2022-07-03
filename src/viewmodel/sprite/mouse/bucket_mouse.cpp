#include "bucket_mouse.h"

BucketMouse::BucketMouse(int x, int y) :
    Mouse(x, y, FRAME_RATE, HEALTH, VELOCITY, DAMAGE) {}

BucketMouse::BucketMouse(int x, int y, std::vector<IMAGE *> frames) :
    Mouse(x, y, FRAME_RATE, frames, HEALTH, VELOCITY, DAMAGE) {}
