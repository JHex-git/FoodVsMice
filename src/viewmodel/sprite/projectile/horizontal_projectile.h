#pragma once
#include "projectile.h"
#include "../mouse/mouse_manager.h"

class HorizontalProjectile : public Projectile
{
public:
    HorizontalProjectile(int x, int y, int delta_x, int delta_y, int muzzle_padding_x, int muzzle_padding_y, int row, int len, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage, MouseManager *mouse_manager);
    
    void UpdateBehave() override;
private:
    MouseManager *mouse_manager;
    int row;
    int len;

};
