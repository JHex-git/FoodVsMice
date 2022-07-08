#include "map_transform.h"


std::pair<int, int> MapTransform::Matrix2Viewport(int row_index, int column_index)
{
    int temp_x;
    temp_x = column_index * 80;
    temp_x = temp_x + 120;

    int temp_y;
    temp_y = row_index * 75;
    temp_y = temp_y + 130;

    return std::pair<int, int>(temp_x, temp_y);
}

std::pair<int, int> MapTransform::Matrix2ViewportCenter(int row_index, int column_index)
{
    std::pair<int, int> coordinate = Matrix2Viewport(row_index, column_index);
    coordinate.first += GRID_WIDTH / 2;
    coordinate.second += GRID_HEIGHT / 2;
    return coordinate;
}

std::pair<int, int> MapTransform::Viewport2Matrix(int x, int y)
{
    std::pair<int, int> a;
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

std::pair<int, int> MapTransform::Index2Viewport(int select_index)
{
    std::pair<int,int> b;
    b.first=90 + 93 * select_index;
    b.second=30;
    return b;
}
