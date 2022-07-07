#include "bucket_mouse.h"

const int FRAME_RATE = 1;
const int DAMAGE = 20;
const int HEALTH = 100;
const int VELOCITY = 2;
const int DELTA_X = 1;
const int DELTA_Y = 1;
BucketMouse::BucketMouse(int x, int y) :
    Mouse(x, y, FRAME_RATE, HEALTH, VELOCITY, DAMAGE) {}

BucketMouse::BucketMouse(int x, int y, int row, std::vector<QPixmap *> frames) :
    Mouse(x, y, DELTA_X, DELTA_Y, row, FRAME_RATE, frames, HEALTH, VELOCITY, DAMAGE) {}
