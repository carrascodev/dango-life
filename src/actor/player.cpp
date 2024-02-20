#include "player.h"
#include "field_area.h"
#include "player_field_area_interaction_component.h"

using namespace dl;

Player::Player(bn::camera_ptr &camera, bn::sprite_ptr &sprite) : Actor(camera, sprite)
{
    _position = bn::fixed_point(0, 0);
    _fieldAreaInteractionComponent = new PlayerFieldAreaInteractionComponent(camera,this);
    _actorHandComponent = new ActorHandComponent();
}

dl::Player::~Player()
{
    delete _fieldAreaInteractionComponent;
    delete _actorHandComponent;
}

void Player::update()
{
    Actor::update();
    _fieldAreaInteractionComponent->update();
}

void Player::move(bn::fixed_point position) {
    Actor::move(position);
}

void Player::interact() {
    Actor::interact();
    switch (_actorHandComponent->get_tool())
    {
        case WorkTool::HOE:
            _fieldAreaInteractionComponent->do_sow();
            break;
        case WorkTool::WATERING_CAN:
            _fieldAreaInteractionComponent->do_water();
            break;
        case WorkTool::SEEDS:
            _fieldAreaInteractionComponent->do_plant();
            break;
    }
}
