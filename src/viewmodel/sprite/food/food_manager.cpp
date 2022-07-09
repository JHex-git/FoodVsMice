#include "food_manager.h"
#include "../../../common/map_transform.h"
#include "../../../common/debug.h"
// add food here
#include "stove.h"
#include "cherry.h"
#include "egg.h"
#include "steam_drawer.h"
#include "fish.h"
#include "small_bread.h"
#include "super_egg.h"

// add card here
#include "../../card/stove_card.h"
#include "../../card/steamdrawer_card.h"
#include "../../card/hotpot_card.h"
#include "../../card/egg_card.h"
#include "../../card/cherry_card.h"
#include "../../card/fish_card.h"
#include "../../card/small_bread_card.h"
#include "../../card/super_egg_card.h"

const int GRID_WIDTH = 80;

FoodManager::FoodManager(int row_count, int column_count, LevelManager *level_manager, FlameManager *flame_manager, MouseManager *mouse_manager, ProjectileManager *projectile_manager) :
    level_manager(level_manager), flame_manager(flame_manager), mouse_manager(mouse_manager), projectile_manager(projectile_manager)
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

    draw_foodlist_ptr = std::make_shared<std::list<SpriteItem *>>();
    draw_card_vec_ptr = std::make_shared<std::vector<SpriteItem *>>();
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
        std::pair<int, int> coordinate = MapTransform::Index2Viewport(i);
        int x = coordinate.first;
        int y = coordinate.second;
        FoodType food_type = food_types[i];
        QPixmap *img = dict.find(food_type)->second[0];
        // TODO: add card here
        switch (food_type)
        {
            case (FoodType::SMALL_FIRE):
                card = new StoveCard(food_type, x, y, img);
                break;
            case (FoodType::HOTPOT):
                card = new HotpotCard(food_type, x, y, img);
                break;
            case (FoodType::STEAM_DRAWER):
                card = new SteamDrawerCard(food_type, x, y, img);
                break;
            case (FoodType::EGG):
                card = new EggCard(food_type, x, y, img);
                break;
            case (FoodType::CHERRY):
                card = new CherryCard(food_type, x, y, img);
                break;
            case (FoodType::FISH):
                card = new FishCard(food_type, x, y, img);
                break;
            case (FoodType::SMALL_BREAD):
                card = new SmallBreadCard(food_type, x, y, img);
                break;
            case (FoodType::SUPER_EGG):
                card = new SuperEggCard(food_type, x, y, img);
                break;

        }
        if (card != nullptr)
        {
            card_vec.push_back(card);
            draw_card_vec_ptr->push_back(&card->card_img);
            draw_card_mask_vec_ptr->push_back(&card->cooldown_ratio);
            draw_card_cost_vec_ptr->push_back(card->flame_cost);
        }
    }
}

Food *FoodManager::GetRightMostFood(int x, int row)
{
    Food *food = nullptr;
    for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end(); ++it)
    {
        if ((*it)->row == row)
        {
            if (food == nullptr && (*it)->center_x < x)
                food = *it;
            else if (food != nullptr)
            {
                if ((*it)->center_x < x && (*it)->center_x > food->center_x)
                    food = *it;
            }
        }
    }
    return food;
}

std::function<bool(int row_index, int column_index, int select_index)> FoodManager::get_PlaceFoodCommand()
{
    return [this](int row_index, int column_index, int select_index)->bool{
        if (row_index == -1) // Invalid grid
            return false;
        if (map_grids[row_index][column_index]) // 格子已经有食物
            return false;

        if (select_index >= card_vec.size()) // 没选中卡片
        {
            return false;
        }

        std::pair<int, int> coordinate = MapTransform::Matrix2ViewportCenter(row_index, column_index);
        int x = coordinate.first;
        int y = coordinate.second;


        Food *food = nullptr;
        FoodType food_type = level_manager->GetFoodTypes()[select_index];
        if (flame_manager->GetFlameCount() >= (*draw_card_cost_vec_ptr)[select_index]) // 火苗足够
        {
            if (card_vec[select_index]->Use()) // 卡片不在冷却
            {
                flame_manager->DecreaseFlame((*draw_card_cost_vec_ptr)[select_index]);
                const std::unordered_map<FoodType, std::vector<QPixmap *>>& dict = level_manager->GetFoodImages();
                const std::vector<QPixmap *>& imgs = (dict.find(food_type))->second;
                // TODO: Add food here
                switch (food_type)
                {
                    case FoodType::SMALL_FIRE:
                        food = new Stove(x, y, row_index, column_index, imgs, flame_manager);
                        map_grids[row_index][column_index] = true;
                        break;
                    case FoodType::CHERRY:
                        food = new Cherry(x, y, row_index, column_index, imgs, mouse_manager, projectile_manager);
                        map_grids[row_index][column_index] = true;
                        break;
                    case FoodType::EGG:
                        food = new Egg(x, y, row_index, column_index, imgs, mouse_manager, projectile_manager);
                        map_grids[row_index][column_index] = true;
                        break;
                    case (FoodType::STEAM_DRAWER):
                        food = new SteamDrawer(x, y, row_index, column_index, imgs, mouse_manager, projectile_manager);
                        map_grids[row_index][column_index] = true;
                        break;
                    case (FoodType::FISH):
                        food = new Fish(x, y, row_index, column_index, imgs, mouse_manager, projectile_manager);
                        map_grids[row_index][column_index] = true;
                        break;
                    case (FoodType::SMALL_BREAD):
                        food = new SmallBread(x, y, row_index, column_index, imgs);
                        map_grids[row_index][column_index] = true;
                        break;
                    case (FoodType::SUPER_EGG):
                        food = new SuperEgg(x, y, row_index, column_index, imgs, mouse_manager, projectile_manager);
                        map_grids[row_index][column_index] = true;
                        break;

                    default:
                        break;
                }
                if (food != nullptr)
                {
                    food_list.push_front(food);
                    draw_foodlist_ptr->push_front(&food->sprite_item);
                }
                return true;
            }
            else
                return false;
        }
        else
            return false;
    };
}

std::function<void()> FoodManager::get_UpdateFoodCommand()
{
    return [this]()->void{
        std::list<SpriteItem *>::iterator draw_it = draw_foodlist_ptr->begin();
        for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
        {
            std::list<Food *>::iterator tmp = it;
            std::list<SpriteItem *>::iterator draw_tmp = draw_it;
            it++;
            draw_it++;
            (*tmp)->Update();
            if ((*tmp)->health <= 0)
            {
                map_grids[(*tmp)->row][(*tmp)->column] = false;
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
//            std::list<SpriteItem *>::iterator draw_it = draw_foodlist.begin();
            std::list<SpriteItem *>::iterator draw_it = draw_foodlist_ptr->begin();
            for (std::list<Food *>::iterator it = food_list.begin(); it != food_list.end();)
            {
                std::list<Food *>::iterator tmp = it;
                std::list<SpriteItem *>::iterator draw_tmp = draw_it;
                it++;
                draw_it++;
                if ((*tmp)->row == row_index && (*tmp)->column == column_index)
                {
                    map_grids[row_index][column_index] = false;
                    food_list.erase(tmp);
                    draw_foodlist_ptr->erase(draw_tmp);
                    delete *tmp;
                    break;
                }
            }
        }
    };
}

std::function<void()> FoodManager::get_InitCardCommand()
{
    return [this]()->void
    {
        Init();
    };
}
