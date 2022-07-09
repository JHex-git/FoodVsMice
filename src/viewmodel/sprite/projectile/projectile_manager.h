#pragma once
#include "projectile.h"
#include <list>
class ProjectileManager
{
private:
    std::list<Projectile *> projectile_list;

// properties
    std::shared_ptr<std::list<SpriteItem *>> draw_projectile_list_ptr;
public:
    ProjectileManager();

    ~ProjectileManager();

    // 将子弹加入子弹list进行管理
    void AddProjectile(Projectile *projectile);

// command
    // 更新子弹list中的所有子弹
    std::function<void()> get_UpdateProjectiles();

// properties
    std::shared_ptr<std::list<SpriteItem *>> get_DrawProjectileList() { return draw_projectile_list_ptr; }
};
