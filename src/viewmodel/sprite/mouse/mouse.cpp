#include "mouse.h"
#include "../../../view/time_manager.h"

Mouse::Mouse(int x, int y, float frame_rate, int health, int velocity, int damage) :
    Sprite(x, y, frame_rate), health(health), velocity(velocity), damage(damage) {}

Mouse::Mouse(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int health, int velocity, int damage) :
        Sprite(x, y, frame_rate, frames), health(health), velocity(velocity), damage(damage) {}

// TODO: 需要添加食物在面前的判断
void Mouse::UpdateBehave()
{
    x -= velocity * TimeManager::DELTA_TIME;
}

void Mouse::TakeDamage(int damage)
{
    health -= damage;
}
