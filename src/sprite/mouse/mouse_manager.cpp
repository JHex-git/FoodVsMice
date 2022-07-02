#include "sprite/mouse/mouse_manager.h"
#include "misc/enums.h"
#include "sprite/mouse/bucket_mouse.h"

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

void MouseManager::PrepareMouse()
{
    // for (std::list<std::pair<MouseType, float>>::iterator it = waiting_mouse_list.begin(); it != waiting_mouse_list.end() && it->second <= ; it++)
    // {
    //     // TODO: Add mouse here
    //     Mouse *mouse = nullptr;
    //     switch (it->first)
    //     {
    //         case MouseType::BUCKET_MOUSE:
                
    //             // mouse = new BucketMouse()
    //             break;
            
    //         default:
    //             break;
    //     }
    //     mouse_list.push_front(mouse);
    // }
}