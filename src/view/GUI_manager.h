#pragma once

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <iostream>
#include <map>
#include <functional>
#include "../common/sprite_item.h"
#include "../common/enums.h"
using namespace std;

#define window_length 900   // x;
#define window_width 680    // y;
#define select_width 120    //选择食物的窗口宽度
#define game_width 560      //放置食物的窗口宽度
#define select_first_width 90
#define select_after_width 93
#define mouse_deta_y 40

class GUIManager : public QWidget
{
    Q_OBJECT

public:
    GUIManager(QWidget *parent = 0);
//..................................................................................................................准备阶段函数
    void init();                                                   //初始化
    void loadImages(QPixmap imgs[], char path[], int n, int begin);//载入多张图
    void loading();                                                //加载图片

//....................................................................................................................定位函数
    int locationing(int x);                                        //返回选择食物的位置,从0开始算;
    pair<int, int> positioning(int x, int y);                      //返回要放置的食物坐标，不在范围内返回（-1.-1）
    int  Place_positioning_x(int x);                               //放置食物时定位，输入x（列号），返回精确的像素坐标x;
    int  Place_positioning_y(int y);                               //放置食物时定位，输入y（行号），放回精确的像素坐标y;
    pair<int, int> select_positioning(int num, int deta_x, int deta_y);    //选择食物时定位，输入选择框的编号和植物的deta_x，获得精确的像素坐标
//..................................................................................................................画图函数
    void draw_game_background();                                   //画游戏背景
    void draw_level_choosing();                                    //画选择页面
    void draw_select();                                            //画选择植物
    void draw_game();                                              //画食物、老鼠
    void draw_menu();                                               //画菜单
    void gameover();                                                //游戏结束

//...................................................................................................................音乐控制
    void background_music_manager();                                //背景音乐
    void music_manager();                                           //其他音乐

    void update_logic();
    ~GUIManager();

protected slots:
       void paintEvent(QPaintEvent *event);                           //绘图事件
       void mousePressEvent(QMouseEvent *event);                      //鼠标移动事件
private:
    std::shared_ptr<std::list<SpriteItem *>> draw_list;
    std::shared_ptr<std::list<SpriteItem *>> mouse_list;
    std::shared_ptr<std::list<SpriteItem *>> projectile_list;
    std::shared_ptr<std::list<SpriteItem *>> flame_list;

    std::shared_ptr<std::vector<SpriteItem *>> select_vector;
    std::shared_ptr<std::vector<float *>> already_vector;
    std::shared_ptr<std::vector<int>> flame_cost_vector;
    std::shared_ptr<int> flame_sum;

    std::shared_ptr<Status> status_ptr;

//...................................................................时钟
    QTimer *timer_draw;         //画图时钟
    int time_draw;              //信号时长
    QTimer *timer_logic;        //更新游戏逻辑时钟
    int time_update_logic;      //信号时长
//....................................................................图片
    QPixmap BackGround;         //大背景
    QPixmap level[11];          //选择页面
    QPixmap game[5];            //游戏页面
    QPixmap already;           //冷却用
    QPixmap menu[6];

    QMediaPlayer *music;        //游戏音乐
    QAudioOutput *audioOutput;

//.................................................................控制信号
    int selected;               //是否已选择（0表示没选择，1表示选择了）
    int num;                    //选择了什么食物（0到6是食物，7是铲子）
    int level_choosing;         //关卡选择（0是选择界面，1是关卡1，2是关卡2，3是关卡3)
    int music_choosing;
    int menu_1;                 //是否点击菜单
    int over_;                   //游戏是否结束
//......................................。。。。。。................自测变量，可删除
    int ii;                     //测试用
    QPixmap Cherry_tart[9];     //测试用
    QPixmap select_food[7];     //测试用
    int num_select;
    map<pair<int,int>,int> sele;

    std::function<bool(int row_index, int column_index, int select_index)> PlaceFood;
    std::function<void(int row_index, int column_index)>RemoveFood;
    std::function<void()> UpdateFood;
    std::function<void()> UpdateCard;
    std::function<void()> UpdateMouse;
    std::function<void()> UpdateProjectile;
    std::function<void(int level)>UpdateLevel;
    std::function<void()> InitCard;
    std::function<bool(int x, int y)> PickupFlame;
    std::function<void()> UpdateFlame;

public:
// properties
    void attach_DrawFoodList(const std::shared_ptr<std::list<SpriteItem *>> food_list)
    {
        draw_list = food_list;
    }
    void attach_DrawMouseList(const std::shared_ptr<std::list<SpriteItem *>> mouse_list_)
    {
        mouse_list= mouse_list_;
    }
    void attach_DrawProjectileList(const std::shared_ptr<std::list<SpriteItem *>> projectile_list_)
    {
        projectile_list=projectile_list_;
    }
    void attach_DrawFlameList(const std::shared_ptr<std::list<SpriteItem *>> flame_list_)
    {
        flame_list = flame_list_;
    }
    void attach_SelectVector(const std::shared_ptr<std::vector<SpriteItem *>> select_vector_)
    {
        select_vector=select_vector_;
    }
    void attach_AlreadyVector(const std::shared_ptr<std::vector<float *>> already_vector_)
    {
        already_vector=already_vector_;
    }
    void attach_SunCost(const std::shared_ptr<std::vector<int>> flame_cost_vector_)
    {
        flame_cost_vector=flame_cost_vector_;
    }
    void attach_SunSum(const std::shared_ptr<int> flame_sum_)
    {
        flame_sum=flame_sum_;
    }
    void attach_Status(const std::shared_ptr<Status> status_)
    {
        status_ptr = status_;
    }

// command
    std::function<std::pair<int, int>(int row_index, int column_index)> get_Matrix2ViewportCommand();
    std::function<std::pair<int, int>(int x, int y)> get_Viewport2MatrixCommand();
    std::function<std::pair<int, int>(int select_index)> get_Index2ViewportCommand();


// command
    void attach_PlaceFoodCommand(std::function<bool(int row_index, int column_index, int select_index)>&& func) { PlaceFood = std::move(func); }
    void attach_RemoveFoodCommand(std::function<void(int row_index, int column_index)>&& func ){RemoveFood = std::move(func);}
    void attach_UpdateFoodCommand(std::function<void()>&& func) { UpdateFood = std::move(func); }
    void attach_UpdateCardCommand(std::function<void()>&& func) { UpdateCard = std::move(func); }
    void attach_UpdateMouseCommand(std::function<void()>&& func){ UpdateMouse = std::move(func);}
    void attach_UpdataUpdateProjectile(std::function<void()>&&func){UpdateProjectile = std::move(func);}
    void attach_UpdateLevel(std::function<void(int level)>&&func){UpdateLevel = std::move(func);}
    void attach_InitCardCommand(std::function<void()>&& func) { InitCard = std::move(func); }
    void attach_PickupFlameCommand(std::function<bool(int x, int y)>&& func) { PickupFlame = std::move(func); }
    void attach_UpdateFlameCommand(std::function<void()>&& func) { UpdateFlame = std::move(func); }
};

