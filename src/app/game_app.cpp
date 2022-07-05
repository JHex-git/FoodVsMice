#include "game_app.h"
#include "../common/debug.h"
GameApp::GameApp(GUIManager *gui_manager, LevelManager *level_manager, TimeManager *time_manager) :
    gui_manager(gui_manager), level_manager(level_manager), time_manager(time_manager), flame_manager(50, level_manager->GetFoodImages().find(FoodType::HOTPOT)->second), food_manager(7, 9, level_manager, &flame_manager), mouse_manager(time_manager)
{
}

void GameApp::Init()
{
// properties
    gui_manager->attach_DrawFoodList(food_manager.get_DrawFoodList());
    food_manager.attach_LevelManager(level_manager);

// command
    food_manager.attach_Matrix2ViewportCommand(gui_manager->get_Matrix2ViewportCommand());
    food_manager.attach_Viewport2MatrixCommand(gui_manager->get_Viewport2MatrixCommand());
    food_manager.attach_Index2ViewportCommand(gui_manager->get_Index2ViewportCommand());
    gui_manager->attach_PlaceFoodCommand(food_manager.get_PlaceFoodCommand());
    gui_manager->attach_UpdateFoodCommand(food_manager.get_UpdateFoodCommand());
    gui_manager->attach_UpdateCardCommand(food_manager.get_UpdateCardCommand());

    food_manager.Init();
}
