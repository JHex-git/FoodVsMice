#pragma once
#include "sprite/projectile/projectile.h"
#include "sprite/mouse/mouse.h"
#include "../model/level/level_manager.h"
#include "../common/enums.h"

/**
 * @brief Use memory pool to decrease cost of allocating and deallocating memory
 * There are frequent new and delete oprations on projectile and mouse, so use memory pool to optimize it.
 */
class PoolManager
{
private:
    /**
     * @brief Fill Mouse into pool
     * new some mouse, fill all of them except one into pool and return that one
     * @param mouse_type
     * @return
     */
    Mouse *FillMouse(MouseType mouse_type);

    Projectile *FillProjectile(ProjectileType projectile_type);

    std::unordered_map<ProjectileType, std::list<Projectile *>> projectile_pool;

    std::unordered_map<MouseType, std::list<Mouse *>> mouse_pool;

    LevelManager *level_manager;

    FoodManager *food_manager;

public:
    PoolManager(LevelManager *level_manager);

    void Init(FoodManager *food_manager);

    /**
     * @brief Fill basic number of objects into pool
     */
    void Initialize(std::vector<MouseType> mouse_type_vec);

    /**
     * @brief Fetch a mouse in the pool
     * Fetch a mouse according to the mouse_type. If there is no such mouse,
     * new some and push all of them except one into the pool and return the one.
     * @note Be sure to reset mouse before use it.
     * @return mouse of specified MouseType
     */
    Mouse *FetchMouse(MouseType mouse_type);

    /**
     * @brief Fetch a projectile in the pool
     * Fetch a projectile according to the projectile_type. If there is no such projectile,
     * new some and push all of them except one into the pool and return the one.
     * @param projectile_type
     * @note Be sure to reset projectile before use it.
     * @return projectile of specified ProjectileType.
     */
    Projectile *FetchProjectile(ProjectileType projectile_type);

    /**
     * @brief Return2Pool
     * return used object to pool
     */
    void Return2Pool(Mouse *mouse);
    void Return2Pool(Projectile *projectile);
};
