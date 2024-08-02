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
    // 加载小火苗图片资源
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

void LevelManager::ReadLevel(int level_num)//对指定的关卡名，进行读取关卡
{
    clearlist();
    char tmppath[100] = ":/new/resources/levels/";
    QString filepath=":/new/resources/levels/";
//    cout << tmppath << endl;
    QString level_name;
    switch (level_num)
    {
    case 1:
        level_name = "first.txt";
        break;
    case 2:
        level_name = "second.txt";
        break;
    case 3:
        level_name = "third.txt";
        break;
    default:
        break;
    }
    filepath = filepath + level_name;
    QResource level_resource(filepath);
    // ifstream fp;
    if (level_resource.isValid())
    {
        qDebug("resource unvalid");

    }
    QByteArray level_data_byteArray = QByteArray::fromRawData(reinterpret_cast<const char*>(level_resource.data()),level_resource.size());
    QTextStream in(&level_data_byteArray);

    char tempnum;
    for (;;)// read background
    {
        in >> tempnum;
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
            (*background_game[0]).load(":/new/resources/picture/Screen/background_game1.png");
            (*background_game[1]).load(":/new/resources/picture/Screen/lawnmower.png");
            (*background_game[2]).load(":/new/resources/picture/Screen/1.png");
            (*background_game[3]).load(":/new/resources/picture/Screen/2.png");
            (*background_game[4]).load(":/new/resources/picture/Screen/3.png");
            map_img.push_back(background_game[0]);
            map_img.push_back(background_game[1]);
            map_img.push_back(background_game[2]);
            map_img.push_back(background_game[3]);
            map_img.push_back(background_game[4]);
            break;

        default:
            break;
        }
        in >> tempnum;
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
    QPixmap *egg;
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
    vector<QPixmap *> super_egg;
    small_fire = new QPixmap[29];
    fire = new QPixmap[10];
    loadImages(small_fire, ":/new/resources/picture/food/small_fire/small_fire/", 29, 1);
    loadImages(fire, ":/new/resources/picture/food/small_fire/fire/", 10, 1);
    for (auto j = 0; j < 29 ; j++){
        smallfire.push_back(&small_fire[j]);
        deletelist.push_back(&small_fire[j]);
    }
    for (auto j = 0; j < 10 ; j++){
        smallfire.push_back(&fire[j]);
        deletelist.push_back(&fire[j]);
    }
    food_types.push_back(FoodType::SMALL_FIRE);
    food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::SMALL_FIRE,smallfire));
    for (;;)//read plant
    {
        in >> now_food;
        cout << "plant:" << now_food << endl;
        FoodType i = (FoodType)now_food;

        switch (i)
        {
        case FoodType::STEAM_DRAWER:
            steam_drawer = new QPixmap[19];//最后一张是子弹
            loadImages(steam_drawer, ":/new/resources/picture/food/steam_drawer/", 19, 1);
            for (auto j = 0; j < 19 ; j++){
                steamdrawer.push_back(&steam_drawer[j]);
                deletelist.push_back(&steam_drawer[j]);
            }
            food_types.push_back(FoodType::STEAM_DRAWER);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::STEAM_DRAWER,steamdrawer));
            break;
        case FoodType::SMALL_BREAD:
            Small=new QPixmap[36];
            loadImages(Small, ":/new/resources/picture/food/Smallbread/", 36, 1);
            for (auto j = 0; j < 36 ; j++){
                Smallbread.push_back(&Small[j]);
                deletelist.push_back(&Small[j]);
            }
            food_types.push_back(FoodType::SMALL_BREAD);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::SMALL_BREAD,Smallbread));
            break;
        case FoodType::FLOUR:
            flour = new QPixmap[27];
            loadImages(flour, ":/new/resources/picture/food/flour/", 27, 1);
            for (auto j = 0; j < 27 ; j++){
                Flour.push_back(&flour[j]);//0~9正常状态，10~26攻击状态
                deletelist.push_back(&flour[j]);
            }
            food_types.push_back(FoodType::FLOUR);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::FLOUR,Flour));
            break;
        case FoodType::FISH:
            fish = new QPixmap[22];
            loadImages(fish, ":/new/resources/picture/food/fish/", 22, 1);
            for (auto j = 0; j < 22 ; j++){
                Fish.push_back(&fish[j]);//最后是子弹
                deletelist.push_back(&fish[j]);
            }
            food_types.push_back(FoodType::FISH);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::FISH,Fish));
            break;
        case FoodType::HOTPOT:
            hotpot = new QPixmap[55];
            loadImages(hotpot, ":/new/resources/picture/food/Hots_pot/", 55, 1);
            for (auto j = 0; j < 55 ; j++){
                hot_pot.push_back(&hotpot[j]);
                deletelist.push_back(&hotpot[j]);
            }
            food_types.push_back(FoodType::HOTPOT);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::HOTPOT,hot_pot));
            break;
        case FoodType::HAMBURG:
            hamburg = new QPixmap[50];
            loadImages(hamburg, ":/new/resources/picture/food/Hamburg/", 50, 1);
            for (auto j = 0; j < 50 ; j++){
                Hamburg.push_back(&hamburg[j]);
                deletelist.push_back(&hamburg[j]);
            }
            food_types.push_back(FoodType::HAMBURG);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::HAMBURG,Hamburg));
            break;
        case FoodType::CHERRY:
            Cherry = new QPixmap[14];
            loadImages(Cherry, ":/new/resources/picture/food/Cherrys_tart/", 14, 1);
            for (auto j = 0; j < 14 ; j++){
                cherry.push_back(&Cherry[j]);
                deletelist.push_back(&Cherry[j]);
            }
            food_types.push_back(FoodType::CHERRY);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::CHERRY,cherry));
            break;
        case FoodType::EGG:
            Egg_pitcher = new QPixmap[37];
            loadImages(Egg_pitcher, ":/new/resources/picture/food/Eggs_pitcher/", 37, 1);
            for (auto j = 0; j < 37 ; j++){
                Eggs_pitcher.push_back(&Egg_pitcher[j]);
                deletelist.push_back(&Egg_pitcher[j]);
            }
            food_types.push_back(FoodType::EGG);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::EGG,Eggs_pitcher));
            break;
        case FoodType::BIG_BREAD:
            Big = new QPixmap[36];
            loadImages(Big, ":/new/resources/picture/food/Bigbread/", 36, 1);
            for (auto j = 0; j < 36 ; j++){
                Bigbread.push_back(&Big[j]);
                deletelist.push_back(&Big[j]);
            }
            food_types.push_back(FoodType::BIG_BREAD);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::BIG_BREAD,Bigbread));
            break;
        case FoodType::BARB:
            barb = new QPixmap[19];
            loadImages(barb, ":/new/resources/picture/food/barb/", 19, 1);
            for (auto j = 0; j < 19 ; j++){
                Barb.push_back(&barb[j]);
                deletelist.push_back(&barb[j]);
            }
            food_types.push_back(FoodType::BARB);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::BARB,Barb));
            break;
        case FoodType::SUPER_EGG:
            egg = new QPixmap[37];
            loadImages(egg, ":/new/resources/picture/food/super_egg/", 37, 1);
            for (auto j = 0; j < 37 ; j++){
                super_egg.push_back(&egg[j]);
                deletelist.push_back(&egg[j]);
            }
            food_types.push_back(FoodType::SUPER_EGG);
            food_img_dict.insert(pair<FoodType, std::vector<QPixmap *>>(FoodType::SUPER_EGG,super_egg));
            break;
        default : break;
        }
        in >> tempnum;
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
        in >> tempnum;
        cout << "mouse:" << tempnum << endl;
        MouseType i = (MouseType)(tempnum - '0');

        switch (i)
        {
        case MouseType::NORMAL_MOUSE:
            normal = new QPixmap[12];
            loadImages(normal, ":/new/resources/picture/mouse/normal_mouse/", 12, 1);
            for (auto j = 0; j < 12 ; j++){
                normal_mouse.push_back(&normal[j]);
                deletelist.push_back(&normal[j]);
            }
            mouse_types.push_back(MouseType::NORMAL_MOUSE);
            mouse_img_dict.insert(pair<MouseType, std::vector<QPixmap *>>(MouseType::NORMAL_MOUSE,normal_mouse));
            break;
        case MouseType::FOOT_MOUSE:
            football = new QPixmap[12];
            loadImages(football, ":/new/resources/picture/mouse/foot_mouse/", 12, 1);
            for (auto j = 0; j < 12 ; j++){
                football_mouse.push_back(&football[j]);
                deletelist.push_back(&football[j]);
            }
            mouse_types.push_back(MouseType::FOOT_MOUSE);
            mouse_img_dict.insert(pair<MouseType, std::vector<QPixmap *>>(MouseType::FOOT_MOUSE,football_mouse));
            break;
        case MouseType::HELMET_MOUSE:
            helmet= new QPixmap[12];
            loadImages(helmet, ":new/resources/picture/mouse/helmet_mouse/", 12, 1);
            for (auto j = 0; j < 12 ; j++){
                helmet_mouse.push_back(&helmet[j]);
                deletelist.push_back(&helmet[j]);
            }
            mouse_types.push_back(MouseType::HELMET_MOUSE);
            mouse_img_dict.insert(pair<MouseType, std::vector<QPixmap *>>(MouseType::HELMET_MOUSE,helmet_mouse));
            break;
        default:
            break;
        }
        in >> tempnum;
        if (tempnum == '\n') break;
    }
    for (;;)// read waves
    {
        float now_wave;
        in >> now_wave;
        cout<<"wavetime:"<<now_wave<<endl;
        waves.push_back(now_wave);
        in >> tempnum;
        if (tempnum == '\n') break;
    }
    for (int j = 0; j < waves.size() ; j++){//read every wave
        for (;;)
        {
            in >> tempnum;
            MouseType this_type = (MouseType)(tempnum - '0');
            mouse_list_ptr->push_back(this_type);
            cout <<"mousetype:"<< tempnum - '0' << endl;
            in >> tempnum;//空格
            float this_wave;
            in >> this_wave;
            cout <<"wavetime:"<< this_wave << endl;
            mouse_come_time_ptr->push_back(this_wave);
            int this_line;
            in >> this_line;
            cout << "line:" << this_line<<endl;
            mouse_line_ptr->push_back(this_line);
            in >> tempnum;//空格或者换行
            if (tempnum == '\n') break;
        }
    }


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
std::function<void(int level)>  LevelManager::get_UpdateLevelCommand()
{
    return [this](int level) -> void
    {
        ReadLevel(level);
    };
}
