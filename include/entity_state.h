#include "player.h"

namespace dl {
    class EntityState {
        public:
            EntityState(Entity* entity);
            virtual ~EntityState();
            virtual void begin_state();
            virtual void update();
            virtual void exit_state();
        protected:
            Entity* _entity;
    };
}
