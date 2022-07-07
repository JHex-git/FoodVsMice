#include "cherry.h"

const int COOL_DOWN_TIME = 1;
const int HEALTH = 100;
const int DELTA_X = -20;
const int DELTA_Y = 5;
const int PROJECTILE_START = 10;
const int FUNC_START_INDEX = 20;
const int FUNC_TAKE_EFFECT_INDEX = 25;

bool Cherry::CheckFunc()
{
    return true;
}

void Cherry::Func()
{

}

Cherry::Cherry(int x, int y, int row, std::vector<QPixmap *> frames, ProjectileManager *projectile_manager)
    : Food(x, y, DELTA_X, DELTA_Y, row, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, PROJECTILE_START, HEALTH, COOL_DOWN_TIME), projectile_manager(projectile_manager) {}
