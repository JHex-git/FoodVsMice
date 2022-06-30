#include "sprite/sun/sun_manager.h"
#include "GUI_manager.h"
#include <iostream>

int main()
{
    GUIManager *gui_manager = new GUIManager();
    gui_manager->loading();
    initgraph(820, 600);
    setbkcolor(WHITE);
    gui_manager->Draw_background();
    // std::vector<IMAGE *> sunflower_vec;
    // for (int i = 0; i < 8; ++i)
    // {
    //     sunflower_vec.push_back(&peashooter[i]);
    // }
    // // SunManager *sun_manager = new SunManager(50, sunflower_vec);
    
        // Sun *sun = new Sun(400, 500, sunflower_vec);
    // BeginBatchDraw();
    // while (1)
    // {
    //     Sleep(1000);
        gui_manager->drawAlpha(&normalZombieWalkPictures[0], 500, 500);
    //     sun->Update();
    //     // sun_manager->GenerateSun(100, 100);
    //     // sun_manager->UpdateSun();
    //     FlushBatchDraw();
    getchar();
     //}

    return 0;
}