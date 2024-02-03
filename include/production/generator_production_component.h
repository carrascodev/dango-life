//
// Created by Henrique Pagnossi on 2024-02-02.
//
#pragma once

#include <bn_timer.h>
#include <bn_optional.h>

namespace dl {
    class ProductionEntity;
    class GeneratorProductionComponent {
        public:
                GeneratorProductionComponent(ProductionEntity & entity, unsigned int durationTicks,
        int cycles,
        int speed = 1
        );

        void start();

        void stop();

        void update();

        inline int get_cycles() { return _cycles; }

    protected:
        ProductionEntity &_entity;
        unsigned int _durationTicks;
        int _speed;
        int _cycles;
        bn::optional<bn::timer> _timer = bn::nullopt;
    };

} // dl