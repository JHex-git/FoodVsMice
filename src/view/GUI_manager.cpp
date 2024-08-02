#include "GUI_manager.h"
#include "../common/time_manager.h"
#include "../common/debug.h"

GUIManager::GUIManager(QWidget *parent)
    : QWidget(parent)
{
    resize(900,680);
    loading();
    init();

    music = new QMediaPlayer();
    audioOutput = new QAudioOutput;
    background_music_manager();

    timer_draw = new QTimer(this);
    connect(timer_draw,SIGNAL(timeout()),this,SLOT(repaint()));
    timer_draw->start(time_draw);

    timer_logic = new QTimer(this);
    timer_logic->setInterval(time_update_logic);
    connect(timer_logic, &QTimer::timeout, this, &GUIManager::update_logic);
}

void GUIManager:: init()
{
    level_choosing=0;
    num=-1;
    selected=0;
    time_draw=50;
    time_update_logic = 50;
    num_select=1;
    ii=0;
    music_choosing=0;
    menu_1=0;
}

void GUIManager::loading()
{
    BackGround.load(":/new/resources/picture/Screen/0.png");
    already.load(":/new/resources/picture/Screen/80.png");
    char temp[]=":/new/resources/picture/Screen/";
    loadImages(game,temp ,5,1);
    char temp1[]=":/new/resources/picture/Screen/leve_select/";
    loadImages(level,temp1 , 11, 0);
    char temp2[]=":/new/resources/picture/Screen/menu/";
    loadImages(menu,temp2,6,1);
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

int GUIManager::Place_positioning_x(int x)
{
    int temp_x;
    temp_x = x * 80;
    temp_x = temp_x + 120;
    return temp_x;
}

int GUIManager::Place_positioning_y(int y)
{
    int temp_y;
    temp_y = y * 75;
    temp_y = temp_y + 130;
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

pair<int, int> GUIManager::select_positioning(int num, int deta_x, int deta_y)
{
    pair<int,int> b;
    b.first=90 + 93 * num-deta_x;
    b.second=30-deta_y;
    return b;
}

void GUIManager::draw_game_background()
{
    int i;
    QPainter painter(this);
    painter.drawPixmap(0,120,900,560,BackGround);
//    for(int i=0;i<7;i++)
//    {
//        painter.drawPixmap(70, 140 + 75 * i,50,40,game[3]);
//    }
    painter.drawPixmap(0,0,100,120,game[0]);
    painter.drawPixmap(90,0,100,120,game[1]);
    painter.drawPixmap(740,0,100,120,game[2]);
    for (i = 1; i <= 6; i++)
    {
        painter.drawPixmap(90+93 * i,0,100,120,game[1]);
    }
    painter.drawPixmap(115+93 * i,40,game[4]);

    QFont font("黑体", 15, 75);
    font.setCapitalization(QFont::SmallCaps);
    painter.setFont(font);
    QRectF rect(10, 90, 75, 20);
    char num[10];
    itoa(*flame_sum, num,10);
    painter.setPen(QColor(Qt::red));
    painter.drawText(rect,Qt::AlignHCenter | Qt::AlignVCenter, num);

    painter.setPen(QColor(Qt::black));
    painter.setBrush(QColor(57, 151, 205));
    painter.drawRect(838,0,61,120);
    QFont font1("黑体", 15, 75);
    font1.setCapitalization(QFont::SmallCaps);
    painter.setFont(font1);
    QRectF rect1(838,0,61,120);
    painter.drawText(rect1,Qt::AlignHCenter | Qt::AlignVCenter, "菜单");
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
    QPainter painter(this);
    for (list<SpriteItem *>::iterator it = draw_list->begin(); it != draw_list->end(); it++)
    {
        painter.drawPixmap((*it)->x, (*it)->y, *(*it)->img);
    }

    for (list<SpriteItem *>::iterator it = mouse_list->begin(); it != mouse_list->end(); it++)
    {
        painter.drawPixmap((*it)->x, (*it)->y, *(*it)->img);
    }

    for (list<SpriteItem *>::iterator it = projectile_list->begin(); it != projectile_list->end(); it++)
    {
        painter.drawPixmap((*it)->x, (*it)->y, *(*it)->img);
    }

    for (list<SpriteItem *>::iterator it = flame_list->begin(); it != flame_list->end(); it++)
    {
        painter.drawPixmap((*it)->x, (*it)->y, *(*it)->img);
    }


}

void GUIManager::draw_select()
{
    QPainter painter(this);
    for(auto it=select_vector->begin();it!=select_vector->end();it++)
    {
        painter.drawPixmap((*it)->x, (*it)->y, *(*it)->img);
    }
    for(int i=0;i<already_vector->size();i++)
    {
        painter.drawPixmap(select_positioning(i, -10, 8).first,select_positioning(i, -10, 8).second,80,*(*already_vector)[i] * 87,already);
        QFont font("黑体", 13, 75);
        font.setCapitalization(QFont::SmallCaps);
        painter.setFont(font);
        QRectF rect(93+93*i, 5, 90, 15);
        char num[10];
        itoa((*flame_cost_vector)[i], num,10);
        painter.setPen(QColor(Qt::yellow));
        painter.drawText(rect,Qt::AlignHCenter | Qt::AlignVCenter, num);
    }
}

void GUIManager::draw_menu()
{
    QPainter painter(this);
    painter.drawPixmap(300,300,menu[0]);
    painter.drawPixmap(409,380,menu[1]);
    painter.drawPixmap(422,430,menu[2]);
}

void GUIManager::gameover()
{
    QPainter painter(this);
    if(*status_ptr == Status::LOSE)
    {
        painter.drawPixmap(350,300,menu[4]);
        timer_draw->stop();
        timer_logic->stop();
    }
    else if(*status_ptr == Status::WIN)
    {
         painter.drawPixmap(350,300,menu[5]);
         timer_draw->stop();
         timer_logic->stop();
    }
}

void GUIManager::paintEvent(QPaintEvent *event)
{
    if(level_choosing==0)
        draw_level_choosing();
    else
    {
        draw_game_background();
        draw_select();
        draw_game();
        gameover();
    }

    if(menu_1==1)
    {
        draw_menu();
        timer_draw->stop();
        timer_logic->stop();
    }
}

void GUIManager::update_logic()
{
    UpdateFood();
    UpdateCard();
    UpdateMouse();
    UpdateProjectile();
    UpdateFlame();
    TimeManager::UpdateTime();
}

void GUIManager::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if (PickupFlame(event->x(), event->y()))
        {
            music_choosing=3;
            music_manager();
        }
        if(level_choosing==0)
        {
            if(event->x()>=300&&event->x()<=570)
            {
                if(event->y()>=150&&event->y()<=210)
                {
                    level_choosing=1;
                    UpdateLevel(level_choosing);
                    InitCard();
                    timer_logic->start();
                    TimeManager::Init();
                }
                else if(event->y()>=300&&event->y()<=360)
                {
                    level_choosing=2;
                    UpdateLevel(level_choosing);
                    InitCard();
                    timer_logic->start();
                    TimeManager::Init();
                }
                else if(event->y()>=450&&event->y()<=510)
                {
                    level_choosing=3;
                    UpdateLevel(level_choosing);
                    InitCard();
                    timer_logic->start();
                    TimeManager::Init();
                }
            }  
            background_music_manager();      

            return;
        }
        if(level_choosing!=0)
        {
            if(event->y()<130)
            {
                num = locationing(event->x());
                selected = 1;
                if(event->x()>845)
                {
                    menu_1=1;
                }
            }
            if (event->y() >= 130 && num!=-1 && selected==1&&num!=7)
            {
                int row = positioning(event->x(), event->y()).second;
                int col = positioning(event->x(), event->y()).first;
                if (PlaceFood(row,col,num))
                {
                    num = -1;
                    selected = 0;
                    music_choosing=1;
                    music_manager();
                }
            }
            if (event->y() >= 130 && event->y()<655 && num==7 && selected==1 && event->x()>120 && event->x()<840)
            {
                int row = positioning(event->x(), event->y()).second;
                int col = positioning(event->x(), event->y()).first;
                RemoveFood(row,col);
                music_choosing=2;
                music_manager();
                num=-1;
                selected = 0;
            }
            if(event->y() >= 130&&menu_1==1)
            {
                if(event->x()>409&&event->x()<490&&event->y()>380&&event->y()<415)
                {
                    menu_1=0;
                    timer_draw->start();
                    timer_logic->start();
                }
                if(event->x()>422&&event->x()<476&&event->y()>430&&event->y()<456)
                    close();
            }
        }

    }
}

