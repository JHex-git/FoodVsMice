#pragma once
#include "sprite/mouse/mouse.h"
#include "time_manager.h"
#include <list>

class MouseManager
{
private:
    TimeManager *time_manager;
    std::list<Mouse *> mouse_list;
    std::list<std::pair<MouseType, float>> waiting_mouse_list;

public:
    MouseManager(TimeManager *time_manager);

    // 释放list中所有的mouse
    ~MouseManager();

    void PrepareMouse();

    void UpdateMouse();
};