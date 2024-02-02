#include "bn_optional.h"
#include "bn_sprite_animate_actions.h"
#include "animation_data.h"

namespace dl {
    class Actor;
    class ActorAnimationComponent {
        public:
            ActorAnimationComponent(Actor* entity, bn::array<AnimationData*, 7> animations);
            ~ActorAnimationComponent();
            /// @brief 
            /// @param animation 
            /// @param direction 
            /// @param loop -1 = forever, 0 = don't update, 1 = once, etc
            void play(AnimationType animation, EntityDirection direction, bool once = false);
            void add_animation(AnimationData* animation);
            inline AnimationType get_currentAnimation() {return _currentAnimation;}
            inline bool is_playing() {return _animation.has_value() && !_animation->done();}
            void update();
        protected:
            Actor* _entity;
            bn::optional<bn::sprite_animate_action<12>> _animation;
            AnimationType _currentAnimation;
            bn::array<AnimationData*, 7> _animations;
    };
}