#include "bn_unordered_map.h"
#include "bn_array.h"
#include "entity_direction.h"

namespace dl {
    enum AnimationType {
        IDLE,
        WALK,
        ATTACK,
        PLANT,
        CARRY,
        HURT,
        DEAD
    };

    struct AnimationData {
        AnimationType type;
        bn::unordered_map<EntityDirection,bn::array<int, 4>,4> frames;
        int speed;
    };
}