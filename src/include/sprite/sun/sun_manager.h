#pragma once
#include <list>
#include "sprite/sun/sun.h"

class SunManager
{
private:
    const int SUN_UNIT = 50;
    int sun_count;
    std::list<Sun *> sun_list;
    std::vector<IMAGE *> frames;

public:
    SunManager(int initial_sun, std::vector<IMAGE *> frames);

    // 在随机位置落下阳光
    void GenerateSun();

    // 在指定位置落下阳光（一般仅限于太阳花使用）
    void GenerateSun(int x, int y);

    // 检测(x, y)处是否有阳光，如果有，则捡起来
    void PickupSun(int x, int y);

    void UpdateSun();


    /* --- 玩家拥有的阳光 --- */

    // 阳光不够则返回false
    bool DecreaseSun(int num);

    inline void IncreaseSun(int num);

    inline int GetSun() { return sun_count; }
};