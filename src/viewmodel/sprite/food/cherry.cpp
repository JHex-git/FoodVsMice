#include "cherry.h"

const int COOL_DOWN_TIME = 1;
const int HEALTH = 100;
const int DELTA_X = -20;
const int DELTA_Y = 5;

void Cherry::Func()
{

}

Cherry::Cherry(int x, int y, std::vector<QPixmap *> frames)
    : Food(x, y, DELTA_X, DELTA_Y, frames, HEALTH, COOL_DOWN_TIME) {}
