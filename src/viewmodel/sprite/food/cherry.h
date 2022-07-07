#pragma once
#include "food.h"

class Cherry : public Food
{
private:
    ProjectileManager *projectile_manager;

    bool CheckFunc() override;
    void Func() override;
public:
    Cherry(int x, int y, int row, std::vector<QPixmap *> frames, ProjectileManager *projectile_manager);
};
