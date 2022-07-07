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
LevelManager::LevelManager()
{
    mouse_list_ptr = std::make_shared<std::list<MouseType>>();
    mouse_come_time_ptr = std::make_shared<std::list<float>>();
    mouse_line_ptr = std::make_shared<std::list<int>>();
}
LevelManager::~LevelManager()
{
    DeleteImages();
}
void LevelManager::clearlist()
{
    mouse_list_ptr->clear();
    mouse_come_time_ptr->clear();
    mouse_line_ptr->clear();
    map_img.clear();
    food_img_dict.clear();
    mouse_img_dict.clear();
    waves.clear();
    food_types.clear();
    mouse_types.clear();
    DeleteImages();
    deletelist.clear();
}

void LevelManager::ReadLevel(std::string level_name)//对指定的关卡名，进行读取关卡
{
    clearlist();
    cout << "1" << endl;
    char tmppath[100] = "../FoodVsMice/resources/levels/";
//    cout << tmppath << endl;
    strcat(tmppath, level_name.c_str());
    ifstream fp;
    fp.open(tmppath,ios::in);
    if(!fp.is_open()){
        cout << "opening failed." << endl;
        return;
    }
    char tempnum;
    for (;;)// read background
    {
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
    int now_food;
    QPixmap *fire;
    QPixmap *small_fire;
    QPixmap *steam_drawer;
    QPixmap *Small;
    QPixmap *flour;
    QPixmap *fish;
    QPixmap *hotpot;
    QPixmap *hamburg;
    QPixmap *Cherry;
    QPixmap *Egg_pitcher;
    QPixmap *Big;
    QPixmap *barb;
    vector<QPixmap *> smallfire;
    vector<QPixmap *> steamdrawer;
    vector<QPixmap *> Smallbread;
    vector<QPixmap *> Flour;
    vector<QPixmap *> Fish;
    vector<QPixmap *> hot_pot;
    vector<QPixmap *> Hamburg;
    vector<QPixmap *> cherry;
    vector<QPixmap *> Eggs_pitcher;
    vector<QPixmap *> Bigbread;
    vector<QPixmap *> Barb;
    for (;;)//read plant
    {
        fp >> now_food;
        cout << "plant:" << now_food << endl;
        FoodType i = (FoodType)now_food;

        switch (i)
        {
        case FoodType::SMALL_FIRE:
            fire = new QPixmap[10];
            small_fire = new QPixmap[29];
            loadImages(fire, "../FoodVsMice/resources/picture/food/small_fire/fire/", 10, 1);
            loadImages(small_fire, "../FoodVsMice/resources/picture/food/small_fire/small_fire/", 29, 1);
            for (auto j = 0; j < 10 ; j++){
                smallfire.push_back(&fire[j]);
                deletelist.push_back(&fire[j]);
            }
            for (auto j = 0; j < 29 ; j++){
                smallfire.push_back(&small_fire[j]);
                deletelist.push_back(&small_fire[j]);
            }
            food_types.push_back(FoodType::SMALL_FIRE);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::SMALL_FIRE,smallfire));
            break;
        case FoodType::STEAM_DRAWER:
            steam_drawer = new QPixmap[19];//最后一张是子弹
            loadImages(steam_drawer, "../FoodVsMice/resources/picture/food/steam_drawer/", 19, 1);
            for (auto j = 0; j < 19 ; j++){
                steamdrawer.push_back(&steam_drawer[j]);
                deletelist.push_back(&steam_drawer[j]);
            }
            food_types.push_back(FoodType::STEAM_DRAWER);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::STEAM_DRAWER,steamdrawer));
            break;
        case FoodType::SMALL_BREAD:
            Small=new QPixmap[36];
            loadImages(Small, "../FoodVsMice/resources/picture/food/Smallbread/", 36, 1);
            for (auto j = 0; j < 36 ; j++){
                Smallbread.push_back(&Small[j]);
                deletelist.push_back(&Small[j]);
            }
            food_types.push_back(FoodType::SMALL_BREAD);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::SMALL_BREAD,Smallbread));
            break;
        case FoodType::FLOUR:
            flour = new QPixmap[27];
            loadImages(flour, "../FoodVsMice/resources/picture/food/flour/", 27, 1);
            for (auto j = 0; j < 27 ; j++){
                Flour.push_back(&flour[j]);//0~9正常状态，10~26攻击状态
                deletelist.push_back(&flour[j]);
            }
            food_types.push_back(FoodType::FLOUR);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::FLOUR,Flour));
            break;
        case FoodType::FISH:
            fish = new QPixmap[22];
            loadImages(fish, "../FoodVsMice/resources/picture/food/fish/", 22, 1);
            for (auto j = 0; j < 22 ; j++){
                Fish.push_back(&fish[j]);//最后是子弹
                deletelist.push_back(&fish[j]);
            }
            food_types.push_back(FoodType::FISH);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::FISH,Fish));
            break;
        case FoodType::HOTPOT:
            hotpot = new QPixmap[55];
            loadImages(hotpot, "../FoodVsMice/resources/picture/food/Hots_pot/", 55, 1);
            for (auto j = 0; j < 55 ; j++){
                hot_pot.push_back(&hotpot[j]);
                deletelist.push_back(&hotpot[j]);
            }
            food_types.push_back(FoodType::HOTPOT);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::HOTPOT,hot_pot));
            break;
        case FoodType::HAMBURG:
            hamburg = new QPixmap[50];
            loadImages(hamburg, "../FoodVsMice/resources/picture/food/Hamburg/", 50, 1);
            for (auto j = 0; j < 50 ; j++){
                Hamburg.push_back(&hamburg[j]);
                deletelist.push_back(&hamburg[j]);
            }
            food_types.push_back(FoodType::HAMBURG);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::HAMBURG,Hamburg));
            break;
        case FoodType::CHERRY:
            Cherry = new QPixmap[14];
            loadImages(Cherry, "../FoodVsMice/resources/picture/food/Cherrys_tart/", 14, 1);
            for (auto j = 0; j < 14 ; j++){
                cherry.push_back(&Cherry[j]);
                deletelist.push_back(&Cherry[j]);
            }
            food_types.push_back(FoodType::CHERRY);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::CHERRY,cherry));
            break;
        case FoodType::EGG:
            Egg_pitcher = new QPixmap[37];
            loadImages(Egg_pitcher, "../FoodVsMice/resources/picture/food/Eggs_pitcher/", 37, 1);
            for (auto j = 0; j < 37 ; j++){
                Eggs_pitcher.push_back(&Egg_pitcher[j]);
                deletelist.push_back(&Egg_pitcher[j]);
            }
            food_types.push_back(FoodType::EGG);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::EGG,Eggs_pitcher));
            break;
        case FoodType::BIG_BREAD:
            Big = new QPixmap[36];
            loadImages(Big, "../FoodVsMice/resources/picture/food/Bigbread/", 36, 1);
            for (auto j = 0; j < 36 ; j++){
                Bigbread.push_back(&Big[j]);
                deletelist.push_back(&Big[j]);
            }
            food_types.push_back(FoodType::BIG_BREAD);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::BIG_BREAD,Bigbread));
            break;
        case FoodType::BARB:
            barb = new QPixmap[19];
            loadImages(barb, "../FoodVsMice/resources/picture/food/barb/", 19, 1);
            for (auto j = 0; j < 19 ; j++){
                Barb.push_back(&barb[j]);
                deletelist.push_back(&barb[j]);
            }
            food_types.push_back(FoodType::BARB);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::BARB,Barb));
            break;
        default : break;
        }
        tempnum = fp.get();
        if (tempnum == '\n') break;
    }
    QPixmap *normal;
    QPixmap *football;
    QPixmap *helmet;

    vector<QPixmap *> normal_mouse;
    vector<QPixmap *> football_mouse;
    vector<QPixmap *> helmet_mouse;
    for (;;)//read mouse
    {
        tempnum = fp.get();
        cout << "mouse:" << tempnum << endl;
        MouseType i = (MouseType)(tempnum - '0');

        switch (i)
        {
        case MouseType::NORMAL_MOUSE:
            normal = new QPixmap[37];
            loadImages(normal, "../FoodVsMice/resources/picture/mouse/normal_mouse/normal_walk1/walk1_", 37, 1);
            for (auto j = 0; j < 8 ; j++){
                normal_mouse.push_back(&normal[j]);
                deletelist.push_back(&normal[j]);
            }
            mouse_types.push_back(MouseType::NORMAL_MOUSE);
            mouse_img_dict.insert(pair<MouseType, std::vector<QPixmap *>>(MouseType::NORMAL_MOUSE,normal_mouse));
            break;
        case MouseType::FOOT_MOUSE:
            football = new QPixmap[76];
            loadImages(football, "../FoodVsMice/resources/picture/mouse/foot_mouse/", 76, 1);
            for (auto j = 0; j < 76 ; j++){
                football_mouse.push_back(&football[j]);
                deletelist.push_back(&football[j]);
            }
            mouse_types.push_back(MouseType::FOOT_MOUSE);
            mouse_img_dict.insert(pair<MouseType, std::vector<QPixmap *>>(MouseType::FOOT_MOUSE,football_mouse));
            break;
        case MouseType::HELMET_MOUSE:
            helmet= new QPixmap[77];
            loadImages(helmet, "../FoodVsMice/resources/picture/mouse/helmet_mouse/", 77, 1);
            for (auto j = 0; j < 77 ; j++){
                helmet_mouse.push_back(&helmet[j]);
                deletelist.push_back(&helmet[j]);
            }
            mouse_types.push_back(MouseType::HELMET_MOUSE);
            mouse_img_dict.insert(pair<MouseType, std::vector<QPixmap *>>(MouseType::HELMET_MOUSE,helmet_mouse));
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
            mouse_list_ptr->push_back(this_type);
            cout <<"mousetype:"<< tempnum - '0' << endl;
            tempnum = fp.get();//空格
            float this_wave;
            fp >> this_wave;
            cout <<"wavetime:"<< this_wave << endl;
            mouse_come_time_ptr->push_back(this_wave);
            int this_line;
            fp >> this_line;
            cout << "line:" << this_line<<endl;
            mouse_line_ptr->push_back(this_line);
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
const std::vector<FoodType>& LevelManager::GetFoodTypes()
{
    return food_types;
}
const std::vector<MouseType>& LevelManager::GetMouseTypes()
{
    return mouse_types;
}
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
std::shared_ptr<std::list<MouseType>> LevelManager::Getmouse_list()
{   
    return mouse_list_ptr;
}
std::shared_ptr<std::list<float>> LevelManager::Getmouse_cometime()
{
    return mouse_come_time_ptr;
}
std::shared_ptr<std::list<int>> LevelManager::Getmouse_line()
{
    return mouse_line_ptr;
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
