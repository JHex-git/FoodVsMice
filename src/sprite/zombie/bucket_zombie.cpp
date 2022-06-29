#include "sprite/zombie/bucket_zombie.h"

BucketZombie::BucketZombie(int x, int y, float frame_rate, int health, int velocity) :
    Zombie(x, y, frame_rate, health, velocity, DAMAGE) {}

BucketZombie::BucketZombie(int x, int y, float frame_rate, std::vector<IMAGE *> frames, int health, int velocity) :
    Zombie(x, y, frame_rate, frames, health, velocity, DAMAGE) {}