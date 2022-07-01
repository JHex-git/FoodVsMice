#pragma once
#include<graphics.h>
#include<iostream>

using namespace std;

#define window_length 900   // x;
#define window_width 710    // y;
#define select_width 150    //选择食物的窗口宽度
#define game_width 560      //放置食物的窗口宽度
#define Egg_deta_x 15       
#define Egg_deta_y 35
#define Cherry_deta_x -25
#define Cherry_deta_y 10
#define mouse_deta_y 40
#define hotpot_deta_x -3
#define hotpot_deta_y 28


extern IMAGE normal_eat1[4];
extern IMAGE normal_eat2[4];
extern IMAGE normal_walk1[8];
extern IMAGE normal_walk2[8];
extern IMAGE normal_die[13];
extern IMAGE Egg_boom[6];
extern IMAGE Egg_pitcher[26];
extern IMAGE Egg_b[5];
extern IMAGE background_game[5];
extern IMAGE Cherry_b;
extern IMAGE Cherry_boom[4];
extern IMAGE Cherry_tart[9];
extern IMAGE hotpot[13];
extern IMAGE hotpot_b[42];

extern int Picture_num;                                       
extern int plant_x, plant_y;
extern int zombie_x, zonbie_y;
class GUIManager
{
    public:
        void init();
        void loading();                                                             //IMAGE 指针指向picture
        pair<int, int> positioning(int x, int y);                                   //返回坐标，不在范围内返回（-1.-1）
        int  Place_positioning_x(int x, int deta_x);                                //放置食物时定位
        int  Place_positioning_y(int y, int deta_y);                                //放置食物时定位
        int  select_positioning_x(int x, int deta_x);                               //选择食物时定位
        int  select_positioning_y(int y, int deta_y);                               //选择食物时定位
        void Draw_background(IMAGE img[]);                                          //画背景                         
        static void drawAlpha(IMAGE *picture, int picture_x, int picture_y);        //插入透明图
        ~GUIManager();
   private:
       void loadImages(IMAGE imgs[], char path[], int n, int begin);                //插入多张图
};