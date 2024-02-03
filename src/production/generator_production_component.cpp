//
// Created by Henrique Pagnossi on 2024-02-02.
//
#include "generator_production_component.h"
#include "production_entity.h"


namespace dl {

    GeneratorProductionComponent::GeneratorProductionComponent(ProductionEntity &entity, unsigned int durationTicks,
                                                               int cycles, int speed) : _entity(entity),
                                                                                        _durationTicks(durationTicks),
                                                                                        _speed(speed),
                                                                                        _cycles(cycles) {

    }

    void GeneratorProductionComponent::start() {
        _timer = bn::timer();
        _entity.set_state(ProductionState::GENERATING);
    }

    void GeneratorProductionComponent::stop() {
        _timer = bn::nullopt;
        _entity.set_state(ProductionState::IDLE);
    }

    void GeneratorProductionComponent::update() {
        if (_timer.has_value() && _timer->elapsed_ticks() > _durationTicks) {
            _timer = bn::nullopt;
            _cycles--;
            if (_cycles == 0) {
                stop();
            }
        }
    }
} // dl