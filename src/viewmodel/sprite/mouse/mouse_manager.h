#pragma once
#include <list>
#include "mouse.h"
#include "../../../common/time_manager.h"
#include "../../../common/enums.h"
#include "../../../model/level/level_manager.h"
#include "../food/food_manager.h"
#include "../../pool_manager.h"

class FoodManager;
class PoolManager;

class MouseManager
{
private:
    TimeManager *time_manager;
    LevelManager *level_manager;
    FoodManager *food_manager;
    PoolManager *pool_manager;
    std::list<Mouse *> mouse_list;

    // for view
    std::shared_ptr<std::list<SpriteItem *>> draw_mouse_list_ptr;
    std::shared_ptr<Status> status_ptr;

    // from model
    std::shared_ptr<std::list<MouseType>> waiting_mouse_list_ptr;
    std::shared_ptr<std::list<float>> waiting_mouse_time_list_ptr;
    std::shared_ptr<std::list<int>> waiting_mouse_line_list_ptr;

// command
    std::function<std::pair<int, int>(int row_index, int column_index)> Matrix2Viewport;

public:
    MouseManager(TimeManager *time_manager, PoolManager *pool_manager);

    // 释放list中所有的mouse
    ~MouseManager();

    void PrepareMouse();

    void UpdateMouse();

    void Init(FoodManager *food_manager);

    // 返回在row行的x右边的最近的老鼠
    Mouse *GetLeftestMouse(int x, int row);

// properties
    // for view
    std::shared_ptr<std::list<SpriteItem *>> get_DrawMouseList() { return draw_mouse_list_ptr; }
    std::shared_ptr<Status> get_Status() { return status_ptr; }

    // from modeel
    void attach_LevelManager(LevelManager *p_level_manager) { level_manager = p_level_manager; }


// command
    void attach_Matrix2ViewportCommand(std::function<std::pair<int, int>(int row_index, int column_index)>&& func) { Matrix2Viewport = std::move(func); }

    std::function<void()> get_UpdateMiceCommand();
};
