#include "random.h"

std::default_random_engine Random::e;

void Random::Init()
{
    e.seed(time(NULL));
}

float Random::RandFloat(float min, float max)
{
    std::uniform_real_distribution<float> random_f(min, max);
    return random_f(e);
}

int Random::RandInt(int min, int max)
{
    std::uniform_int_distribution<int> random_int(min, max);
    return random_int(e);
}
