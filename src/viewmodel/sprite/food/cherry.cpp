#include "cherry.h"

const int COOL_DOWN_TIME = 1;
const int HEALTH = 100;
const int DELTA_X = -20;
const int DELTA_Y = 5;
const float FRAME_RATE = 1;
const int FUNC_START_INDEX = 9;
const int FUNC_TAKE_EFFECT_INDEX = 9;

// projectile
const int PROJECTILE_DELTA_X = 0;
const int PROJECTILE_DELTA_Y = 1;
const int PROJECTILE_START = 9;
const int PROJECTILE_BOOM = 10;
const int PROJECTILE_VELOCITY = 1000;
const int PROJECTILE_DAMAGE = 20;
const int PROJECTILE_LEN = 20; // 太小会穿过

bool Cherry::CheckFunc()
{
    return mouse_manager->GetLeftestMouse(draw_item.x, row) != nullptr;
}

void Cherry::Func()
{
    DEBUG_INFO(frames.size());
    std::vector<QPixmap *> imgs(frames.begin() + PROJECTILE_START, frames.end());
    DEBUG_INFO(imgs.size());
    HorizontalProjectile *projectile = new HorizontalProjectile(draw_item.x, draw_item.y, PROJECTILE_DELTA_X, PROJECTILE_DELTA_Y, row, PROJECTILE_LEN,
                                          FRAME_RATE, imgs, PROJECTILE_BOOM - PROJECTILE_START, PROJECTILE_VELOCITY, PROJECTILE_DAMAGE, mouse_manager);
    projectile_manager->AddProjectile(projectile);
}

Cherry::Cherry(int x, int y, int row, int column, std::vector<QPixmap *> frames, MouseManager *mouse_manager, ProjectileManager *projectile_manager)
    : Food(x, y, DELTA_X, DELTA_Y, row, column, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, PROJECTILE_START, HEALTH, COOL_DOWN_TIME), projectile_manager(projectile_manager), mouse_manager(mouse_manager) {}
