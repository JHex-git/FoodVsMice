#pragma once
#include "food.h"
#include "../projectile/pitch_projectile.h"

class SuperEgg : public Food
{
private:
    ProjectileManager *projectile_manager;
    MouseManager *mouse_manager;
    Mouse *target = nullptr;

    bool CheckFunc() override;
    void Func() override;
public:
    SuperEgg(int x, int y, int row, int column, std::vector<QPixmap *> frames, MouseManager *mouse_manager, ProjectileManager *projectile_manager);
};

