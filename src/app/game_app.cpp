#include "game_app.h"
GameApp::GameApp(GUIManager *gui_manager, LevelManager *level_manager, TimeManager *time_manager) :
    gui_manager(gui_manager), level_manager(level_manager), time_manager(time_manager), flame_manager(100), pool_manager(PoolManager(level_manager)), mouse_manager(time_manager, &pool_manager), food_manager(7, 9, level_manager, &flame_manager, &mouse_manager, &projectile_manager)
{
}

void GameApp::Init()
{
// properties
    gui_manager->attach_DrawFoodList(food_manager.get_DrawFoodList());
    gui_manager->attach_DrawMouseList(mouse_manager.get_DrawMouseList());
    gui_manager->attach_SelectVector(food_manager.get_DrawCardVec());
    gui_manager->attach_AlreadyVector(food_manager.get_DrawCardMaskVec());
    gui_manager->attach_SunCost(food_manager.get_DrawCardCostVec());
    gui_manager->attach_SunSum(flame_manager.get_FlameCount());
    gui_manager->attach_DrawFlameList(flame_manager.get_DrawFlameList());
    gui_manager->attach_DrawProjectileList(projectile_manager.get_DrawProjectileList());
    gui_manager->attach_Status(mouse_manager.get_Status());
    food_manager.attach_LevelManager(level_manager);
    mouse_manager.attach_LevelManager(level_manager);
    flame_manager.attach_LevelManager(level_manager);

// command
    gui_manager->attach_PlaceFoodCommand(food_manager.get_PlaceFoodCommand());
    gui_manager->attach_UpdateFoodCommand(food_manager.get_UpdateFoodCommand());
    gui_manager->attach_UpdateCardCommand(food_manager.get_UpdateCardCommand());
    gui_manager->attach_RemoveFoodCommand(food_manager.get_RemoveFoodCommand());
    gui_manager->attach_InitCardCommand(food_manager.get_InitCardCommand());
    gui_manager->attach_UpdateMouseCommand(mouse_manager.get_UpdateMiceCommand());
    gui_manager->attach_UpdataUpdateProjectile(projectile_manager.get_UpdateProjectiles());
    gui_manager->attach_UpdateLevel(level_manager->get_UpdateLevelCommand());
    gui_manager->attach_PickupFlameCommand(flame_manager.get_PickupFlameCommand());
    gui_manager->attach_UpdateFlameCommand(flame_manager.get_UpdateFlameCommand());

    food_manager.Init();
    mouse_manager.Init(&food_manager);
    pool_manager.Init(&food_manager);
}
