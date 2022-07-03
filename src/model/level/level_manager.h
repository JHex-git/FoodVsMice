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
#include "../../common/enums.h"
using namespace std;
class LevelManager
{
public:
    // void WriteLevel(char name[]);
    /**
     *  1. �ͷ�֮ǰռ�õ�ͼƬ��Դ(������дһ��private����)
     *  2. ���ݹؿ�����ȡ�ؿ��ļ�������ؿ���Ϣ������Ҫʹ�õ�ʳ�����������ͼƬ��Դ��
     *  ���� vector<IMAGE *> food_img_dict, mouse_img_dict.
     *  3. ���ݹؿ������ͼ��Դ IMAGE *.
     */
    void ReadLevel(std::string level_name);

    // �����ֵ����ù����õ�ͼƬ��Դ
    const std::unordered_map<FoodType, std::vector<IMAGE *>>& GetFoodImages();
    const std::unordered_map<MouseType, std::vector<IMAGE *>>& GetMouseImages();

    // ���ز�����Ϣ
    const std::list<float>& GetWaves();
    // ���������ƣ����������ֱ𷵻�mouse_list��mouse_come_time�Լ�mouse_line
    const std::list<MouseType> &Getmouse_list();
    const std::list<float> &Getmouse_cometime();
    const std::list<int> &Getmouse_line();

    //�ͷ�ͼƬ��Դ
    void DeleteImages();

    ~LevelManager(){};

private:
    std::vector<FoodType> food_types; // �ؿ���ʹ�õ�ʳ�FoodType��ö�ٱ���������int���棩
    std::vector<MouseType> mouse_types; // �ؿ����ܳ��ֵ�����MouseType��ö�ٱ���������int���棩

    std::list<float> waves; // ÿ��������ʱ�䣬��ʱ��˳���ź�

    std::list<MouseType> mouse_list; // ��ʱ��˳���źõ�����
    std::list<float> mouse_come_time; // ��������ʱ�䣬��mouse_listһͬʹ�ã�����ͬ"�±�"Ϊͬһֻ����
    std::list<int> mouse_line;//������������
    // std::list<std::pair<MouseType, float>> mouse_list; ��������ַ�ʽ

    // ���ص�ʳ��ͼƬ��Դ�洢�ڸ��ֵ��У�һ��ʳ���Ӧһϵ�е�ͼƬ
    std::unordered_map<FoodType, std::vector<IMAGE *>> food_img_dict;
    // ���ص�����ͼƬ��Դ�洢�ڸ��ֵ��У�һ�������Ӧһϵ�е�ͼƬ
    std::unordered_map<MouseType, std::vector<IMAGE *>> mouse_img_dict;
    // ��ͼͼƬ
    vector<IMAGE *> map_img;
    void loadImages(IMAGE imgs[], char path[], int n, int begin);
    std::list<IMAGE *> deletelist;
};

// delete deletelist[1];
