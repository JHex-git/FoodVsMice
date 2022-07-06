#pragma once
#include <map>
class MapTransform
{
public:
    static std::pair<int, int> Maxtrix2Viewport(int row_index, int column_index);
    static std::pair<int, int> Viewport2Matrix(int x, int y);
    static std::pair<int, int> Index2Viewport(int select_index);
};
