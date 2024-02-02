#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_optional.h"
#include "bn_vector.h"
#include "entity_direction.h"
#include "entity.h"

namespace dl {
    class ActorAnimationComponent;

    class Actor : public IEntity {
        public:
            Actor(bn::camera_ptr& camera, bn::sprite_ptr& sprite);
            virtual ~Actor();
            virtual void update();

            virtual void move(bn::fixed_point delta);
            virtual void interact();
            
            void set_position(bn::fixed_point position) override;
            inline bn::fixed_point get_position() override { return _sprite.position() + _camera.position(); };

            bn::sprite_ptr get_sprite();

        inline void set_direction(EntityDirection direction) { _currentDirection = direction; };
        inline EntityDirection get_direction() { return _currentDirection; };

    protected:
            bn::fixed_point _position;
            bn::sprite_ptr _sprite;
            bn::camera_ptr _camera;
            bool _isMoving;
            ActorAnimationComponent* _animationComponent;
            EntityDirection _currentDirection;
    };
}
