
#pragma once

#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "actor.h"
#include "player_field_area_interaction_component.h"
#include "actor_hand_component.h"

namespace dl {
    class Player : public Actor {
        public:
            Player(bn::camera_ptr& camera, bn::sprite_ptr& sprite);
            ~Player() override;
            void update() override;
            void move(bn::fixed_point position) override;
            void interact() override;
            ActorHandComponent* get_hand_component() { return _actorHandComponent; }

    private:
            bn::fixed_point _position;
            PlayerFieldAreaInteractionComponent* _fieldAreaInteractionComponent;
            ActorHandComponent* _actorHandComponent;
    };
}