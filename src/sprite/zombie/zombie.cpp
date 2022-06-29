#include "sprite/zombie/zombie.h"
#include "time_manager.h"

Zombie::Zombie(int x, int y, float frame_rate, int health, int velocity, int damage) :
    Sprite(x, y, frame_rate), health(health), velocity(velocity), damage(damage) {}

Zombie::Zombie(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int health, int velocity, int damage) :
        Sprite(x, y, frame_rate, frames), health(health), velocity(velocity), damage(damage) {}

// TODO: 需要添加植物在面前的判断
void Zombie::UpdateBehave()
{
    x -= velocity * TimeManager::DELTA_TIME;
}