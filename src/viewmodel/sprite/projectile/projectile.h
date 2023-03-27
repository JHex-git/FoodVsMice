#pragma once
#include "../sprite.h"
#include "../../../common/enums.h"

class Projectile : public Sprite
{
    friend class ProjectileManager;
public:
    bool is_active;

    Projectile(int x, int y, int delta_x, int delta_y, float frame_rate, std::vector<QPixmap *> frames, int boom_index, float velocity, int damage);

    void Update() override;

    virtual void UpdateBehave() = 0;

    inline ProjectileType GetType() { return type; }

    virtual ~Projectile() = default;
protected:
    float velocity;
    int damage;
//    bool is_active;
    bool is_boom;
    int boom_index;
    int bound;
    int center_x;
    int center_y;
    ProjectileType type;
};
