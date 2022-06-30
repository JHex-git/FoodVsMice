#pragma once
#include<graphics.h>

using namespace std;

extern IMAGE background;                                           //背景
extern IMAGE lawnmower;                                            //推车
extern IMAGE peashooter[8];                                        //豌豆射手
extern IMAGE PB;					                                //豌豆射手的炮弹
extern IMAGE normalZombieWalkPictures[47];                         //普通僵尸走路
extern IMAGE normalZombieEatPictures[10];                          //普通僵尸eat
extern IMAGE coneheadZombieWalkPictures[47];                       //路障僵尸走路
extern IMAGE coneheadZombieEatPictures[10];                        //路障僵尸eat
extern IMAGE bucketheadZombieWalkPictures[47];                     //铁桶僵尸走路
extern IMAGE bucketheadZombieEatPictures[10];                      //铁桶僵尸eat
extern IMAGE sunflowers[8];                                        //太阳花

extern int Picture_num;                                            //图片号
extern int plant_x, plant_y;
extern int zombie_x, zonbie_y;
class GUIManager
{
    public:
        void loading();                                     //IMAGE 指针指向picture
        void positioning(int x, int y);                     //放置植物时定位
        void Draw_background();                             //画背景
        void Draw_plant(IMAGE plant_img[]);                           //画植物
        void Draw_zombie(IMAGE zombie_img[]);                          //画僵尸
        static void drawAlpha(IMAGE *picture, int picture_x, int picture_y); //插入透明图

   private:
       void loadImages(IMAGE imgs[], char path[], int n, int begin); //插入多张图
};