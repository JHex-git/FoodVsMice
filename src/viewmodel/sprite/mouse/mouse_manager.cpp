#include "mouse_manager.h"
#include "../../../common/enums.h"
#include "../../../common/debug.h"
#include "bucket_mouse.h"
#include "football_mouse.h"
#include "normal_mouse.h"
#include "../../../common/map_transform.h"

const int RIGHT_MOST = 910;
MouseManager::MouseManager(TimeManager *time_manager, PoolManager *pool_manager) : time_manager(time_manager), pool_manager(pool_manager)
{
    draw_mouse_list_ptr = std::make_shared<std::list<SpriteItem *>>();
    status_ptr = std::make_shared<Status>();
    *status_ptr = Status::NORMAL;
}

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
    if (mouse_list.begin() == mouse_list.end() && waiting_mouse_list_ptr->begin() == waiting_mouse_list_ptr->end())
    {
        *status_ptr = Status::WIN;
    }
    std::list<SpriteItem *>::iterator draw_it = draw_mouse_list_ptr->begin();
    for (std::list<Mouse *>::iterator it = mouse_list.begin(); it != mouse_list.end();)
    {
        std::list<Mouse *>::iterator tmp = it++;
        std::list<SpriteItem *>::iterator tmp_draw_it = draw_it++;
        (*tmp)->Update();
        if ((*tmp)->GetX() == 0)
        {
            *status_ptr = Status::LOSE;
        }
        if (!(*tmp)->is_active)
        {
            mouse_list.erase(tmp);
            draw_mouse_list_ptr->erase(tmp_draw_it);
            pool_manager->Return2Pool(*tmp);
        }
    }
}

void MouseManager::Init(FoodManager *food_manager)
{
    waiting_mouse_list_ptr = level_manager->Getmouse_list();

    waiting_mouse_time_list_ptr = level_manager->Getmouse_cometime();
    waiting_mouse_line_list_ptr = level_manager->Getmouse_line();

    this->food_manager = food_manager;
}

void MouseManager::PrepareMouse()
{
    std::list<MouseType>::iterator type_it = waiting_mouse_list_ptr->begin();
    std::list<int>::iterator line_it = waiting_mouse_line_list_ptr->begin();

    for (std::list<float>::iterator time_it = waiting_mouse_time_list_ptr->begin(); time_it != waiting_mouse_time_list_ptr->end() && *time_it <= time_manager->GetCurrentSecond();)
    {
        std::list<MouseType>::iterator tmp_type_it = type_it++;
        std::list<int>::iterator tmp_line_it = line_it++;
        std::list<float>::iterator tmp_time_it = time_it++;

        Mouse *mouse = nullptr;
        int y = MapTransform::Matrix2ViewportCenter(*tmp_line_it, 0).second;

        mouse = pool_manager->FetchMouse(*tmp_type_it);
        DEBUG_INFO(mouse->sprite_item.x);
        DEBUG_INFO(mouse->sprite_item.y);
        if (mouse != nullptr)
        {
            mouse->Reset(RIGHT_MOST, y, *tmp_line_it);
            mouse_list.push_front(mouse);
            draw_mouse_list_ptr->push_front(&mouse->sprite_item);
        }
        waiting_mouse_list_ptr->erase(tmp_type_it);
        waiting_mouse_line_list_ptr->erase(tmp_line_it);
        waiting_mouse_time_list_ptr->erase(tmp_time_it);
    }
}

Mouse *MouseManager::GetLeftestMouse(int x, int row)
{
    Mouse *mouse = nullptr;
    for (std::list<Mouse *>::iterator it = mouse_list.begin(); it != mouse_list.end(); ++it)
    {
        if ((*it)->row == row)
        {
            if (mouse == nullptr && (*it)->GetX() + (*it)->right_padding > x) mouse = *it;
            else if (mouse != nullptr)
            {
                if ((*it)->GetX() + (*it)->right_padding > x && (*it)->GetX() < mouse->GetX()) mouse = *it;
            }
        }
    }
    return mouse;
}

std::function<void()> MouseManager::get_UpdateMiceCommand()
{
    return [this]()->void
    {
        PrepareMouse();
        UpdateMouse();
    };
}
