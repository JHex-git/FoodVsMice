#include "guimanager.h"

GUIManager::GUIManager(QWidget *parent)
    : QWidget(parent)
{
    resize(900,680);
    loading();
    init();

    timer_draw = new QTimer(this);
    connect(timer_draw,SIGNAL(timeout()),this,SLOT(repaint()));
    timer_draw->start(time_draw);
    //connect(timer_mouse,SIGNAL(timeout()),this,SLOT(mousePressEvent(QMouseEvent *event)));
}

void GUIManager:: init()
{
    level_choosing=0;
    num=-1;
    selected=0;
    time_draw=50;
    ii=0;
}

int GUIManager::Place_positioning_x(int x, int deta_x)
{
    int temp_x;
    temp_x = x * 80;
    temp_x = temp_x + 120;
    temp_x = temp_x - deta_x;
    return temp_x;
}

int GUIManager::Place_positioning_y(int y, int deta_y)
{
    int temp_y;
    temp_y = y * 75;
    temp_y = temp_y + 130;
    temp_y = temp_y - deta_y;
    return temp_y;
}

pair<int, int> GUIManager::positioning(int x, int y)
{
    pair<int, int> a;
    a.first = -1;
    a.second = -1;
    if(x>=120&&x<=840&&y>=130&&y<=655)
    {
        int temp_x, temp_y;
        temp_x = x - 120;
        temp_x = temp_x / 80;
        temp_y = y - 130;
        temp_y = temp_y / 75;
        a.first = temp_x;
        a.second = temp_y;
    }
    return a;
}

int GUIManager::locationing(int x)
{
    int temp = -1;
    if(x>90&&x<=845)
    {
        temp = x;
        temp = temp - 90;
        temp = temp / 93;
    }

    return temp;
}

void GUIManager::loadImages(QPixmap imgs[], char path[], int n, int begin)
{
    for (int i = 0; i < n; i++)
    {
        char tmpPath[200], frameNo[4];
        strcpy_s(tmpPath, 200, path);
        strcat(strcat(tmpPath, itoa(i + begin, frameNo, 10)), ".png");
        imgs[i].load(tmpPath);
    }
}

void GUIManager::loading()
{
    BackGround.load("D:\\Qt\\project\\GUI_Manager\\resources\\picture\\Screen\\0.png");
    loadImages(game, "../GUI_Manager/resources/picture/Screen/",5,1);
    loadImages(level, "../GUI_Manager/resources/picture/Screen/leve_select/", 11, 0);
    loadImages(Cherry_tart, "../GUI_Manager/resources/picture/food/Cherrys_tart/Cherry_tart/", 9, 1);
}

void GUIManager::draw_game_background()
{
    int i;
    QPainter painter(this);
    painter.drawPixmap(0,120,900,560,BackGround);
    for(int i=0;i<7;i++)
    {
        painter.drawPixmap(70, 140 + 75 * i,50,40,game[3]);
    }
    painter.drawPixmap(0,0,100,120,game[0]);
    painter.drawPixmap(90,0,100,120,game[1]);
    painter.drawPixmap(740,0,100,120,game[2]);
    for (i = 1; i <= 6; i++)
    {
        painter.drawPixmap(90+93 * i,0,100,120,game[1]);
    }
    painter.drawPixmap(115+93 * i,40,game[4]);
}

void GUIManager:: draw_level_choosing()
{
    QPainter painter(this);
    painter.drawPixmap(0,0,900,680,level[0]);
    painter.drawPixmap(300,150,270,60,level[4]);
    painter.drawPixmap(300,300,270,60,level[4]);
    painter.drawPixmap(300,450,270,60,level[4]);

    painter.drawPixmap(330,165,30,30,level[8]);
    painter.drawPixmap(420,165,30,30,level[1]);
    painter.drawPixmap(510,165,30,30,level[5]);

    painter.drawPixmap(330,315,30,30,level[9]);
    painter.drawPixmap(420,315,30,30,level[2]);
    painter.drawPixmap(510,315,30,30,level[6]);

    painter.drawPixmap(330,465,30,30,level[10]);
    painter.drawPixmap(420,465,30,30,level[3]);
    painter.drawPixmap(510,465,30,30,level[7]);
}

void GUIManager::draw_game()
{
    QPainter a(this);
    for (list<DrawItem *>::iterator it = draw_list->begin(); it != draw_list->end(); it++)
    {
        a.drawPixmap(it->x, int->y, it->img);
    }

}

void GUIManager::paintEvent(QPaintEvent *event)
{
    timer_draw->start(time_draw);
    if(level_choosing==0)
        draw_level_choosing();
    else
    {
        draw_game_background();
        draw_game();
    }
}

//void GUIManager::mousePressEvent(QMouseEvent *event)
//{
//    m_PointStart = event->pos();
//    if(event->button()==Qt::LeftButton)
//    {
//        if(level_choosing==0)
//        {
//            if()
//        }
//    }
//}

GUIManager::~GUIManager()
{
    delete timer_draw;
}
