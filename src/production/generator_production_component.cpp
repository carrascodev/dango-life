//
// Created by Henrique Pagnossi on 2024-02-02.
//
#include "generator_production_component.h"
#include "production_entity.h"


namespace dl {

    GeneratorProductionComponent::GeneratorProductionComponent(ProductionEntity* entity, unsigned long durationTicks,int cycles, int speed) :
            _entity(entity),
            _durationTicks(durationTicks),
            _speed(speed),
            _timer(bn::nullopt),
            _cycles(cycles) {

    }

    void GeneratorProductionComponent::start() {
        _timer = bn::make_optional<bn::timer>();
        _entity->set_state(ProductionState::GENERATING);
    }

    void GeneratorProductionComponent::stop() {
        _timer = bn::nullopt;
        if(_entity->get_state() == ProductionState::GENERATING)
            _entity->on_complete();
        _entity->set_state(ProductionState::IDLE);
    }

    void GeneratorProductionComponent::update() {
        int elapsed = _timer->elapsed_ticks();
        if (_timer.has_value() && elapsed > _durationTicks) {
            _timer->restart();
            _cycles--;
            _entity->on_cycle_complete();
            if (_cycles == 0) {
                stop();
            }
        }
    }
} // dl