#include "normal_mouse.h"

const int FRAME_RATE = 16;
const int DAMAGE = 20;
const int HEALTH = 200;
const int VELOCITY = 2;
const int DELTA_X = 1;
const int DELTA_Y = 80;
const int LEFT_PADDING = 20;
const int RIGHT_PADDING = 60;
const float ATTACK_INTERVAL = 1;

NormalMouse::NormalMouse(int x, int y, int row, std::vector<QPixmap *> frames, FoodManager *food_manager) :
    Mouse(x, y, DELTA_X, DELTA_Y, row, LEFT_PADDING, RIGHT_PADDING, FRAME_RATE, frames, HEALTH, VELOCITY, DAMAGE, ATTACK_INTERVAL, food_manager)
{
}
