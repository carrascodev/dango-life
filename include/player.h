#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "entity.h"

namespace dl {
    class Player : public Entity {
        public:
            Player(bn::camera_ptr& camera, bn::sprite_ptr& sprite);
            ~Player() override;
            void update() override;
        private:
            bn::fixed_point _position;
    };
}