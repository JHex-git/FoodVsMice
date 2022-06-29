/**
 * 提供生成随机数的接口，包括指定范围整数、浮点数
 */
#pragma once

class Random
{
public:
    static float RandFloat(float min, float max);
    static int RandInt(int min, int max);
};