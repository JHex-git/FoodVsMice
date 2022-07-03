#include "level_manager.h""
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
    for (;;)
    { // read background
        count++;
        cout << "count:" << count << endl;
        tempnum = fp.get();
        cout << "background:" << tempnum << endl;
        MapType i = (MapType)(tempnum - '0');
        IMAGE *background_game[5];
        switch (i)
        {
        case MapType::BASE:
            background_game[0] = new IMAGE;
            background_game[1] = new IMAGE;
            background_game[2] = new IMAGE;
            background_game[3] = new IMAGE;
            background_game[4] = new IMAGE;
            deletelist.push_back(background_game[0]);
            deletelist.push_back(background_game[1]);
            deletelist.push_back(background_game[2]);
            deletelist.push_back(background_game[3]);
            deletelist.push_back(background_game[4]);
            loadimage(background_game[0], "../resources/picture/Screen/background_game1.png", 900, 560);
            loadimage(background_game[1], "../resources/picture/Screen/lawnmower.png", 50, 40);
            loadimage(background_game[2], "../resources/picture/Screen/1.png", 100, 120);
            loadimage(background_game[3], "../resources/picture/Screen/2.png", 100, 120);
            loadimage(background_game[4], "../resources/picture/Screen/3.png", 100, 120);
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
    for (;;)
    {//read plant
        count++;
        cout << "count:" << count << endl;
        tempnum = fp.get();
        cout << "plant:" << tempnum << endl;
        FoodType i = (FoodType)(tempnum - '0');
        IMAGE *hotpot;
        IMAGE *hotpot_b;
        vector<IMAGE *> hot_pot;
        switch (i)
        {
        case FoodType::HOTPOT:
            hotpot = new IMAGE[13];
            hotpot_b = new IMAGE[42];
            loadImages(hotpot, "../../resources/picture/food/Hots_pot/Hotpot/", 13, 1);
            loadImages(hotpot_b, "../resources/picture/food/Hots_pot/Hotpot_b/", 42, 14);
            for (auto j = 0; j < 13 ; j++){
                hot_pot.push_back(&hotpot[j]);
                deletelist.push_back(&hotpot[j]);
            }
            for (auto j = 0; j < 42 ; j++){
                hot_pot.push_back(&hotpot_b[j]);
                deletelist.push_back(&hotpot_b[j]);
            }
            food_types.push_back(FoodType::HOTPOT);
            food_img_dict.insert(pair<FoodType, std::vector<IMAGE *>>(FoodType::HOTPOT,hot_pot));
            break;

        default:
            break;
        }
        tempnum = fp.get();
        if (tempnum == '\n') break;
    }
    for (;;)
    {//read mouse
        tempnum = fp.get();
        cout << "mouse:" << tempnum << endl;
        MouseType i = (MouseType)(tempnum - '0');
        IMAGE *normal_eat1;
        vector<IMAGE *> normal_mouse;
        switch (i)
        {
        case MouseType::MOUSE:
            normal_eat1 = new IMAGE[4];
            loadImages(normal_eat1, "../resources/picture/mouse/normal_mouse/normal_eat1/eat1_", 4, 1);
            for (auto j = 0; j < 4 ; j++){
                normal_mouse.push_back(&normal_eat1[j]);
                deletelist.push_back(&normal_eat1[j]);
            }
            mouse_types.push_back(MouseType::MOUSE);
            mouse_img_dict.insert(pair<MouseType, std::vector<IMAGE *>>(MouseType::MOUSE,normal_mouse));
            break;

        default:
            break;
        }
        tempnum = fp.get();
        if (tempnum == '\n') break;
    }
    for (;;)
    { // read waves
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

const std::unordered_map<FoodType, std::vector<IMAGE *>>& LevelManager::GetFoodImages()
{
    return food_img_dict;
}
const std::unordered_map<MouseType, std::vector<IMAGE *>>& LevelManager::GetMouseImages()
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
void LevelManager::loadImages(IMAGE imgs[], char path[], int n, int begin)
{
    for (int i = 0; i < n; i++)
    {
        char tmpPath[200], frameNo[4];
        strcpy_s(tmpPath, 200, path);
        strcat(strcat(tmpPath, itoa(i + begin, frameNo, 10)), ".png");
        loadimage(&imgs[i], tmpPath);
    }
}

void LevelManager::DeleteImages()
{
    for (auto i = deletelist.begin(); i != deletelist.end();i++){
        delete (*i);
    }
}
