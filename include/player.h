#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "entity.h"
#include "player_field_area_interaction_component.h"

namespace dl {
    class Player : public Entity {
        public:
            Player(bn::camera_ptr& camera, bn::sprite_ptr& sprite);
            ~Player() override;
            void update() override;
            void move(bn::fixed_point position) override;
            void interact() override;
        private:
            bn::fixed_point _position;
            PlayerFieldAreaInteractionComponent* _fieldAreaInteractionComponent;
    };
}