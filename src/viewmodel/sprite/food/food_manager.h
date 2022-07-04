#pragma once
#include <list>
#include "food.h"
#include "../../../common/enums.h"
#include "../../../model/level/level_manager.h"
#include "../flame/flame_manager.h"
#include "../../../common/draw_item.h"
class Food;

class FoodManager
{
private:
    std::vector<std::vector<bool> > map_grids; // 用于指示地图上某格是否放有食物
    std::list<Food *> food_list; // 所有放在地图上的食物
    LevelManager *level_manager;
    FlameManager *flame_manager;
    std::list<DrawItem *> draw_foodlist;

public:
    /*** 
     * 控制所有放下的食物
     * @param {int} row_count 关卡地图的行数
     * @param {int} column_count 关卡地图的列数
     */    
    FoodManager(int row_count, int column_count, LevelManager *level_manager, FlameManager *flame_manager);

    /*** 
     * 销毁所有的食物
     */    
    ~FoodManager();
    /*** 
     * 更新所有食物的图片及行为
     */    
    void UpdateFood();

    /*** 
     * 判断该位置是否为空，空则放置食物并返回true，否则返回false 
     * 卡片是否冷却中不由该函数判断
     */
    bool PlaceFood(int row_index, int column_index, FoodType food_type);

    /*** 
     * 移除食物（铲子）
     */    
    void RemoveFood(int row_index, int column_index);

// properties
    std::shared_ptr<std::list<DrawItem *>> get_DrawFoodList() {return std::make_shared<std::list<DrawItem *>>(draw_foodlist);}
};