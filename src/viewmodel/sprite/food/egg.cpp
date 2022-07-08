#include "egg.h"

const int COOL_DOWN_TIME = 2;
const int HEALTH = 100;
const int DELTA_X = 15;
const int DELTA_Y = 35;
const float FRAME_RATE = 1;
const int FUNC_START_INDEX = 15;
const int FUNC_TAKE_EFFECT_INDEX = 20;

// projectile
const int PROJECTILE_DELTA_X = -10;
const int PROJECTILE_DELTA_Y = 1;
const int PROJECTILE_START = 26;
const int PROJECTILE_BOOM = 31;
const int PROJECTILE_VELOCITY_Y = 1000;
const int PROJECTILE_DAMAGE = 20;
const int PROJECTILE_LOW_BOUND_PADDING = -20;

bool Egg::CheckFunc()
{
    target = mouse_manager->GetLeftestMouse(draw_item.x, row);
    return target != nullptr;
}

void Egg::Func()
{
    std::vector<QPixmap *> imgs(frames.begin() + PROJECTILE_START, frames.end());
    if (target != nullptr)
    {
        PitchProjectile *projectile = new PitchProjectile(draw_item.x, draw_item.y, PROJECTILE_DELTA_X, PROJECTILE_DELTA_Y,
                                         FRAME_RATE, imgs, PROJECTILE_BOOM - PROJECTILE_START, PROJECTILE_VELOCITY_Y, PROJECTILE_DAMAGE, target, PROJECTILE_LOW_BOUND_PADDING);
        projectile_manager->AddProjectile(projectile);
    }
}



Egg::Egg(int x, int y, int row, int column, std::vector<QPixmap *> frames, MouseManager *mouse_manager, ProjectileManager *projectile_manager)
    : Food(x, y, DELTA_X, DELTA_Y, row, column, frames, FUNC_START_INDEX, FUNC_TAKE_EFFECT_INDEX, PROJECTILE_START, HEALTH, COOL_DOWN_TIME), mouse_manager(mouse_manager), projectile_manager(projectile_manager) {}
