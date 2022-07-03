#include "stove.h"
#include "../flame/flame.h"

const int Stove::COOL_DOWN_TIME = 20;
const int Stove::FLAME_PADDING_X = 40;
const int Stove::FLAME_PADDING_Y = 40;
const int Stove::HEALTH = 100;

void Stove::Func()
{
    flame_manager->GenerateFlame(x + FLAME_PADDING_X, y + FLAME_PADDING_Y);
}

Stove::Stove(int x, int y, FlameManager *flame_manager) : 
    Food(x, y, HEALTH, COOL_DOWN_TIME), flame_manager(flame_manager) {}

Stove::Stove(int x, int y, std::vector<IMAGE *> frames, FlameManager *flame_manager) :
    Food(x, y, frames, HEALTH, COOL_DOWN_TIME), flame_manager(flame_manager) {}
