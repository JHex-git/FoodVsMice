#include "mouse_manager.h"
#include "../../../common/enums.h"
#include "bucket_mouse.h"
#include "football_mouse.h"
#include "normal_mouse.h"
#include "../../../common/map_transform.h"
#include "../../../common/debug.h"

const int RIGHT_MOST = 910;
MouseManager::MouseManager(TimeManager *time_manager) : time_manager(time_manager)
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
        if ((*tmp)->health <= 0)
        {
            mouse_list.erase(tmp);
            draw_mouse_list_ptr->erase(tmp_draw_it);
            delete *tmp;
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
        int y = MapTransform::Matrix2ViewportCenter(*tmp_line_it, 0).second;
        const std::vector<QPixmap *>&imgs = dict.find(*tmp_type_it)->second;

        // TODO: Add mouse type here
        switch (*tmp_type_it)
        {
            case MouseType::NORMAL_MOUSE:
                mouse = new NormalMouse(RIGHT_MOST, y, *tmp_line_it, imgs, food_manager);
                break;
            case MouseType::HELMET_MOUSE:
                DEBUG_INFO(imgs.size());
                mouse = new BucketMouse(RIGHT_MOST, y, *tmp_line_it, imgs, food_manager);
                break;
            case MouseType::FOOT_MOUSE:
                mouse = new FootballMouse(RIGHT_MOST, y, *tmp_line_it, imgs, food_manager);
                break;
        }
        if (mouse != nullptr)
        {
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
