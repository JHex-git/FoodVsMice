#include "level_manager.h"
using namespace std;
// void LevelManager::SetLevelName(){//赋值每个关卡的名字，初始化的一部分
//     Files levelnames;
//     levelnames.getFiles("./levels");
//     for (auto i = levelnames.files.begin(); i !=levelnames.files.end(); i++)
//     {
//         Level *newlevel=new Level;
//         newlevel->setname((*i));
//         levels.push_back(newlevel);
//     }
// }

void LevelManager::ReadLevel(std::string level_name)//对指定的关卡名，进行读取关卡
{
    char path[] = "../resources/levels/", tmppath[200] = { 0 };
    strcat(strcat(tmppath, path), level_name.c_str());
    ifstream fp;
    fp.open(tmppath,ios::in);
    if(!fp.is_open()){
        cout << "opening failed." << endl;
        return;
    }
    char tempnum;
    int count=0;
    for (;;)// read background
    { 
        count++;
        cout << "count:" << count << endl;
        tempnum = fp.get();
        cout << "background:" << tempnum << endl;
        MapType i = (MapType)(tempnum - '0');
        QPixmap *background_game[5];
        switch (i)
        {
        case MapType::BASE:
            background_game[0] = new QPixmap;
            background_game[1] = new QPixmap;
            background_game[2] = new QPixmap;
            background_game[3] = new QPixmap;
            background_game[4] = new QPixmap;
            deletelist.push_back(background_game[0]);
            deletelist.push_back(background_game[1]);
            deletelist.push_back(background_game[2]);
            deletelist.push_back(background_game[3]);
            deletelist.push_back(background_game[4]);
            (*background_game[0]).load("../FoodVsMice/resources/picture/Screen/background_game1.png");
            (*background_game[1]).load("../FoodVsMice/resources/picture/Screen/lawnmower.png");
            (*background_game[2]).load("../FoodVsMice/resources/picture/Screen/1.png");
            (*background_game[3]).load("../FoodVsMice/resources/picture/Screen/2.png");
            (*background_game[4]).load("../FoodVsMice/resources/picture/Screen/3.png");
            map_img.push_back(background_game[0]);
            map_img.push_back(background_game[1]);
            map_img.push_back(background_game[2]);
            map_img.push_back(background_game[3]);
            map_img.push_back(background_game[4]);
            break;

        default:
            break;
        }
        tempnum = fp.get();
        if (tempnum == '\n') break;
    }
    count = 0;
    for (;;)//read plant
    {
        count++;
        cout << "count:" << count << endl;
        tempnum = fp.get();
        cout << "plant:" << tempnum << endl;
        FoodType i = (FoodType)(tempnum - '0');
        QPixmap *hotpot;
        QPixmap *hotpot_b;
        QPixmap *Cherry_tart;
        QPixmap *Cherry_b;
        QPixmap *Cherry_boom;
        QPixmap *Egg_pitcher;
        QPixmap *Eggs;
        QPixmap *Egg_boom;
        vector<QPixmap *> hot_pot;
        vector<QPixmap *> cherry;
        vector<QPixmap *> Eggs_pitcher;
        switch (i)
        {
        case FoodType::HOTPOT:
            hotpot = new QPixmap[13];
            hotpot_b = new QPixmap[42];
            loadImages(hotpot, "../FoodVsMice/resources/picture/food/Hots_pot/Hotpot/", 13, 1);
            loadImages(hotpot_b, "../FoodVsMice/resources/picture/food/Hots_pot/Hotpot_b/", 42, 14);
            for (auto j = 0; j < 13 ; j++){
                hot_pot.push_back(&hotpot[j]);
                deletelist.push_back(&hotpot[j]);
            }
            for (auto j = 0; j < 42 ; j++){
                hot_pot.push_back(&hotpot_b[j]);
                deletelist.push_back(&hotpot_b[j]);
            }
            food_types.push_back(FoodType::HOTPOT);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::HOTPOT,hot_pot));
            break;
        case FoodType::CHERRY:
            Cherry_tart = new QPixmap[9];
            Cherry_b = new QPixmap[1];
            Cherry_boom = new QPixmap[4]
            loadImages(Cherry_tart, "../FoodVsMice/resources/picture/food/Cherrys_tart/Cherry_tart/", 9, 1);
            loadImages(Cherry_b, "../FoodVsMice/resources/picture/food/Cherrys_tart/Cherry_b/", 1, 1);
            loadImages(Cherry_boom, "../FoodVsMice/resources/picture/food/Cherrys_tart/Cherry_boom/", 4, 2);
            for (auto j = 0; j < 9 ; j++){
                cherry.push_back(&Cherry_tart[j]);
                deletelist.push_back(&Cherry_tart[j]);
            }
            for (auto j = 0; j < 1 ; j++){
                cherry.push_back(&Cherry_b[j]);
                deletelist.push_back(&Cherry_b[j]);
            }
            for (auto j = 0; j < 4 ; j++){
                cherry.push_back(&Cherry_boom[j]);
                deletelist.push_back(&Cherry_boom[j]);
            }
            food_types.push_back(FoodType::CHERRY);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::CHERRY,cherry));
            break;
        case FoodType::EGG:
            Egg_pitcher = new QPixmap[26];
            Eggs = new QPixmap[5];
            Egg_boom = new QPixmap[6];
            loadImages(Egg_pitcher, "../FoodVsMice/resources/picture/food/Eggs_pitcher/Egg_pitcher/", 26, 1);
            loadImages(Eggs, "../FoodVsMice/resources/picture/food/Eggs_pitcher/Eggs/", 5, 1);
            loadImages(Egg_boom, "../FoodVsMice/resources/picture/food/Eggs_pitcher/Egg_boom/", 6, 1);
            for (auto j = 0; j < 26 ; j++){
                Eggs_pitcher.push_back(&Egg_pitcher[j]);
                deletelist.push_back(&Egg_pitcher[j]);
            }
            for (auto j = 0; j < 5 ; j++){
                Eggs_pitcher.push_back(&Eggs[j]);
                deletelist.push_back(&Eggs[j]);
            }
            for (auto j = 0; j < 6 ; j++){
                Eggs_pitcher.push_back(&Egg_boom[j]);
                deletelist.push_back(&Egg_boom[j]);
            }
            food_types.push_back(FoodType::EGG);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::EGG,Eggs_pitcher));
            break;
        default : break;
        }
        tempnum = fp.get();
        if (tempnum == '\n') break;
    }
    for (;;)//read mouse
    {
        tempnum = fp.get();
        cout << "mouse:" << tempnum << endl;
        MouseType i = (MouseType)(tempnum - '0');
        QPixmap *normal_walk1;
        QPixmap *normal_walk2;
        QPixmap *normal_eat1;
        QPixmap *normal_eat2;
        QPixmap *normal_die;
        vector<QPixmap *> normal_mouse;
        switch (i)
        {
        case MouseType::NORMAL_MOUSE:
            normal_walk1 = new QPixmap[8];
            normal_walk2 = new QPixmap[8];
            normal_eat1 = new QPixmap[4];
            normal_eat2 = new QPixmap[4];
            normal_die = new QPixmap[13];

            loadImages(normal_walk1, "../FoodVsMice/resources/picture/mouse/normal_mouse/normal_walk1/walk1_", 8, 1);
            loadImages(normal_walk2, "../FoodVsMice/resources/picture/mouse/normal_mouse/normal_walk2/walk2_", 8, 1);
            loadImages(normal_eat1, "../FoodVsMice/resources/picture/mouse/normal_mouse/normal_eat1/eat1_", 4, 1);
            loadImages(normal_eat2, "../FoodVsMice/resources/picture/mouse/normal_mouse/normal_eat2/eat2_", 4, 1);
            loadImages(normal_die, "../FoodVsMice/resources/picture/mouse/normal_mouse/normal_die/die_", 13, 1);
            
            for (auto j = 0; j < 8 ; j++){
                normal_mouse.push_back(&normal_walk1[j]);
                deletelist.push_back(&normal_walk1[j]);
            }
            for (auto j = 0; j < 8 ; j++){
                normal_mouse.push_back(&normal_walk2[j]);
                deletelist.push_back(&normal_walk2[j]);
            }
            for (auto j = 0; j < 4 ; j++){
                normal_mouse.push_back(&normal_eat1[j]);
                deletelist.push_back(&normal_eat1[j]);
            }
            for (auto j = 0; j < 4 ; j++){
                normal_mouse.push_back(&normal_eat2[j]);
                deletelist.push_back(&normal_eat2[j]);
            }
            for (auto j = 0; j < 13 ; j++){
                normal_mouse.push_back(&normal_die[j]);
                deletelist.push_back(&normal_die[j]);
            }
            mouse_types.push_back(MouseType::NORMAL_MOUSE);
            mouse_img_dict.insert(pair<MouseType, std::vector<QPixmap *>>(MouseType::NORMAL_MOUSE,normal_mouse));
            break;
        default:
            break;
        }
        tempnum = fp.get();
        if (tempnum == '\n') break;
    }
    for (;;)// read waves
    { 
        float now_wave;
        fp >> now_wave;
        cout<<"wavetime:"<<now_wave<<endl;
        waves.push_back(now_wave);
        tempnum = fp.get();
        if (tempnum == '\n') break;
    }
    for (int j = 0; j < waves.size() ; j++){//read every wave
        for (;;)
        {
            tempnum = fp.get();
            MouseType this_type = (MouseType)(tempnum - '0');
            mouse_list.push_back(this_type);
            cout <<"mousetype:"<< tempnum - '0' << endl;
            tempnum = fp.get();//空格
            float this_wave;
            fp >> this_wave;
            cout <<"wavetime:"<< this_wave << endl;
            mouse_come_time.push_back(this_wave);
            int this_line;
            fp >> this_line;
            cout << "line:" << this_line<<endl;
            mouse_line.push_back(this_line);
            tempnum = fp.get();//空格或者换行
            if (tempnum == '\n') break;
        }
    }


    fp.close();

}

