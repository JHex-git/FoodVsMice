#include "flame_manager.h"
#include "../../../common/debug.h"
const int FLAME_START = 29;
const int PADDING_X = 20;
const int PADDING_Y = 20;
const int FLAME_UNIT = 50;

FlameManager::FlameManager(int initial_flame)
{
    ASSERT(initial_flame > 0, "Initial flame must no less than 0");
    flame_count_ptr = std::make_shared<int>();
    *flame_count_ptr = initial_flame;
    draw_flame_list_ptr = std::make_shared<std::list<SpriteItem *>>();
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
    if (frames.empty())
    {
        frames = level_manager->GetFoodImages().find(FoodType::SMALL_FIRE)->second;
        frames = std::vector<QPixmap *>(frames.begin() + FLAME_START, frames.end());
    }
    Flame *flame = new Flame(x, y, frames);
    draw_flame_list_ptr->push_front(&flame->sprite_item);
    flame_list.push_front(flame);
}

std::function<bool(int x, int y)> FlameManager::get_PickupFlameCommand()
{
    return [this](int x, int y)->bool
    {
        std::list<SpriteItem *>::iterator draw_it = draw_flame_list_ptr->begin();
        for (std::list<Flame *>::iterator it = flame_list.begin(); it != flame_list.end();)
        {
            std::list<Flame *>::iterator tmp = it++;
            std::list<SpriteItem *>::iterator draw_tmp = draw_it++;
            if (abs((*tmp)->center_x -x) < PADDING_X && abs((*tmp)->center_y - y) < PADDING_Y)
            {
                flame_list.erase(tmp);
                draw_flame_list_ptr->erase(draw_tmp);
                IncreaseFlame(FLAME_UNIT);
                delete *tmp;
                return true;
            }
        }
        return false;
    };
}

std::function<void()> FlameManager::get_UpdateFlameCommand()
{
    return [this]()->void
    {
        std::list<SpriteItem *>::iterator draw_it = draw_flame_list_ptr->begin();
        for (std::list<Flame *>::iterator it = flame_list.begin(); it != flame_list.end();)
        {
            std::list<Flame *>::iterator tmp = it++;
            std::list<SpriteItem *>::iterator draw_tmp = draw_it++;

            (*tmp)->Update();
            if (!(*tmp)->is_exist)
            {
                flame_list.erase(tmp);
                draw_flame_list_ptr->erase(draw_tmp);
                delete *tmp;
            }
        }
    };
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
