#include "entity_animation_component.h"
#include "entity.h"
#include "bn_sprite_items_char_base.h"

namespace dl
{
    EntityAnimationComponent::EntityAnimationComponent(Entity *entity, bn::array<AnimationData *, 7> animations) : _entity(entity), _animations(animations)
    {
        _currentDirection = AnimationDirection::FRONT;
    }

    EntityAnimationComponent::~EntityAnimationComponent()
    {
    }

    void EntityAnimationComponent::play(AnimationType type, AnimationDirection direction, bool once)
    {
        if (_animation.has_value() && _currentAnimation == type && (_currentDirection == direction))
        {
            return;
        }

        if (direction == AnimationDirection::NONE)
        {
            direction = _currentDirection;
        }

        _currentAnimation = type;
        _currentDirection = direction;
        auto animationData = _animations[static_cast<int>(type)];
        _entity->get_sprite().set_horizontal_flip(direction == AnimationDirection::LEFT);
        if (direction == AnimationDirection::LEFT)
        {
            direction = AnimationDirection::RIGHT;
        }
        auto frames = animationData->frames[direction];
        auto speed = animationData->speed;

        if (once)
        {
            _animation = bn::create_sprite_animate_action_once(
                _entity->get_sprite(), speed, bn::sprite_items::char_base.tiles_item(), frames[0], frames[1], frames[2], frames[3]);
        }
        else
        {    
            _animation = bn::create_sprite_animate_action_forever(
                _entity->get_sprite(), speed, bn::sprite_items::char_base.tiles_item(), frames[0], frames[1], frames[2], frames[3]);
        }
    }

    void EntityAnimationComponent::add_animation(AnimationData *animation)
    {
        _animations[static_cast<int>(animation->type)] = animation;
    }

    void EntityAnimationComponent::update()
    {
        if(_animation.has_value() && !_animation->done())
        {
            _animation->update();
        }
        else {
            play(AnimationType::IDLE, AnimationDirection::NONE);
        }
    }
}