#include "mouse_manager.h"
#include "../../../common/enums.h"
#include "bucket_mouse.h"

const int RIGHT_MOST = 960;
MouseManager::MouseManager(TimeManager *time_manager) : time_manager(time_manager) {}

MouseManager::~MouseManager()
{
    for (std::list<Mouse *>::iterator it = mouse_list.begin(); it != mouse_list.end();)
    {
        std::list<Mouse *>::iterator tmp = it;
        it++;
        delete *tmp;
    }
}

void MouseManager::UpdateMouse()
{
    for (std::list<Mouse *>::iterator it = mouse_list.begin(); it != mouse_list.end();)
    {
        std::list<Mouse *>::iterator tmp = it;
        it++;
        (*tmp)->Update();
        if ((*tmp)->health <= 0)
        {
            mouse_list.erase(tmp);
            delete *tmp;
        }
    }
}

void MouseManager::Init()
{
//    waiting_mouse_list_ptr = level_manager->Getmouse_list();
}

void MouseManager::PrepareMouse()
{
//    for (std::list<std::pair<MouseType, float>>::iterator it = waiting_mouse_list.begin(); it != waiting_mouse_list.end() && it->second <= ; it++)
//    {
//         // TODO: Add mouse here
//         Mouse *mouse = nullptr;
//         switch (it->first)
//         {
//             case MouseType::BUCKET_MOUSE:

//                 // mouse = new BucketMouse()
//                 break;

//             default:
//                 break;
//         }
//         mouse_list.push_front(mouse);
//    }
    std::list<MouseType>::iterator type_it = waiting_mouse_list_ptr->begin();
    std::list<int>::iterator line_it = waiting_mouse_line_list_ptr->begin();
    const std::unordered_map<MouseType, std::vector<QPixmap *>>& dict = level_manager->GetMouseImages();

    for (std::list<float>::iterator time_it = waiting_mouse_time_list_ptr->begin(); time_it != waiting_mouse_time_list_ptr->end() && *time_it <= time_manager->GetCurrentSecond();)
    {
        std::list<MouseType>::iterator tmp_type_it = type_it++;
        std::list<int>::iterator tmp_line_it = line_it++;
        std::list<float>::iterator tmp_time_it = time_it++;

        Mouse *mouse = nullptr;
        int y = Matrix2Viewport(*tmp_line_it, 0).second;
        const std::vector<QPixmap *>&imgs = dict.find(*tmp_type_it)->second;

        // TODO: Add mouse type here
        switch (*tmp_type_it)
        {
            case MouseType::BUCKET_MOUSE:
                mouse = new BucketMouse(RIGHT_MOST, y, imgs);
                break;
        }
        if (mouse != nullptr)
        {
            mouse_list.push_front(mouse);
        }

        waiting_mouse_list_ptr->erase(tmp_type_it);
        waiting_mouse_line_list_ptr->erase(tmp_line_it);
        waiting_mouse_time_list_ptr->erase(tmp_time_it);
    }
}

std::function<void()> MouseManager::get_UpdateMiceCommand()
{
    return [this]()->void
    {
        PrepareMouse();
        UpdateMouse();
    };
}