void GUIManager::background_music_manager()
{
    QUrl music_url = QUrl("qrc:/new/resources/music/beijing.mp3");
    music->setAudioOutput(audioOutput);
    music->setSource(music_url);
    music->setLoops(QMediaPlayer::Loops::Infinite);
    audioOutput->setVolume(50);
    music->play();


    if(level_choosing!=0)
    {
        music->stop();
        music->setAudioOutput(audioOutput);
        QUrl music_url = QUrl("qrc:/new/resources/music/zhandou.mp3");
        music->setSource(music_url);
        music->setLoops(QMediaPlayer::Loops::Infinite);
        music->play();
    }
}

void GUIManager::music_manager()
{
    QMediaPlayer player(this);//设置音乐
    if(music_choosing==1)
    {
        music_choosing=0;
        player.setAudioOutput(audioOutput);
        QUrl music_url = QUrl("qrc:/new/resources/music/zhongzhi.mp3");
        player.setSource(music_url);
        audioOutput->setVolume(100);//音量
        player.play();
    }

    if(music_choosing==2)
    {
        music_choosing=0;
        player.setAudioOutput(audioOutput);
        QUrl music_url = QUrl("qrc:/new/resources/music/chanzi.mp3");
        player.setSource(music_url);
        audioOutput->setVolume(200);//音量
        player.play();
    }

    if(music_choosing==3)
    {
        music_choosing=0;
        player.setAudioOutput(audioOutput);
        QUrl music_url = QUrl("qrc:/new/resources/music/huomiao.mp3");
        player.setSource(music_url);
        audioOutput->setVolume(200);//音量
        player.play();
    }

}

GUIManager::~GUIManager()
{
    delete timer_draw;
}

std::function<std::pair<int, int>(int row_index, int column_index)> GUIManager::get_Matrix2ViewportCommand()
{
    return [this](int row_index, int column_index)->std::pair<int, int>
    {
        std::pair<int, int> p;
        p.first = Place_positioning_x(column_index);
        p.second = Place_positioning_y(row_index);
        return p;
    };
}

std::function<std::pair<int, int>(int x, int y)> GUIManager::get_Viewport2MatrixCommand()
{
    return [this](int x, int y)->std::pair<int, int>
    {
        std::pair<int, int> p;
        p.first = positioning(x, y).second;
        p.second = positioning(x, y).first;
        return p;
    };
}

std::function<std::pair<int, int>(int select_index)> GUIManager::get_Index2ViewportCommand()
{
    return [this](int select_index)->std::pair<int, int>
    {
        return select_positioning(select_index,0,0);
    };
}

