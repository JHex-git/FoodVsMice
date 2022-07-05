#include "mouse.h"
#include "../../../view/time_manager.h"

Mouse::Mouse(int x, int y, float frame_rate, int health, int velocity, int damage) :
    Sprite(x, y, frame_rate), health(health), velocity(velocity), damage(damage) {}

Mouse::Mouse(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames, int health, int velocity, int damage) :
        Sprite(x, y, delta_x, delta_y, frame_rate, frames), health(health), velocity(velocity), damage(damage) {}

// TODO: 需要添加食物在面前的判断
void Mouse::UpdateBehave()
{
    draw_item.x -= velocity * TimeManager::DELTA_TIME;
}

void Mouse::TakeDamage(int damage)
{
    health -= damage;
}
