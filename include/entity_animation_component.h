#include "bn_optional.h"
#include "bn_sprite_animate_actions.h"
#include "animation_data.h"

namespace dl {
    class Entity;
    class EntityAnimationComponent {
        public:
            EntityAnimationComponent(Entity* entity, bn::array<AnimationData*, 7> animations);
            ~EntityAnimationComponent();
            /// @brief 
            /// @param animation 
            /// @param direction 
            /// @param loop -1 = forever, 0 = don't update, 1 = once, etc
            void play(AnimationType animation, AnimationDirection direction, bool once = false);
            void add_animation(AnimationData* animation);
            inline AnimationType get_currentAnimation() {return _currentAnimation;}
            void update();
        protected:
            Entity* _entity;
            bn::optional<bn::sprite_animate_action<8>> _animation;
            AnimationType _currentAnimation;
            AnimationDirection _currentDirection;
            bn::array<AnimationData*, 7> _animations;
    };
}