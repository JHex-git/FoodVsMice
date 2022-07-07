#pragma once
#include "food.h"
#include "../projectile/horizontal_projectile.h"

class Cherry : public Food
{
private:
    ProjectileManager *projectile_manager;
    MouseManager *mouse_manager;

    bool CheckFunc() override;
    void Func() override;
public:
    Cherry(int x, int y, int row, int column, std::vector<QPixmap *> frames, MouseManager *mouse_manager, ProjectileManager *projectile_manager);
};
