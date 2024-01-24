#include "entity.h"
#include "bn_camera_ptr.h"
#include "bn_fixed_point.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_char_base.h"
#include "bn_log.h"
#include "entity_animation_component.h"

namespace dl
{
    Entity::Entity(bn::camera_ptr &camera, bn::sprite_ptr &sprite) : _sprite(sprite), _camera(camera)
    {
        // default animation datas
        AnimationData *idleAnimation = new AnimationData();
        idleAnimation->type = AnimationType::IDLE;
        idleAnimation->speed = 8;
        idleAnimation->frames[AnimationDirection::BACK] = bn::array<int, 4>{4, 4, 4, 4};
        idleAnimation->frames[AnimationDirection::FRONT] = bn::array<int, 4>{0, 0, 0, 0};
        idleAnimation->frames[AnimationDirection::RIGHT] = bn::array<int, 4>{8, 8, 8, 8};

        AnimationData *walkAnimation = new AnimationData();
        walkAnimation->type = AnimationType::WALK;
        walkAnimation->speed = 8;
        walkAnimation->frames[AnimationDirection::BACK] = bn::array<int, 4>{5, 6, 7, 5};
        walkAnimation->frames[AnimationDirection::FRONT] = bn::array<int, 4>{1, 2, 3, 1};
        walkAnimation->frames[AnimationDirection::RIGHT] = bn::array<int, 4>{9, 10, 11, 9};

        AnimationData *attackAnimation = new AnimationData();
        attackAnimation->type = AnimationType::ATTACK;
        attackAnimation->speed = 8;
        attackAnimation->frames[AnimationDirection::FRONT] = bn::array<int, 4>{12, 13, 14, 12};
        attackAnimation->frames[AnimationDirection::BACK] = bn::array<int, 4>{15, 16, 17, 15};
        attackAnimation->frames[AnimationDirection::RIGHT] = bn::array<int, 4>{18, 19, 20, 18};

        _animationComponent = new EntityAnimationComponent(this, bn::array<AnimationData *, 7>{idleAnimation, walkAnimation, attackAnimation, nullptr, nullptr, nullptr, nullptr});
    }

    Entity::~Entity()
    {
    }

    void Entity::move(bn::fixed_point delta)
    {
        auto x = delta.x().to_double();
        auto y = delta.y().to_double();

        if (_animationComponent->get_currentAnimation() == AnimationType::ATTACK)
        {
            return;
        }
        
        if (x == 0 && y == 0)
        {
            _animationComponent->play(AnimationType::IDLE, AnimationDirection::NONE);
            return;
        }

        if (y == 0 && x != 0)
        {
            _animationComponent->play(AnimationType::WALK, x > 0 ? AnimationDirection::RIGHT : AnimationDirection::LEFT);
        }
        else
        {
            _animationComponent->play(AnimationType::WALK, y > 0 ? AnimationDirection::FRONT : AnimationDirection::BACK);
        }

        _position += delta;
        _sprite.set_position(_position);
    }

    void Entity::attack()
    {
        _animationComponent->play(AnimationType::ATTACK, AnimationDirection::NONE, true);
    }

    void Entity::set_position(bn::fixed_point position)
    {
        _position = position;
        _sprite.set_position(_position);
    }

    bn::sprite_ptr Entity::get_sprite()
    {
        return _sprite;
    }

    void Entity::update()
    {
        _animationComponent->update();
    }
} // dl
