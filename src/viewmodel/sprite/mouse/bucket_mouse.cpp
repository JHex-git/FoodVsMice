#include "bucket_mouse.h"

BucketMouse::BucketMouse(int x, int y) :
    Mouse(x, y, FRAME_RATE, HEALTH, VELOCITY, DAMAGE) {}

BucketMouse::BucketMouse(int x, int y, std::vector<QPixmap *> frames) :
    Mouse(x, y, DELTA_X, DELTA_Y,FRAME_RATE, frames, HEALTH, VELOCITY, DAMAGE) {}
