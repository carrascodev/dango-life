#include "actor_animation_component.h"
#include "actor.h"
#include "bn_sprite_items_char_base.h"
#include "entity_direction.h"

namespace dl
{
    ActorAnimationComponent::ActorAnimationComponent(Actor *entity, bn::array<AnimationData *, 7> animations) : _entity(entity), _animations(animations)
    {
        entity->set_direction(EntityDirection::FRONT);
    }

    ActorAnimationComponent::~ActorAnimationComponent()
    {
    }

    void ActorAnimationComponent::play(AnimationType type, EntityDirection direction, bool once)
    {
        if (_animation.has_value() && _currentAnimation == type && (_entity->get_direction() == direction))
        {
            return;
        }

        if (direction == EntityDirection::NONE)
        {
            direction = _entity->get_direction();
        }

        _currentAnimation = type;
        _entity->set_direction(direction);
        auto animationData = _animations[static_cast<int>(type)];
        _entity->get_sprite().set_horizontal_flip(direction == EntityDirection::LEFT);
        if (direction == EntityDirection::LEFT)
        {
            direction = EntityDirection::RIGHT;
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

    void ActorAnimationComponent::add_animation(AnimationData *animation)
    {
        _animations[static_cast<int>(animation->type)] = animation;
    }

    void ActorAnimationComponent::update()
    {
        if(_animation.has_value() && !_animation->done())
        {
            _animation->update();
        }
    }
}