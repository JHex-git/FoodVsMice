#include "small_bread.h"

const int HEALTH = 300;
const int DELTA_X = 25;
const int DELTA_Y = 25;
const float FRAME_RATE = 0.75;
const int FUNC_START_INDEX = 12;
const int FUNC_TAKE_EFFECT_INDEX = 9;
const int PROJECTILE_START = 10;
const int COOL_DOWN_TIME = 10;
const int LEFT_PADDING = 20;
const int RIGHT_PADDING = 20;


SmallBread::SmallBread(int x, int y, int row, int column, std::vector<QPixmap *> frames)
    : Food(x, y, DELTA_X, DELTA_Y, row, column, LEFT_PADDING, RIGHT_PADDING, FRAME_RATE, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, PROJECTILE_START, HEALTH, COOL_DOWN_TIME) {}