// void LevelManager::WriteLevel(char name[]){
//     int i;
//     for (i = 0 ; i != levels.size() ; i++)
//     {
//         if(levels[i]->getname()==name){
//             break;
//         }
//     }
//     if(i==levels.size()){
//         std::cout<<"write a new level"<<std::endl;
//         Level *newlevel=new Level;
//         newlevel->setname(name);
//         newlevel->writelevel();
//         levels.push_back(newlevel);
//     }else
//     {
//         std::cout << "update an existed level" << std::endl;
//     }
// }

const std::unordered_map<FoodType, std::vector<QPixmap *>>& LevelManager::GetFoodImages()
{
    return food_img_dict;
}
const std::unordered_map<MouseType, std::vector<QPixmap *>>& LevelManager::GetMouseImages()
{
    return mouse_img_dict;
}
const std::list<float>& LevelManager::GetWaves()
{
    return waves;
}
const std::list<MouseType>& LevelManager::Getmouse_list()
{
    return mouse_list;
}
const std::list<float>& LevelManager::Getmouse_cometime()
{
    return mouse_come_time;
}
const std::list<int>& LevelManager::Getmouse_line()
{
    return mouse_line;
}
void LevelManager::DeleteImages()
{
    for (auto i = deletelist.begin(); i != deletelist.end();i++){
        delete (*i);
    }
}
void LevelManager::loadImages(QPixmap imgs[], char path[], int n, int begin)
{
    for (int i = 0; i < n; i++)
    {
        char tmpPath[200], frameNo[4];
        strcpy_s(tmpPath, 200, path);
        strcat(strcat(tmpPath, itoa(i + begin, frameNo, 10)), ".png");
        imgs[i].load(tmpPath);
    }
}