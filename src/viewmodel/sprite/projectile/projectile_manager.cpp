#include "projectile_manager.h"

ProjectileManager::ProjectileManager()
{
    draw_projectile_list_ptr = std::make_shared<std::list<DrawItem *>>();
}

void ProjectileManager::AddProjectile(Projectile *projectile)
{
    projectile_list.push_front(projectile);
}

void ProjectileManager::UpdateProjectiles()
{
    for (std::list<Projectile *>::iterator it = projectile_list.begin(); it != projectile_list.end();)
    {
        std::list<Projectile *>::iterator tmp_it = it++;
        if ((*tmp_it)->is_active)
        {
            (*tmp_it)->Update();
        }
        else
        {
            projectile_list.erase(tmp_it);
            // TODO: 加入对象池
            delete *tmp_it;
        }
    }
}
