#include "player.h"

using namespace dl;

Player::Player(bn::camera_ptr &camera, bn::sprite_ptr &sprite) : Entity(camera, sprite)
{
    _position = bn::fixed_point(0, 0);
}

dl::Player::~Player()
{
}

void Player::update()
{
    Entity::update();
}
