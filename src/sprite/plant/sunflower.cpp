#include "sprite/plant/sunflower.h"
#include "sprite/sun/sun.h"

const int Sunflower::COOL_DOWN_TIME = 20;
const int Sunflower::SUN_PADDING_X = 40;
const int Sunflower::SUN_PADDING_Y = 40;

void Sunflower::Func()
{
    sun_manager->GenerateSun(x + SUN_PADDING_X, y + SUN_PADDING_Y);
}

Sunflower::Sunflower(int x, int y, int health, SunManager *sun_manager) : 
    Plant(x, y, health, COOL_DOWN_TIME), sun_manager(sun_manager) {}

Sunflower::Sunflower(int x, int y, std::vector<IMAGE *> frames, int health, SunManager *sun_manager) :
    Plant(x, y, frames, health, COOL_DOWN_TIME), sun_manager(sun_manager) {}