#include "player.h"
#include "field_area.h"
#include "player_field_area_interaction_component.h"

using namespace dl;

Player::Player(bn::camera_ptr &camera, bn::sprite_ptr &sprite) : Entity(camera, sprite)
{
    _position = bn::fixed_point(0, 0);
    _fieldAreaInteractionComponent = new PlayerFieldAreaInteractionComponent(camera,this);
}

dl::Player::~Player()
{
}

void Player::update()
{
    Entity::update();
    _fieldAreaInteractionComponent->update();
}

void Player::move(bn::fixed_point position) {
    Entity::move(position);
}

void Player::interact() {
    Entity::interact();
    _fieldAreaInteractionComponent->do_sow();
}
