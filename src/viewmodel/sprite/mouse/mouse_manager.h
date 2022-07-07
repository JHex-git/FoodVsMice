#pragma once
#include <list>
#include "mouse.h"
#include "../../../view/time_manager.h"
#include "../../../common/enums.h"
#include "../../../model/level/level_manager.h"

class Mouse;

class MouseManager
{
private:
    TimeManager *time_manager;
    LevelManager *level_manager;
    std::list<Mouse *> mouse_list;

    // from view
    std::shared_ptr<std::list<DrawItem *>> draw_mouse_list_ptr;

    // from model
    std::shared_ptr<std::list<MouseType>> waiting_mouse_list_ptr;
    std::shared_ptr<std::list<float>> waiting_mouse_time_list_ptr;
    std::shared_ptr<std::list<int>> waiting_mouse_line_list_ptr;

// command
    std::function<std::pair<int, int>(int row_index, int column_index)> Matrix2Viewport;

public:
    MouseManager(TimeManager *time_manager);

    // 释放list中所有的mouse
    ~MouseManager();

    void PrepareMouse();

    void UpdateMouse();

    void Init();

    // 返回在row行的x右边的最近的老鼠
    Mouse *GetLeftestMouse(int x, int row);

// properties
    // for view
    std::shared_ptr<std::list<DrawItem *>> get_DrawMouseList() { return draw_mouse_list_ptr; }

    // from modeel
    void attach_LevelManager(LevelManager *p_level_manager) { level_manager = p_level_manager; }


// command
    void attach_Matrix2ViewportCommand(std::function<std::pair<int, int>(int row_index, int column_index)>&& func) { Matrix2Viewport = std::move(func); }

    std::function<void()> get_UpdateMiceCommand();
};
