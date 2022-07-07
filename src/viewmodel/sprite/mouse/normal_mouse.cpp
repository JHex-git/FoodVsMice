#include "normal_mouse.h"

const int FRAME_RATE = 16;
const int DAMAGE = 20;
const int HEALTH = 100;
const int VELOCITY = 2;
const int DELTA_X = 1;
const int DELTA_Y = 40;

NormalMouse::NormalMouse(int x, int y, int row, std::vector<QPixmap *> frames) :
    Mouse(x, y, DELTA_X, DELTA_Y, row, FRAME_RATE, frames, HEALTH, VELOCITY, DAMAGE) {}
