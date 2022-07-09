#include "stove.h"
#include "../flame/flame.h"
const int COOL_DOWN_TIME = 10;
const int FLAME_PADDING_X = 10;
const int FLAME_PADDING_Y = 10;
const int HEALTH = 100;
const int DELTA_X = 20;
const int DELTA_Y = 62;
const int FUNC_START_INDEX = 12;
const int FUNC_TAKE_EFFECT_INDEX = 26;
const float FRAME_RATE = 1;
const int LEFT_PADDING = 20;
const int RIGHT_PADDING = 20;

const int FLAME_START = 29;

bool Stove::CheckFunc()
{
    return true;
}

void Stove::Func()
{
    flame_manager->GenerateFlame(center_x + FLAME_PADDING_X, center_y + FLAME_PADDING_Y);
}

Stove::Stove(int x, int y, float frame_rate, FlameManager *flame_manager) :
    Food(x, y, HEALTH, frame_rate, COOL_DOWN_TIME), flame_manager(flame_manager) {}

Stove::Stove(int x, int y, int row, int column, std::vector<QPixmap *> frames, FlameManager *flame_manager) :
    Food(x, y, DELTA_X, DELTA_Y, row, column, LEFT_PADDING, RIGHT_PADDING, FRAME_RATE, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, FLAME_START, HEALTH, COOL_DOWN_TIME), flame_manager(flame_manager) {}
