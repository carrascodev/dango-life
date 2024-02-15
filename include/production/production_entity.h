//
// Created by Henrique Pagnossi on 2024-02-02.
//
#pragma once

#include "entity.h"
#include "bn_optional.h"
#include "generator_production_component.h"

namespace dl {
    enum class ProductionState {
        IDLE,
        GENERATING,
        COLLECTING
    };

    class ProductionEntity : public IEntity {
    public:
        virtual void produce(int amount) = 0;

        virtual void collect() = 0;

        virtual void update();

        inline void set_state(ProductionState state) { _state = state; }
        inline ProductionState get_state() { return _state; }

        virtual void on_complete() = 0;

    protected:
        bn::optional<GeneratorProductionComponent> _generator;
        ProductionState _state;
    };
} // dl
