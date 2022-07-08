#pragma once
#include <functional>
#include <memory>
#include <list>
#include "flame.h"
#include "../../../model/level/level_manager.h"
class FlameManager
{
private:
    const int FLAME_UNIT = 50;

    LevelManager *level_manager;
    std::list<Flame *> flame_list;
    std::vector<QPixmap *> frames;
    std::shared_ptr<int> flame_count_ptr;

public:
    FlameManager(int initial_flame);

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

    // 不是属性绑定用的
    inline int GetFlameCount() { return *flame_count_ptr; }

public:

// properties
    inline std::shared_ptr<int> get_FlameCount() { return flame_count_ptr; }
    void attach_LevelManager(LevelManager *p_level_manager) { level_manager = p_level_manager; }

// commands
    // 在随机位置落下火苗
    std::function<void()> get_GenerateFlameCommand();

    // 检测(x, y)处是否有火苗，如果有，则捡起来
    std::function<void(int x, int y)> get_PickupFlameCommand();


    std::function<void()> get_UpdateFlameCommand();
};
