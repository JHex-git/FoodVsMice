#include "flame.h"
#include "../../../common/random.h"
#include "../../../common/time_manager.h"
#include "flame.h"

const float DURATION = 5;
const float MIN_DROP_DURATION = 1;
const float MAX_DROP_DURATION = 5;
const int DROP_VELOCITY = 1;
const int DELTA_X = 34;
const int DELTA_Y = 34;
const float FRAME_RATE = 1;

Flame::Flame(int x, int y) : Sprite(x, y, FRAME_RATE)
{
    is_exist = true;
    is_dropping = true;
    current_exist_time = 0;
    drop_duration = Random::RandFloat(MIN_DROP_DURATION, MAX_DROP_DURATION);
}

Flame::Flame(int x, int y, std::vector<QPixmap *> frames) : Sprite(x, y, DELTA_X, DELTA_Y, FRAME_RATE, frames)
{
    center_x = x;
    center_y = y;
    is_exist = true;
    is_dropping = true;
    current_exist_time = 0;
    drop_duration = Random::RandFloat(MIN_DROP_DURATION, MAX_DROP_DURATION);
}

void Flame::UpdateBehave()
{
    current_exist_time += TimeManager::DELTA_TIME;
    
    if (current_exist_time > DURATION) // 火苗一段时间后会消失
    {
        is_exist = false;
        return;
    }
    else if (is_dropping) // 坠落
    {
        center_y += DROP_VELOCITY * TimeManager::DELTA_TIME;
        sprite_item.y += DROP_VELOCITY * TimeManager::DELTA_TIME;

        if (current_exist_time >= drop_duration)
        {
            is_dropping = false;
        }
    }
}

Flame::~Flame()
{
}
