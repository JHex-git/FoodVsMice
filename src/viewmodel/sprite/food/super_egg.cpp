#include "super_egg.h"

const int COOL_DOWN_TIME = 1;
const int HEALTH = 100;
const int DELTA_X = 65;
const int DELTA_Y = 73;
const float FRAME_RATE = 1;
const int FUNC_START_INDEX = 15;
const int FUNC_TAKE_EFFECT_INDEX = 20;
const int LEFT_PADDING = 20;
const int RIGHT_PADDING = 20;

// projectile
const int PROJECTILE_PADDING_X = 30; // 发射点的delta
const int PROJECTILE_PADDING_Y = 110;
const int PROJECTILE_DELTA_X = 10;
const int PROJECTILE_DELTA_Y = 1;
const int PROJECTILE_START = 26;
const int PROJECTILE_BOOM = 31;
const int PROJECTILE_VELOCITY_Y = 500;
const int PROJECTILE_DAMAGE = 60;
const int PROJECTILE_LOW_BOUND_PADDING = -100;

bool SuperEgg::CheckFunc()
{
    target = mouse_manager->GetLeftestMouse(center_x, row);
    return target != nullptr;
}

void SuperEgg::Func()
{
    std::vector<QPixmap *> imgs(frames.begin() + PROJECTILE_START, frames.end());
    if (target != nullptr)
    {
        PitchProjectile *projectile = new PitchProjectile(center_x, center_y, PROJECTILE_DELTA_X, PROJECTILE_DELTA_Y, PROJECTILE_PADDING_X, PROJECTILE_PADDING_Y,
                                         FRAME_RATE, imgs, PROJECTILE_BOOM - PROJECTILE_START, PROJECTILE_VELOCITY_Y, PROJECTILE_DAMAGE, target, PROJECTILE_LOW_BOUND_PADDING);
        projectile_manager->AddProjectile(projectile);
    }
}

SuperEgg::SuperEgg(int x, int y, int row, int column, std::vector<QPixmap *> frames, MouseManager *mouse_manager, ProjectileManager *projectile_manager)
    : Food(x, y, DELTA_X, DELTA_Y, row, column, LEFT_PADDING, RIGHT_PADDING, FRAME_RATE, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, PROJECTILE_START, HEALTH, COOL_DOWN_TIME), mouse_manager(mouse_manager), projectile_manager(projectile_manager) {}
