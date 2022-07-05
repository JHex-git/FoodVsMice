#include "../view/GUI_manager.h"
#include "../viewmodel/sprite/food/food_manager.h"
#include "../viewmodel/sprite/flame/flame_manager.h"
#include "../viewmodel/sprite/mouse/mouse_manager.h"

// 当载入关卡的时候
class GameApp
{
public:
    GameApp(GUIManager* gui_manager, LevelManager *level_manager, TimeManager *time_manager);
    void Init();

private:
    GUIManager* gui_manager;
    LevelManager* level_manager;
    TimeManager *time_manager;
    FlameManager flame_manager;
    FoodManager food_manager;
    MouseManager mouse_manager;
};
