#include "football_mouse.h"

const int FRAME_RATE = 1;
const int DAMAGE = 20;
const int HEALTH = 100;
const int VELOCITY = 20;
const int DELTA_X = 1;
const int DELTA_Y = 1;

FootballMouse::FootballMouse(int x, int y, int row, std::vector<QPixmap *> frames) :
    Mouse(x, y, DELTA_X, DELTA_Y,FRAME_RATE, row, frames, HEALTH, VELOCITY, DAMAGE) {}
