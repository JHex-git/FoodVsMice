#pragma once
#include<graphics.h>
#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <io.h>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <mmsystem.h>

using namespace std;

IMAGE background;                                           //背景
IMAGE lawnmower;                                            //推车
IMAGE peashooter[8];                                        //豌豆射手
IMAGE PB;					                                //豌豆射手的炮弹
IMAGE normalZombieWalkPictures[47];                         //普通僵尸走路
IMAGE normalZombieEatPictures[10];                          //普通僵尸eat
IMAGE coneheadZombieWalkPictures[47];                       //路障僵尸走路
IMAGE coneheadZombieEatPictures[10];                        //路障僵尸eat
IMAGE bucketheadZombieWalkPictures[47];                     //铁桶僵尸走路
IMAGE bucketheadZombieEatPictures[10];                      //铁桶僵尸eat
IMAGE sunflowers[8];                                        //太阳花

int Picture_num;                                            //图片号
int plant_x, plant_y;
int zombie_x, zonbie_y;
class GUIManager
{
    public:
        void loading();                                     //IMAGE 指针指向picture
        void positioning(int x, int y);                     //放置植物时定位
        void Draw_background();                             //画背景
        void Draw_plant(IMAGE plant_img[]);                           //画植物
        void Draw_zombie(IMAGE zombie_img[]);                          //画僵尸

   private:
       void drawAlpha(IMAGE *picture, int picture_x, int picture_y); //插入透明图
       void loadImages(IMAGE imgs[], char path[], int n, int begin); //插入多张图
};