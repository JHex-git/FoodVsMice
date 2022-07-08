#include "flame.h"
#include "../../../common/random.h"
#include "../../../common/time_manager.h"
#include "flame.h"

Flame::Flame(int x, int y) : Sprite(x, y, FRAME_RATE)
{
    is_exist = true;
    is_dropping = true;
    current_exist_time = 0;
    drop_duration = Random::RandFloat(MIN_DROP_DURATION, MAX_DROP_DURATION);
}

Flame::Flame(int x, int y, std::vector<QPixmap *> frames) : Sprite(x, y, DELTA_X, DELTA_Y, FRAME_RATE, frames)
{
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
        sprite_item.y += DROP_VELOCITY * TimeManager::DELTA_TIME;

        if (current_exist_time >= drop_duration)
        {
            is_dropping = false;
        }
    }
}

Flame::~Flame()
{
    // TODO: 擦除图片
}
