#pragma once
#include "../sprite.h"
#include "mouse_manager.h"
#include <vector>

class MouseManager; // forward declaration
class Mouse : public Sprite
{
    friend class MouseManager;

private:
    int health;
    int velocity;
    int damage;

public:
    Mouse(int x, int y, float frame_rate, int health, int velocity, int damage);

    Mouse(int x, int y, float frame_rate, std::vector<QPixmap *> frames, int health, int velocity, int damage);

    virtual void UpdateBehave();

    void TakeDamage(int damage);
};
