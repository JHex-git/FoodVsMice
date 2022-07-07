#pragma once
#include "food.h"
#include "../projectile/pitch_projectile.h"

class Egg : public Food
{
private:
    ProjectileManager *projectile_manager;
    PitchProjectile *projectile;
    MouseManager *mouse_manager;
    Mouse *target = nullptr;

    bool CheckFunc() override;
    void Func() override;

public:
    Egg(int x, int y, int row, std::vector<QPixmap *> frames, MouseManager *mouse_manager, ProjectileManager *projectile_manager);
};
