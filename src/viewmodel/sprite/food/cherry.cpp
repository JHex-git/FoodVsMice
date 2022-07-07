#include "cherry.h"

const int COOL_DOWN_TIME = 1;
const int HEALTH = 100;
const int DELTA_X = -20;
const int DELTA_Y = 5;
const int PROJECTILE_START = 10;

bool Cherry::Func()
{

}

Cherry::Cherry(int x, int y, int row, std::vector<QPixmap *> frames, ProjectileManager *projectile_manager)
    : Food(x, y, DELTA_X, DELTA_Y, row, frames, PROJECTILE_START, HEALTH, COOL_DOWN_TIME), projectile_manager(projectile_manager) {}
