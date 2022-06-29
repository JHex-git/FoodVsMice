#include "sun/sun_manager.h"
#include "misc/common.h"

SunManager::SunManager(int initial_sun)
{
    ASSERT(initial_sun > 0, "Initial sun must no less than 0");
    sun_count = initial_sun;
}

// TODO: 随机
void SunManager::GenerateSun()
{
    int x, y;
    // x = Random::RandInt(GameManager::MIN_X + PADDING_X, GameManager::MAX_X - PADDING_X);
    // y = GameManager::MAX_Y + Sun::PADDING_Y;
    GenerateSun(x, y);
}

void SunManager::GenerateSun(int x, int y)
{
    Sun *sun = new Sun(x, y);
    sun_list.push_back(sun);
}

void SunManager::PickupSun(int x, int y)
{
    for (std::list<Sun *>::iterator it = sun_list.begin(); it != sun_list.end();)
    {
        std::list<Sun *>::iterator tmp = it;
        it++;
        if (abs((*tmp)->x -x) < Sun::PADDING_X && abs((*tmp)->y - y) < Sun::PADDING_Y)
        {
            sun_list.erase(tmp);
            IncreaseSun(SUN_UNIT);
            delete *tmp;
            break;
        }
    }
}

void SunManager::UpdateSun()
{
    for (std::list<Sun *>::iterator it = sun_list.begin(); it != sun_list.end();)
    {
        std::list<Sun *>::iterator tmp = it;
        it++;

        (*tmp)->Update();
        if (!(*tmp)->is_exist)
        {
            sun_list.erase(tmp);
            delete *tmp;
        }
    }
}

void SunManager::IncreaseSun(int num)
{
    ASSERT(num >= 0, "num must be non negative when increase!");
    sun_count += num;
}

bool SunManager::DecreaseSun(int num)
{
    if (sun_count < num)
        return false;

    sun_count -= num;
    return true;
}