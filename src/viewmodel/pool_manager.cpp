#include "pool_manager.h"
// TODO: Add mouse here
#include "sprite/mouse/bucket_mouse.h"
#include "sprite/mouse/normal_mouse.h"
#include "sprite/mouse/football_mouse.h"
#include "../common/debug.h"
const int MIN_MOUSE_NUM = 5;
const int MIN_PROJECTILE_NUM = 10;
const int RIGHT_MOST = 960;

PoolManager::PoolManager(LevelManager *level_manager): level_manager(level_manager)
{

}

void PoolManager::Init(FoodManager *food_manager)
{
    this->food_manager = food_manager;
}

Mouse *PoolManager::FillMouse(MouseType mouse_type)
{
    DEBUG_INFO("Fill mouse");
    const std::unordered_map<MouseType, std::vector<QPixmap *>>& dict = level_manager->GetMouseImages();
    const std::vector<QPixmap *>&imgs = dict.find(mouse_type)->second;
    std::list<Mouse *>& mouse_list = mouse_pool.find(mouse_type)->second;
    DEBUG_INFO(imgs.size());
    for (int i = 0; i <= MIN_MOUSE_NUM; ++i)
    {
        Mouse *mouse = nullptr;
        switch (mouse_type)
        {
            case MouseType::NORMAL_MOUSE:
                mouse = new NormalMouse(RIGHT_MOST, 0, 0, imgs, food_manager);
                break;
            case MouseType::HELMET_MOUSE:
                mouse = new BucketMouse(RIGHT_MOST, 0, 0, imgs, food_manager);
                break;
            case MouseType::FOOT_MOUSE:
                mouse = new FootballMouse(RIGHT_MOST, 0, 0, imgs, food_manager);
                break;
        }
        if (mouse != nullptr)
        {
            if (i == MIN_MOUSE_NUM) return mouse;
            else mouse_list.push_back(mouse);
        }
    }
    return nullptr;
}

Mouse *PoolManager::FetchMouse(MouseType mouse_type)
{
    Mouse *result = nullptr;
    std::unordered_map<MouseType, std::list<Mouse *>>::iterator mouse_iter = mouse_pool.find(mouse_type);
    if (mouse_iter != mouse_pool.end()) // 池中有该list
    {
        DEBUG_INFO("list");
        if ((*mouse_iter).second.begin() != (*mouse_iter).second.end()) // list不为空
        {
            DEBUG_INFO("list not empty");
            result = (*mouse_iter).second.front();
            (*mouse_iter).second.pop_front();
        }
        else
        {
            DEBUG_INFO("list empty");
            result = FillMouse(mouse_type);
        }
    }
    else
    {
        DEBUG_INFO("No list");
        mouse_pool.insert(std::pair<MouseType, std::list<Mouse *>>(mouse_type, std::list<Mouse *>()));
        result = FillMouse(mouse_type);
    }
    return result;
}

Projectile *PoolManager::FillProjectile(ProjectileType projectile_type)
{
    std::list<Projectile *>& projectile_list = projectile_pool.find(projectile_type)->second;
    for (int i = 0; i <= MIN_PROJECTILE_NUM; ++i)
    {
        Projectile *projectile = nullptr;
        switch (projectile_type)
        {
//            case ProjectileType::NORMAL_MOUSE:
//                projectile = new NormalMouse();
//                break;
        }
        if (projectile != nullptr)
        {
            if (i == MIN_PROJECTILE_NUM) return projectile;
            else projectile_list.push_back(projectile);
        }
    }
    return nullptr;
}

Projectile *PoolManager::FetchProjectile(ProjectileType projectile_type)
{
    Projectile *result = nullptr;
    std::unordered_map<ProjectileType, std::list<Projectile *>>::iterator projectile_iter = projectile_pool.find(projectile_type);
    if (projectile_iter != projectile_pool.end()) // 池中有该list
    {
         if ((*projectile_iter).second.begin() != (*projectile_iter).second.end()) // list不为空
         {
             result = (*projectile_iter).second.front();
             (*projectile_iter).second.pop_front();
         }
         else
         {
            result = FillProjectile(projectile_type);
         }
    }
    else
    {
        projectile_pool.insert(std::pair<ProjectileType, std::list<Projectile *>>(projectile_type, std::list<Projectile *>()));
        result = FillProjectile(projectile_type);
    }
    return result;
}

void PoolManager::Return2Pool(Mouse *mouse)
{
    mouse->is_active = false;
    mouse_pool.find(mouse->GetType())->second.push_back(mouse);

}

void PoolManager::Return2Pool(Projectile *projectile)
{
    projectile->is_active = false;
    projectile_pool.find(projectile->GetType())->second.push_back(projectile);

}
