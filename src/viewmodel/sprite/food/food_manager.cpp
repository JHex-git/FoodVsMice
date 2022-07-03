#include "food_manager.h"
#include "GUI_manager.h"
#include "sprite/food/stove.h"

FoodManager::FoodManager(int row_count, int column_count, LevelManager *level_manager, FlameManager *flame_manager) :
    level_manager(level_manager), flame_manager(flame_manager)
{
    // 初始化map_grids
    map_grids.resize(row_count);
    for (size_t i = 0; i < row_count; i++)
    {
        map_grids[i].resize(column_count);
        for (size_t j = 0; j < column_count; j++)
        {
            map_grids[i][j] = false;
        }
    }
}

FoodManager::~FoodManager()
{
    for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
    {
        std::list<Food *>::iterator tmp = it;
        it++;
        delete *tmp;
    }
}

void FoodManager::UpdateFood()
{
    for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
    {
        std::list<Food *>::iterator tmp = it;
        it++;
        (*tmp)->Update();
        if ((*tmp)->health <= 0)
        {
            std::pair<int, int> coorinate = GUIManager::positioning((*tmp)->x, (*tmp)->y);
            map_grids[coorinate.second][coorinate.first] = false;
            food_list.erase(tmp);
            delete *tmp;
        }
    }
}

bool FoodManager::PlaceFood(int row_index, int column_index, FoodType food_type)
{
    ASSERT(row_index < map_grids.size() && column_index < map_grids[0].size(), "Coordinate out of range!");
    if (map_grids[row_index][column_index])
        return false;

    Food *food = nullptr;
    // TODO: Add food here
    // TODO: Implement level manager here
    switch (food_type)
    {
        case FoodType::STOVE:
            // food = new Stove(x, y, level_manager->dict[food_type], flame_manager);
            map_grids[row_index][column_index] = true;
            break;
        default:
            break;
    }
}

void FoodManager::RemoveFood(int row_index, int column_index)
{
    ASSERT(row_index < map_grids.size() && column_index < map_grids[0].size(), "Coordinate out of range!");
    if (map_grids[row_index][column_index])
    {
        // TODO: positioning
        for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
        {
            std::list<Food *>::iterator tmp = it;
            it++;
            // 此处应用i,j==>格子中心坐标点
            // if (std::pair<int, int> ((*tmp)->x, (*tmp)->y) == GUIManager::positioning(row_index, column_index))
            // {
            //     map_grids[row_index][column_index] = false;
            //     food_list.erase(tmp);
            //     delete *tmp;
            //     break;
            // }
        }
    }
}
