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
    QPixmap *Small1;
    QPixmap *Small2;
    QPixmap *Small3;
    QPixmap *flour;
    QPixmap *fish;
    QPixmap *hotpot;
    QPixmap *hotpot_b;
    QPixmap *Hamburg1;
    QPixmap *Hamburg2;
    QPixmap *Cherry_tart;
    QPixmap *Cherry_b;
    QPixmap *Cherry_boom;
    QPixmap *Egg_pitcher;
    QPixmap *Eggs;
    QPixmap *Egg_boom;
    QPixmap *Big1;
    QPixmap *Big2;
    QPixmap *Big3;
    QPixmap *barb;
    vector<QPixmap *> smallfire;
    vector<QPixmap *> steamdrawer;
    vector<QPixmap *> Smallbread;
    vector<QPixmap *> Flour;
    vector<QPixmap *> Fish;
    vector<QPixmap *> hot_pot;
    vector<QPixmap *> Hamburg;
    vector<QPixmap *> cherry;
    vector<QPixmap *> Eggs_pitche;;
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
            steam_drawer = new QPixmap[19];//第一张里是子弹
            loadImages(steam_drawer, "../FoodVsMice/resources/picture/food/steam_drawer/", 19, 0);
            for (auto j = 0; j < 19 ; j++){
                steamdrawer.push_back(&steam_drawer[j]);
                deletelist.push_back(&steam_drawer[j]);
            }
            food_types.push_back(FoodType::STEAM_DRAWER);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::STEAM_DRAWER,steamdrawer));
            break;
        case FoodType::SMALL_BREAD:
            Small1=new QPixmap[12];
            Small2=new QPixmap[12];
            Small3=new QPixmap[12];
            loadImages(Small1, "../FoodVsMice/resources/picture/food/Smallbread/Small1/", 12, 1);
            loadImages(Small2, "../FoodVsMice/resources/picture/food/Smallbread/Small2/", 12, 13);
            loadImages(Small3, "../FoodVsMice/resources/picture/food/Smallbread/Small3/", 12, 25);
            for (auto j = 0; j < 12 ; j++){
                Smallbread.push_back(&Small1[j]);
                deletelist.push_back(&Small1[j]);
            }
            for (auto j = 0; j < 12 ; j++){
                Smallbread.push_back(&Small2[j]);
                deletelist.push_back(&Small2[j]);
            }
            for (auto j = 0; j < 12 ; j++){
                Smallbread.push_back(&Small3[j]);
                deletelist.push_back(&Small3[j]);
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
            loadImages(fish, "../FoodVsMice/resources/picture/food/fish/", 22, 0);
            for (auto j = 0; j < 22 ; j++){
                Fish.push_back(&fish[j]);//0是子弹
                deletelist.push_back(&fish[j]);
            }
            food_types.push_back(FoodType::FISH);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::FISH,Fish));
            break;
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
        case FoodType::HAMBURG:
            Hamburg1 = new QPixmap[13];
            Hamburg2 = new QPixmap[37];
            loadImages(Hamburg1, "../FoodVsMice/resources/picture/food/Hamburg/Hamburg1/", 13, 1);
            loadImages(Hamburg2, "../FoodVsMice/resources/picture/food/Hamburg/Hamburg2/", 37, 14);
            for (auto j = 0; j < 13 ; j++){
                Hamburg.push_back(&Hamburg1[j]);
                deletelist.push_back(&Hamburg1[j]);
            }
            for (auto j = 0; j < 37 ; j++){
                Hamburg.push_back(&Hamburg2[j]);
                deletelist.push_back(&Hamburg2[j]);
            }
            food_types.push_back(FoodType::HAMBURG);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::HAMBURG,Hamburg));
            break;
        case FoodType::CHERRY:
            Cherry_tart = new QPixmap[9];
            Cherry_b = new QPixmap[1];
            Cherry_boom = new QPixmap[4];
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
        case FoodType::BIG_BREAD:
            Big1 = new QPixmap[12];
            Big2 = new QPixmap[12];
            Big3 = new QPixmap[12];
            loadImages(Big1, "../FoodVsMice/resources/picture/food/Bigbread/Big1/", 12, 1);
            loadImages(Big2, "../FoodVsMice/resources/picture/food/Bigbread/Big2/", 12, 13);
            loadImages(Big3, "../FoodVsMice/resources/picture/food/Bigbread/Big3/", 12, 25);
            for (auto j = 0; j < 12 ; j++){
                Bigbread.push_back(&Big1[j]);
                deletelist.push_back(&Big1[j]);
            }
            for (auto j = 0; j < 12 ; j++){
                Bigbread.push_back(&Big2[j]);
                deletelist.push_back(&Big2[j]);
            }
            for (auto j = 0; j < 12 ; j++){
                Bigbread.push_back(&Big3[j]);
                deletelist.push_back(&Big3[j]);
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
    QPixmap *normal_walk1;
    QPixmap *normal_walk2;
    QPixmap *normal_eat1;
    QPixmap *normal_eat2;
    QPixmap *normal_die;
    
    QPixmap *helmet_walking1;
    QPixmap *helmet_walking2;
    QPixmap *helmet_walking3;
    QPixmap *helmet_walking4;
    QPixmap *helmet_walking5;
    QPixmap *helmet_eating1;
    QPixmap *helmet_eating2;
    QPixmap *helmet_eating3;
    QPixmap *helmet_eating4;
    QPixmap *helmet_eating5;
    QPixmap *helmet_die;

    vector<QPixmap *> normal_mouse;
    vector<QPixmap *> helmet_mouse;
    for (;;)//read mouse
    {
        tempnum = fp.get();
        cout << "mouse:" << tempnum << endl;
        MouseType i = (MouseType)(tempnum - '0');
        
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
        case MouseType::HELMET_MOUSE:
            helmet_walking1 = new QPixmap[8];
            helmet_walking2 = new QPixmap[8];
            helmet_walking3 = new QPixmap[8];
            helmet_walking4 = new QPixmap[8];
            helmet_walking5 = new QPixmap[8];
            helmet_eating1 = new QPixmap[4];
            helmet_eating2 = new QPixmap[4];
            helmet_eating3 = new QPixmap[8];
            helmet_eating4 = new QPixmap[4];
            helmet_eating5 = new QPixmap[4];
            helmet_die = new QPixmap[13];

            loadImages(helmet_walking1, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_walking1/", 8, 1);
            loadImages(helmet_walking2, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_walking2/", 8, 9);
            loadImages(helmet_walking3, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_walking3/", 8, 17);
            loadImages(helmet_walking4, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_walking4/", 8, 25);
            loadImages(helmet_walking5, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_walking5/", 8, 33);
            loadImages(helmet_eating1, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_eating1/", 4, 41);
            loadImages(helmet_eating2, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_eating2/", 4, 45);
            loadImages(helmet_eating3, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_eating3/", 8, 49);
            loadImages(helmet_eating4, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_eating4/", 4, 57);
            loadImages(helmet_eating5, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_eating5/", 4, 61);
            loadImages(helmet_die, "../FoodVsMice/resources/picture/mouse/helmet_mouse/helmet_die/", 13, 65);

            for (auto j = 0; j < 8 ; j++){
                helmet_mouse.push_back(&helmet_walking1[j]);
                deletelist.push_back(&helmet_walking1[j]);
            }
            for (auto j = 0; j < 8 ; j++){
                helmet_mouse.push_back(&helmet_walking2[j]);
                deletelist.push_back(&helmet_walking2[j]);
            }
            for (auto j = 0; j < 8 ; j++){
                helmet_mouse.push_back(&helmet_walking3[j]);
                deletelist.push_back(&helmet_walking3[j]);
            }
            for (auto j = 0; j < 8 ; j++){
                helmet_mouse.push_back(&helmet_walking4[j]);
                deletelist.push_back(&helmet_walking4[j]);
            }
            for (auto j = 0; j < 8 ; j++){
                helmet_mouse.push_back(&helmet_walking5[j]);
                deletelist.push_back(&helmet_walking5[j]);
            }
            for (auto j = 0; j < 4 ; j++){
                helmet_mouse.push_back(&helmet_eating1[j]);
                deletelist.push_back(&helmet_eating1[j]);
            }
            for (auto j = 0; j < 4 ; j++){
                helmet_mouse.push_back(&helmet_eating2[j]);
                deletelist.push_back(&helmet_eating2[j]);
            }
            for (auto j = 0; j < 8 ; j++){
                helmet_mouse.push_back(&helmet_eating3[j]);
                deletelist.push_back(&helmet_eating3[j]);
            }
            for (auto j = 0; j < 4 ; j++){
                helmet_mouse.push_back(&helmet_eating4[j]);
                deletelist.push_back(&helmet_eating4[j]);
            }
            for (auto j = 0; j < 4 ; j++){
                helmet_mouse.push_back(&helmet_eating5[j]);
                deletelist.push_back(&helmet_eating5[j]);
            }
            for (auto j = 0; j < 13 ; j++){
                helmet_mouse.push_back(&helmet_die[j]);
                deletelist.push_back(&helmet_die[j]);
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