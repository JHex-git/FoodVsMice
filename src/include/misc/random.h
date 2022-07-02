/**
 * 提供生成随机数的接口，包括指定范围整数、浮点数
 */
#pragma once
#include <random>
#include <ctime>

class Random
{
public:
    static void Init();
    static float RandFloat(float min, float max);
    static int RandInt(int min, int max);
private:
    static std::default_random_engine e;
};