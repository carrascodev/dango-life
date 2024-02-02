#include "actor.h"
#include "bn_camera_ptr.h"
#include "bn_fixed_point.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_char_base.h"
#include "bn_log.h"
#include "actor_animation_component.h"

namespace dl
{
    Actor::Actor(bn::camera_ptr &camera, bn::sprite_ptr &sprite) : _sprite(sprite), _camera(camera)
    {
        // default animation datas
        AnimationData *idleAnimation = new AnimationData();
        idleAnimation->type = AnimationType::IDLE;
        idleAnimation->speed = 8;
        idleAnimation->frames[EntityDirection::BACK] = bn::array<int, 4>{4, 4, 4, 4};
        idleAnimation->frames[EntityDirection::FRONT] = bn::array<int, 4>{0, 0, 0, 0};
        idleAnimation->frames[EntityDirection::RIGHT] = bn::array<int, 4>{8, 8, 8, 8};

        AnimationData *walkAnimation = new AnimationData();
        walkAnimation->type = AnimationType::WALK;
        walkAnimation->speed = 8;
        walkAnimation->frames[EntityDirection::BACK] = bn::array<int, 4>{5, 6, 7, 5};
        walkAnimation->frames[EntityDirection::FRONT] = bn::array<int, 4>{1, 2, 3, 1};
        walkAnimation->frames[EntityDirection::RIGHT] = bn::array<int, 4>{9, 10, 11, 9};

        AnimationData *attackAnimation = new AnimationData();
        attackAnimation->type = AnimationType::ATTACK;
        attackAnimation->speed = 8;
        attackAnimation->frames[EntityDirection::FRONT] = bn::array<int, 4>{12, 13, 14, 12};
        attackAnimation->frames[EntityDirection::BACK] = bn::array<int, 4>{15, 16, 17, 15};
        attackAnimation->frames[EntityDirection::RIGHT] = bn::array<int, 4>{18, 19, 20, 18};

        _animationComponent = new ActorAnimationComponent(this, bn::array<AnimationData *, 7>{idleAnimation, walkAnimation, attackAnimation, nullptr, nullptr, nullptr, nullptr});
    }

    Actor::~Actor()
    {
    }

    void Actor::move(bn::fixed_point delta)
    {
        auto x = delta.x().to_double();
        auto y = delta.y().to_double();

        if (_animationComponent->get_currentAnimation() == AnimationType::ATTACK)
        {
            return;
        }
        
        if (x == 0 && y == 0)
        {
            _animationComponent->play(AnimationType::IDLE, EntityDirection::NONE);
            return;
        }

        if (y == 0 && x != 0)
        {
            _animationComponent->play(AnimationType::WALK, x > 0 ? EntityDirection::RIGHT : EntityDirection::LEFT);
        }
        else
        {
            _animationComponent->play(AnimationType::WALK, y > 0 ? EntityDirection::FRONT : EntityDirection::BACK);
        }

        _position += delta;
        _sprite.set_position(_position);
    }

    void Actor::interact()
    {

        _animationComponent->play(AnimationType::ATTACK, EntityDirection::NONE, true);
    }

    void Actor::set_position(bn::fixed_point position)
    {
        _position = position;
        _sprite.set_position(_position);
    }

    bn::sprite_ptr Actor::get_sprite()
    {
        return _sprite;
    }

    void Actor::update()
    {
        if(_animationComponent->is_playing())
        {
            _animationComponent->update();
        }
        else {
            _animationComponent->play(AnimationType::IDLE, EntityDirection::NONE);
        }
    }
} // dl
