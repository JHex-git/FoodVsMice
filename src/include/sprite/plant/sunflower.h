#pragma once
#include "plant.h"
#include "sun/sun_manager.h"

class Sunflower : public Plant
{
private:
    void Func() override;

    static const int COOL_DOWN_TIME;
    static const int SUN_PADDING_X = 20;
    static const int SUN_PADDING_Y = 10;

    SunManager *sun_manager;

public:
    Sunflower(int x, int y, int health, SunManager *sun_manager);

    Sunflower(int x, int y, std::vector<IMAGE *> frames, int health, SunManager *sun_manager);
};