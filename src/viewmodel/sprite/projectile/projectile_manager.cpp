#include "projectile_manager.h"

ProjectileManager::ProjectileManager()
{
    draw_projectile_list_ptr = std::make_shared<std::list<DrawItem *>>();
}

void ProjectileManager::AddProjectile(Projectile *projectile)
{
    projectile_list.push_front(projectile);
    draw_projectile_list_ptr->push_front(&projectile->draw_item);
}

std::function<void()> ProjectileManager::get_UpdateProjectiles()
{
    return [this]()->void
    {
        std::list<DrawItem *>::iterator draw_it = draw_projectile_list_ptr->begin();
        for (std::list<Projectile *>::iterator it = projectile_list.begin(); it != projectile_list.end();)
        {
            std::list<DrawItem *>::iterator tmp_draw_it = draw_it++;
            std::list<Projectile *>::iterator tmp_it = it++;
            if ((*tmp_it)->is_active)
            {
                (*tmp_it)->Update();
            }
            else
            {
                projectile_list.erase(tmp_it);
                draw_projectile_list_ptr->erase(tmp_draw_it);
                // TODO: 加入对象池
                delete *tmp_it;
            }
        }
    };
}
