#pragma once

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <iostream>
#include <map>
#include <functional>
#include "../common/draw_item.h"
#include "../common/debug.h"
using namespace std;

#define window_length 900   // x;
#define window_width 680    // y;
#define select_width 120    //选择食物的窗口宽度
#define game_width 560      //放置食物的窗口宽度
#define select_first_width 90
#define select_after_width 93

#define Egg_deta_x 15       
#define Egg_deta_y 35
#define Select_Egg_deta_x -10
#define Select_Egg_deta_y  23

#define Cherry_deta_x -20
#define Cherry_deta_y 5
#define Select_Cherry_deta_x -30
#define Select_Cherry_deta_y -8

#define mouse_deta_y 40

#define hotpot_deta_x -3
#define hotpot_deta_y 28
#define Select_hotpot_deta_x -15
#define Select_hotpot_deta_y 13



class GUIManager : public QWidget
{
    Q_OBJECT

public:
    GUIManager(QWidget *parent = 0);
//.............................................................................................................................准备阶段函数
    void init();                                                   //初始化
    void loadImages(QPixmap imgs[], char path[], int n, int begin);//载入多张图
    void loading();                                                //加载图片

//............................................................................................................................定位函数
    int locationing(int x);                                        //返回选择食物的位置,从0开始算;
    pair<int, int> positioning(int x, int y);                      //返回要放置的食物坐标，不在范围内返回（-1.-1）
    int  Place_positioning_x(int x);                               //放置食物时定位，输入x（列号），返回精确的像素坐标x;
    int  Place_positioning_y(int y);                               //放置食物时定位，输入y（行号），放回精确的像素坐标y;
    pair<int, int> select_positioning_x(int num, int deta_x, int deta_y);    //选择食物时定位，输入选择框的编号和植物的deta_x，获得精确的像素坐标
//...........................................................................................................................画图函数
    void draw_game_background();                                   //画游戏背景
    void draw_level_choosing();                                    //画选择页面
    void draw_select();                                            //画选择植物
    void draw_game();                                              //画食物、老鼠

    void update_logic();

    ~GUIManager();

protected slots:
       void paintEvent(QPaintEvent *event);                           //绘图事件
       void mousePressEvent(QMouseEvent *event);                      //鼠标移动事件
private:
    std::shared_ptr<std::list<DrawItem *>> draw_list;
    std::shared_ptr<std::list<DrawItem *>> mouse_list;

    std::shared_ptr<std::vector<DrawItem *>> select_vector;

    std::shared_ptr<std::vector<float *>> already_vector;
    std::shared_ptr<std::vector<int>> flame_cost_vector;
    std::shared_ptr<int> flame_sum;

//...................................................................时钟
    QTimer *timer_draw;         //画图时钟
    int time_draw;              //信号时长
    QPixmap BackGround;         //大背景
    QPixmap level[11];          //选择页面
    QPixmap game[5];            //游戏页面
    QPainter already;           //冷却用
    QTimer *timer_logic;        //更新游戏逻辑时钟
    int time_update_logic;      //信号时长


//.................................................................控制信号
    int selected;               //是否已选择（0表示没选择，1表示选择了）
    int num;                    //选择了什么食物（0到6是食物，7是铲子）
    int level_choosing;         //关卡选择（0是选择界面，1是关卡1，2是关卡2，3是关卡3)
    map<pair<int,int>,int> sele;

//......................................。。。。。。................自测变量，可删除
    int ii;                     //测试用
    QPixmap Cherry_tart[9];     //测试用
    QPixmap select_food[7];     //测试用
    int num_select;

    std::function<bool(int row_index, int column_index, int select_index)> PlaceFood;
    std::function<void()> UpdateFood;
    std::function<void()> UpdateCard;

public:
// properties
    void attach_DrawFoodList(const std::shared_ptr<std::list<DrawItem *>> food_list)
    {
        draw_list = food_list;
    }
    void attach_DrawMouseList(const std::shared_ptr<std::list<DrawItem *>> mouse_list_)
    {
        mouse_list= mouse_list_;
    }
    void attach_SelectVector(const std::shared_ptr<std::vector<DrawItem *>> select_vector_)
    {
        select_vector=select_vector_;
    }
    viod attach_AlreadyVector(const std::shared_ptr<std::vector<float *>> already_vector_)
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
// command
    std::function<std::pair<int, int>(int row_index, int column_index)> get_Matrix2ViewportCommand();
    std::function<std::pair<int, int>(int x, int y)> get_Viewport2MatrixCommand();
    std::function<std::pair<int, int>(int select_index)> get_Index2ViewportCommand();

// command
    void attach_PlaceFoodCommand(std::function<bool(int row_index, int column_index, int select_index)>&& func) { PlaceFood = std::move(func); }
    void attach_UpdateFoodCommand(std::function<void()>&& func) { UpdateFood = std::move(func); }
    void attach_UpdateCardCommand(std::function<void()>&& func) { UpdateCard = std::move(func); }
};

