#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_optional.h"
#include "bn_vector.h"

namespace dl {
    class EntityAnimationComponent;

    class Entity {
        public:
            Entity(bn::camera_ptr& camera, bn::sprite_ptr& sprite);
            virtual ~Entity();
            virtual void update();

            virtual void move(bn::fixed_point delta);
            void attack();
            
            void set_position(bn::fixed_point position);
            bn::fixed_point get_position();

            bn::sprite_ptr get_sprite();

        protected:
            void animate_movement(int wait_updates, bn::array<int, 4> graphics_indexes);

            bn::fixed_point _position;
            bn::sprite_ptr _sprite;
            bn::camera_ptr _camera;
            bool _isMoving;
            EntityAnimationComponent* _animationComponent;
    };
}
