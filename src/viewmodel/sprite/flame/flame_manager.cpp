#include "flame_manager.h"

FlameManager::FlameManager(int initial_flame, std::vector<QPixmap *> frames) : frames(frames)
{
    ASSERT(initial_flame > 0, "Initial flame must no less than 0");
    flame_count_ptr = std::make_shared<int>();
    *flame_count_ptr = initial_flame;
}

FlameManager::~FlameManager()
{
    for (std::list<Flame *>::iterator it = flame_list.begin(); it != flame_list.end();)
    {
        std::list<Flame *>::iterator tmp = it;
        it++;
        delete *tmp;
    }
}

// TODO: 随机
void FlameManager::GenerateFlame()
{
    int x, y;
    // x = Random::RandInt(GameManager::MIN_X + PADDING_X, GameManager::MAX_X - PADDING_X);
    // y = GameManager::MAX_Y + Flame::PADDING_Y;
    GenerateFlame(x, y);
}

void FlameManager::GenerateFlame(int x, int y)
{
    Flame *flame = new Flame(x, y, frames);
    flame_list.push_back(flame);
}

void FlameManager::PickupFlame(int x, int y)
{
    for (std::list<Flame *>::iterator it = flame_list.begin(); it != flame_list.end();)
    {
        std::list<Flame *>::iterator tmp = it;
        it++;
        if (abs((*tmp)->sprite_item.x -x) < Flame::PADDING_X && abs((*tmp)->sprite_item.y - y) < Flame::PADDING_Y)
        {
            flame_list.erase(tmp);
            IncreaseFlame(FLAME_UNIT);
            delete *tmp;
            break;
        }
    }
}

void FlameManager::UpdateFlame()
{
    for (std::list<Flame *>::iterator it = flame_list.begin(); it != flame_list.end();)
    {
        std::list<Flame *>::iterator tmp = it;
        it++;

        (*tmp)->Update();
        if (!(*tmp)->is_exist)
        {
            flame_list.erase(tmp);
            delete *tmp;
        }
    }
}

void FlameManager::IncreaseFlame(int num)
{
    ASSERT(num >= 0, "num must be non negative when increase!");
    *flame_count_ptr += num;
}

bool FlameManager::DecreaseFlame(int num)
{
    if (*flame_count_ptr < num)
        return false;

    *flame_count_ptr -= num;
    return true;
}
