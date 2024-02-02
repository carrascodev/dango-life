#include "player.h"

namespace dl {
    class ActorState {
        public:
            ActorState(Actor* entity);
            virtual ~ActorState();
            virtual void begin_state();
            virtual void update();
            virtual void exit_state();
        protected:
            Actor* _entity;
    };
}
