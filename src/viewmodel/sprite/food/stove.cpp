#include "stove.h"
#include "../flame/flame.h"
const int Stove::COOL_DOWN_TIME = 20;
const int Stove::FLAME_PADDING_X = 40;
const int Stove::FLAME_PADDING_Y = 40;
const int Stove::HEALTH = 100;
const int Stove::DELTA_X = -3;
const int Stove::DELTA_Y = 28;
const int PROJECTILE_START = 100;
const int FUNC_START_INDEX = 20;
const int FUNC_TAKE_EFFECT_INDEX = 25;

bool Stove::CheckFunc()
{
    return true;
}

void Stove::Func()
{
    flame_manager->GenerateFlame(draw_item.x + FLAME_PADDING_X, draw_item.y + FLAME_PADDING_Y);
}

Stove::Stove(int x, int y, FlameManager *flame_manager) : 
    Food(x, y, HEALTH, COOL_DOWN_TIME), flame_manager(flame_manager) {}

Stove::Stove(int x, int y, int row, std::vector<QPixmap *> frames, FlameManager *flame_manager) :
    Food(x, y, DELTA_X, DELTA_Y, row, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, PROJECTILE_START, HEALTH, COOL_DOWN_TIME), flame_manager(flame_manager) {}
