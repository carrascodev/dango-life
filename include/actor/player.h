
#pragma once

#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "actor.h"
#include "player_field_area_interaction_component.h"
#include "observer.h"
#include "bn_array.h"

namespace dl {
    class ActorHandComponent;
    class Player : public Actor, public ISubject<Player&> {
        public:
            Player(bn::camera_ptr& camera, bn::sprite_ptr& sprite);
            ~Player() override;
            void update() override;
            void move(bn::fixed_point position) override;
            void interact() override;
            ActorHandComponent* get_hand_component() { return _actorHandComponent; }
            int get_money() { return _money; }
            void attach(IObserver<Player&> *observer) override;
            void detach(IObserver<Player&> *observer) override;
            void add_money(int amount);

    private:
            bn::fixed_point _position;
            PlayerFieldAreaInteractionComponent* _fieldAreaInteractionComponent;
            ActorHandComponent* _actorHandComponent;
            int _money;
            bn::array<IObserver<Player&>*,3> _observers;
    };
}