#pragma once
#include "player.h"

namespace dl {
    template<typename T>
    class EntityState {
        public:
            EntityState(T& entity);
            virtual ~EntityState();
            virtual void begin_state();
            virtual void update();
            virtual void exit_state();
        protected:
            T& _entity;
    };
}
