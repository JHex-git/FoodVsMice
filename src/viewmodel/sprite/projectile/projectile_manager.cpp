#include "projectile_manager.h"
#include "../../../common/debug.h"

ProjectileManager::ProjectileManager()
{
    draw_projectile_list_ptr = std::make_shared<std::list<SpriteItem *>>();
}

void ProjectileManager::AddProjectile(Projectile *projectile)
{
    projectile_list.push_front(projectile);
    draw_projectile_list_ptr->push_front(&projectile->sprite_item);
}

std::function<void()> ProjectileManager::get_UpdateProjectiles()
{
    return [this]()->void
    {
        std::list<SpriteItem *>::iterator draw_it = draw_projectile_list_ptr->begin();
        for (std::list<Projectile *>::iterator it = projectile_list.begin(); it != projectile_list.end();)
        {
            std::list<SpriteItem *>::iterator tmp_draw_it = draw_it++;
            std::list<Projectile *>::iterator tmp_it = it++;
            if ((*tmp_it)->is_active)
            {
                (*tmp_it)->Update();
            }
            else
            {
                projectile_list.erase(tmp_it);
                draw_projectile_list_ptr->erase(tmp_draw_it);
                DEBUG_INFO("9");
                // TODO: 加入对象池
                delete *tmp_it;
            }
        }
    };
}

ProjectileManager::~ProjectileManager()
{
    for (std::list<Projectile *>::iterator it = projectile_list.begin(); it != projectile_list.end(); it++)
    {
        std::list<Projectile *>::iterator tmp = it++;
        delete *tmp;
    }
}
