#include "food_manager.h"
#include "../../../view/GUI_manager.h"
#include "stove.h"
#include "../../../common/debug.h"
#include "../../card/stove_card.h"

FoodManager::FoodManager(int row_count, int column_count, LevelManager *level_manager, FlameManager *flame_manager) :
    level_manager(level_manager), flame_manager(flame_manager)
{
    // 初始化map_grids
    map_grids.resize(row_count);
    for (int i = 0; i < row_count; i++)
    {
        map_grids[i].resize(column_count);
        for (int j = 0; j < column_count; j++)
        {
            map_grids[i][j] = false;
        }
    }

    draw_foodlist_ptr = std::make_shared<std::list<DrawItem *>>();
    draw_card_vec_ptr = std::make_shared<std::vector<DrawItem *>>();
    draw_card_mask_vec_ptr = std::make_shared<std::vector<float *>>();
    draw_card_cost_vec_ptr = std::make_shared<std::vector<int>>();
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

void FoodManager::Init()
{
    const std::vector<FoodType>& food_types = level_manager->GetFoodTypes();
    const std::unordered_map<FoodType, std::vector<QPixmap *>>& dict = level_manager->GetFoodImages();
    for (size_t i = 0; i < food_types.size(); ++i)
    {
        Card *card = nullptr;
        std::pair<int, int> coordinate = Index2Viewport(i);
        FoodType food_type = food_types[i];

        // TODO: add card here
        switch (food_type)
        {
            case (FoodType::HOTPOT):
                card = new StoveCard(food_type, coordinate.first, coordinate.second,dict.find(food_type)->second[0]);
                break;
        }
        if (card != nullptr)
        {
            card_vec.push_back(card);
            draw_card_vec_ptr->push_back(&card->card_img);
            draw_card_mask_vec_ptr->push_back(&card->cooldown_ratio);
        }
    }
}
//void FoodManager::UpdateFood()
//{
//    std::list<DrawItem *>::iterator draw_it = draw_foodlist.begin();
//    for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
//    {
//        std::list<Food *>::iterator tmp = it;
//        std::list<DrawItem *>::iterator draw_tmp = draw_it;
//        it++;
//        draw_it++;
//        (*tmp)->Update();
//        if ((*tmp)->health <= 0)
//        {
//            std::pair<int, int> coorinate = Viewport2Matrix((*tmp)->draw_item.x, (*tmp)->draw_item.y);
//            map_grids[coorinate.second][coorinate.first] = false;
//            food_list.erase(tmp);
//            draw_foodlist.erase(draw_tmp);
//            delete *tmp;
//        }
//    }
//}

//bool FoodManager::PlaceFood(int row_index, int column_index, FoodType food_type)
//{
//    ASSERT((size_t)row_index < map_grids.size() && (size_t)column_index < map_grids[0].size(), "Coordinate out of range!");
//    if (map_grids[row_index][column_index])
//        return false;

//    Food *food = nullptr;
//    // TODO: Add food here
//    std::pair<int, int> coordinate = Matrix2Viewport(row_index, column_index);

//    switch (food_type)
//    {
//        case FoodType::HOTPOT:
//            food = new Stove(coordinate.first, coordinate.second, (*img_dict_ptr)[food_type], flame_manager);
//            map_grids[row_index][column_index] = true;
//            break;
//        default:
//            break;
//    }
//    if (food != nullptr)
//    {
//        food_list.push_front(food);
//        draw_foodlist.push_front(&food->draw_item);
//    }
//    return true;
//}

//void FoodManager::RemoveFood(int row_index, int column_index)
//{
//    ASSERT((size_t)row_index < map_grids.size() && (size_t)column_index < map_grids[0].size(), "Coordinate out of range!");
//    if (map_grids[row_index][column_index])
//    {
//        std::list<DrawItem *>::iterator draw_it = draw_foodlist.begin();
//        for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
//        {
//            std::list<Food *>::iterator tmp = it;
//            std::list<DrawItem *>::iterator draw_tmp = draw_it;
//            it++;
//            draw_it++;
//            std::pair<int, int> coordinate = Viewport2Matrix((*tmp)->draw_item.x, (*tmp)->draw_item.y);
//            if (coordinate.first == row_index && coordinate.second == column_index)
//            {
//                map_grids[row_index][column_index] = false;
//                food_list.erase(tmp);
//                draw_foodlist.erase(draw_tmp);
//                delete *tmp;
//                break;
//            }
//        }
//    }
//}


std::function<bool(int row_index, int column_index, int select_index)> FoodManager::get_PlaceFoodCommand()
{
    return [this](int row_index, int column_index, int select_index)->bool{
        if (row_index == -1) // Invalid grid
            return false;
        std::pair<int, int> coordinate = Matrix2Viewport(row_index, column_index);

        if (map_grids[row_index][column_index]) // 格子已经有食物
            return false;


        if (select_index >= card_vec.size() || card_vec[select_index]->Use() == false) // 卡片还在冷却中
        {
            return false;
        }

        Food *food = nullptr;
        FoodType food_type = level_manager->GetFoodTypes()[select_index];
        const std::unordered_map<FoodType, std::vector<QPixmap *>>& dict = level_manager->GetFoodImages();
        // TODO: Add food here
        switch (food_type)
        {
            case FoodType::HOTPOT:
                food = new Stove(coordinate.first, coordinate.second, (dict.find(food_type))->second, flame_manager);
                map_grids[row_index][column_index] = true;
                break;
            default:
                break;
        }
        if (food != nullptr)
        {
            food_list.push_front(food);
//            draw_foodlist.push_front(&food->draw_item);
            draw_foodlist_ptr->push_front(&food->draw_item);
        }
        return true;
    };
}

std::function<void()> FoodManager::get_UpdateFoodCommand()
{
    return [this]()->void{
        std::list<DrawItem *>::iterator draw_it = draw_foodlist_ptr->begin();
        for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
        {
            std::list<Food *>::iterator tmp = it;
            std::list<DrawItem *>::iterator draw_tmp = draw_it;
            it++;
            draw_it++;
            (*tmp)->Update();
            if ((*tmp)->health <= 0)
            {
                std::pair<int, int> coorinate = Viewport2Matrix((*tmp)->draw_item.x, (*tmp)->draw_item.y);
                map_grids[coorinate.second][coorinate.first] = false;
                food_list.erase(tmp);
                draw_foodlist_ptr->erase(draw_tmp);
                delete *tmp;
            }
        }
    };
}

std::function<void()> FoodManager::get_UpdateCardCommand()
{
    return [this]()->void{
        // 更新所有卡片
        for (size_t i = 0; i < card_vec.size(); ++i)
        {
            card_vec[i]->Update();
        }
    };
}

std::function<void(int row_index, int column_index)> FoodManager::get_RemoveFoodCommand()
{
    return [this](int row_index, int column_index)->void{
        ASSERT((size_t)row_index < map_grids.size() && (size_t)column_index < map_grids[0].size(), "Coordinate out of range!");
        if (map_grids[row_index][column_index])
        {
//            std::list<DrawItem *>::iterator draw_it = draw_foodlist.begin();
            std::list<DrawItem *>::iterator draw_it = draw_foodlist_ptr->begin();
            for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
            {
                std::list<Food *>::iterator tmp = it;
                std::list<DrawItem *>::iterator draw_tmp = draw_it;
                it++;
                draw_it++;
                std::pair<int, int> coordinate = Viewport2Matrix((*tmp)->draw_item.x, (*tmp)->draw_item.y);
                if (coordinate.first == row_index && coordinate.second == column_index)
                {
                    map_grids[row_index][column_index] = false;
                    food_list.erase(tmp);
//                    draw_foodlist.erase(draw_tmp);
                    draw_foodlist_ptr->erase(draw_tmp);
                    delete *tmp;
                    break;
                }
            }
        }
    };
}
