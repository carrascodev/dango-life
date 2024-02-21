//
// Created by Henrique Pagnossi on 2024-02-02.
//
#pragma once

#include <bn_timer.h>
#include <bn_optional.h>
#include <bn_unique_ptr.h>

namespace dl {
    class ProductionEntity;
    class GeneratorProductionComponent {
        public:
                GeneratorProductionComponent(ProductionEntity* entity, unsigned long durationTicks,
        int cycles,
        int speed = 1
        );

        void start();

        void stop();

        void pause();

        void update();

        inline int get_cycles() { return _cycles; }

        bool isDone() { return _cycles == 0; }

    protected:
        ProductionEntity* _entity;
        unsigned long _durationTicks;
        int _speed;
        int _cycles = -1;
        bn::optional<bn::timer> _timer;
    };

} // dl