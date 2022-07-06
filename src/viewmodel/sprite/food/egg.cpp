#include "egg.h"

const int COOL_DOWN_TIME = 1;
const int HEALTH = 100;
const int DELTA_X = 15;
const int DELTA_Y = 35;

void Egg::Func()
{

}

Egg::Egg(int x, int y, std::vector<QPixmap *> frames)
    : Food(x, y, DELTA_X, DELTA_Y, frames, HEALTH, COOL_DOWN_TIME) {}
