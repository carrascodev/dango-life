#include "bn_unordered_map.h"
#include "bn_array.h"

namespace dl {
    enum AnimationDirection {
        NONE,
        FRONT,
        BACK,
        RIGHT,
        LEFT
    };

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
        bn::unordered_map<AnimationDirection,bn::array<int, 4>,4> frames;
        int speed;
    };
}