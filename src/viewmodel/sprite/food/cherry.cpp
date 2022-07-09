#include "cherry.h"

const int COOL_DOWN_TIME = 1;
const int HEALTH = 100;
const int DELTA_X = 20;
const int DELTA_Y = 43;
const float FRAME_RATE = 1;
const int FUNC_START_INDEX = 9;
const int FUNC_TAKE_EFFECT_INDEX = 9;
const int LEFT_PADDING = 20;
const int RIGHT_PADDING = 20;

// projectile
const int PROJECTILE_PADDING_X = 40; // 发射点的delta
const int PROJECTILE_PADDING_Y = 40;
const int PROJECTILE_DELTA_X = 0; // 图片的delta
const int PROJECTILE_DELTA_Y = 0;
const int PROJECTILE_START = 9;
const int PROJECTILE_BOOM = 10;
const int PROJECTILE_VELOCITY = 500;
const int PROJECTILE_DAMAGE = 20;
const int PROJECTILE_LEN = 20; // 太小会穿过

bool Cherry::CheckFunc()
{
    return mouse_manager->GetLeftestMouse(center_x, row) != nullptr;
}

void Cherry::Func()
{
    std::vector<QPixmap *> imgs(frames.begin() + PROJECTILE_START, frames.end());
    HorizontalProjectile *projectile = new HorizontalProjectile(center_x, center_y, PROJECTILE_DELTA_X, PROJECTILE_DELTA_Y, PROJECTILE_PADDING_X, PROJECTILE_PADDING_Y, row, PROJECTILE_LEN,
                                          FRAME_RATE, imgs, PROJECTILE_BOOM - PROJECTILE_START, PROJECTILE_VELOCITY, PROJECTILE_DAMAGE, mouse_manager);
    projectile_manager->AddProjectile(projectile);
}

Cherry::Cherry(int x, int y, int row, int column, std::vector<QPixmap *> frames, MouseManager *mouse_manager, ProjectileManager *projectile_manager)
    : Food(x, y, DELTA_X, DELTA_Y, row, column, LEFT_PADDING, RIGHT_PADDING, FRAME_RATE, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, PROJECTILE_START, HEALTH, COOL_DOWN_TIME), projectile_manager(projectile_manager), mouse_manager(mouse_manager) {}
