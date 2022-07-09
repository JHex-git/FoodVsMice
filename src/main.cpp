#include "app/game_app.h"
#include "view/GUI_manager.h"
#include "model/level/level_manager.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIManager gui_manager;
    gui_manager.show();
    TimeManager time_manager;
    LevelManager level_manager;
    GameApp game_app(&gui_manager, &level_manager, &time_manager);
    game_app.Init();
    return a.exec();
}
