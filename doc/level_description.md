# level

```c++
eg:first.txt
0
/*0为第一张地图*/
5 7 8
/*第二行5,7,8分别对应食物序号，在enums.h中可以查看。
    SMALL_FIRE=0,
    STEAM_DRAWER=1,
    SMALL_BREAD=2,
    FLOUR=3,
    FISH=4,
    HOTPOT=5,
    HAMBURG=6,
    CHERRY=7,
    EGG=8,
    BIG_BREAD=9,
    BARB=10
对应HOTPOT，CHERRY，EGG*/
0 2
/*第三行0，2对应老鼠序号
	NORMAL_MOUSE=0,
    FOOT_MOUSE=1,
    HELMET_MOUSE=2
此处对应NORMAL_MOUSE和HELMET_MOUSE*/
30 120 210
/*第四行是三波密集攻击的大概时间，后续根据游戏体验可修改*/
/*有几波密集攻击，以下就有几行*/
0 29 1 0 30 2 0 30 4 2 30 5 0 31 1 2 31 2 0 31.5 5
/*此处逐个列举每个老鼠的类型、到来时间和行数
例如，
0 29 1 代表NORMAL_MOUSE在29s的第1行到来
0 30 2 代表NORMAL_MOUSE在30s的第2行到来
2 31 2 代表HELMET_MOUSE在31s的第2行到来
*/
0 119 3 0 119.5 1 2 119.5 2 2 120 4 0 120 5 0 121 5
2 209 6 0 209 7 0 209.5 1 2 210 1 2 210.5 4 0 211 2
```

注意数字由空格隔开，一行末端没有多余空格

为了便于调试，此处的关卡设计较为简单，老鼠数量少且到来时间稀疏，等基本实现功能后可加大难度