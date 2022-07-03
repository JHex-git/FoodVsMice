#pragma once
#include <list>
#include "flame.h"

class FlameManager
{
private:
    const int FLAME_UNIT = 50;
    int flame_count;
    std::list<Flame *> flame_list;
    std::vector<IMAGE *> frames;

public:
    FlameManager(int initial_flame, std::vector<IMAGE *> frames);

    // 释放list中的所有flame
    ~FlameManager();

    // 在随机位置落下火苗
    void GenerateFlame();

    // 在指定位置落下火苗（一般仅限于火炉使用）
    void GenerateFlame(int x, int y);

    // 检测(x, y)处是否有火苗，如果有，则捡起来
    void PickupFlame(int x, int y);

    void UpdateFlame();


    /* --- 玩家拥有的火苗 --- */

    // 火苗不够则返回false
    bool DecreaseFlame(int num);

    inline void IncreaseFlame(int num);

    inline int GetFlame() { return flame_count; }
};
