#pragma once
#include <iostream>
#include <string>
#include <io.h>
#include <vector>
#include <stdio.h>
#include <list>
#include <graphics.h>
#include <unordered_map>
#include <fstream>
#include "misc/enums.h"
using namespace std;
class LevelManager
{
public:
    // void WriteLevel(char name[]);
    /**
     *  1. 释放之前占用的图片资源(可以另写一个private函数)
     *  2. 根据关卡名读取关卡文件，载入关卡信息，根据要使用的食物和老鼠载入图片资源，
     *  放入 vector<IMAGE *> food_img_dict, mouse_img_dict.
     *  3. 根据关卡载入地图资源 IMAGE *.
     */
    void ReadLevel(std::string level_name);

    // 返回字典引用供外界得到图片资源
    const std::unordered_map<FoodType, std::vector<IMAGE *>>& GetFoodImages();
    const std::unordered_map<MouseType, std::vector<IMAGE *>>& GetMouseImages();

    // 返回波的信息
    const std::list<float>& GetWaves();
    // 与上面类似，两个函数分别返回mouse_list、mouse_come_time以及mouse_line
    const std::list<MouseType> &Getmouse_list();
    const std::list<float> &Getmouse_cometime();
    const std::list<int> &Getmouse_line();
    
    //释放图片资源
    void DeleteImages();

    ~LevelManager(){};

private:
    std::vector<FoodType> food_types; // 关卡供使用的食物（FoodType是枚举变量，或用int代替）
    std::vector<MouseType> mouse_types; // 关卡可能出现的老鼠（MouseType是枚举变量，或用int代替）

    std::list<float> waves; // 每波到来的时间，按时间顺序排好

    std::list<MouseType> mouse_list; // 按时间顺序排好的老鼠
    std::list<float> mouse_come_time; // 老鼠来的时间，与mouse_list一同使用，即相同"下标"为同一只老鼠
    std::list<int> mouse_line;//老鼠来的行数
    // std::list<std::pair<MouseType, float>> mouse_list; 或采用这种方式

    // 加载的食物图片资源存储在该字典中，一种食物对应一系列的图片
    std::unordered_map<FoodType, std::vector<IMAGE *>> food_img_dict;
    // 加载的老鼠图片资源存储在该字典中，一种老鼠对应一系列的图片
    std::unordered_map<MouseType, std::vector<IMAGE *>> mouse_img_dict;
    // 地图图片
    vector<IMAGE *> map_img;
    void loadImages(IMAGE imgs[], char path[], int n, int begin);
    std::list<IMAGE *> deletelist;
};

// delete deletelist[1];