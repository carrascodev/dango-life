#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_optional.h"
#include "bn_vector.h"
#include "entity_direction.h"

namespace dl {
    class EntityAnimationComponent;

    class Entity {
        public:
            Entity(bn::camera_ptr& camera, bn::sprite_ptr& sprite);
            virtual ~Entity();
            virtual void update();

            virtual void move(bn::fixed_point delta);
            virtual void interact();
            
            void set_position(bn::fixed_point position);
            inline bn::fixed_point get_position() { return _sprite.position() + _camera.position(); };

            bn::sprite_ptr get_sprite();

        inline void set_direction(EntityDirection direction) { _currentDirection = direction; };
        inline EntityDirection get_direction() { return _currentDirection; };

    protected:
            bn::fixed_point _position;
            bn::sprite_ptr _sprite;
            bn::camera_ptr _camera;
            bool _isMoving;
            EntityAnimationComponent* _animationComponent;
            EntityDirection _currentDirection;
    };
}
