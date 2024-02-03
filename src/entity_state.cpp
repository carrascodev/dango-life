//
// Created by Henrique Pagnossi on 2024-01-22.
//

#include "entity_state.h"

namespace dl {
    template<typename T>
    EntityState<T>::EntityState(T &entity) : _entity(entity) {

    }

    template<typename T>
    EntityState<T>::~EntityState() {
    }

    template<typename T>
   void EntityState<T>::begin_state() {

    }

    template<typename T>
    void EntityState<T>::update() {
    }

    template<typename T>
    void EntityState<T>::exit_state() {
    }
} // dl