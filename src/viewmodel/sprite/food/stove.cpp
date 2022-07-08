#include "stove.h"
#include "../flame/flame.h"
const int COOL_DOWN_TIME = 20;
const int FLAME_PADDING_X = 40;
const int FLAME_PADDING_Y = 40;
const int HEALTH = 100;
const int DELTA_X = 37;
const int DELTA_Y = 66;
const int PROJECTILE_START = 100;
const int FUNC_START_INDEX = 20;
const int FUNC_TAKE_EFFECT_INDEX = 25;
const int LEFT_PADDING = 20;
const int RIGHT_PADDING = 20;

bool Stove::CheckFunc()
{
    return true;
}

void Stove::Func()
{
    flame_manager->GenerateFlame(center_x + FLAME_PADDING_X, center_y + FLAME_PADDING_Y);
}

Stove::Stove(int x, int y, FlameManager *flame_manager) : 
    Food(x, y, HEALTH, COOL_DOWN_TIME), flame_manager(flame_manager) {}

Stove::Stove(int x, int y, int row, int column, std::vector<QPixmap *> frames, FlameManager *flame_manager) :
    Food(x, y, DELTA_X, DELTA_Y, row, column, LEFT_PADDING, RIGHT_PADDING, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, PROJECTILE_START, HEALTH, COOL_DOWN_TIME), flame_manager(flame_manager) {}
