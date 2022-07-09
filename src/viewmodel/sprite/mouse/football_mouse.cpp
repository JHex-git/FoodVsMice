#include "football_mouse.h"

const int FRAME_RATE = 1;
const int DAMAGE = 20;
const int HEALTH = 300;
const int VELOCITY = 20;
const int DELTA_X = 40;
const int DELTA_Y = 100;
const int LEFT_PADDING = 20;
const int RIGHT_PADDING = 60;
const float ATTACK_INTERVAL = 1;


const int WALK_NORMAL_END = 7;

FootballMouse::FootballMouse(int x, int y, int row, std::vector<QPixmap *> frames, FoodManager *food_manager) :
    Mouse(x, y, DELTA_X, DELTA_Y, row, LEFT_PADDING, RIGHT_PADDING, FRAME_RATE, frames, HEALTH, VELOCITY, DAMAGE, ATTACK_INTERVAL, food_manager)
{
}
