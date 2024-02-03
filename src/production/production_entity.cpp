//
// Created by Henrique Pagnossi on 2024-02-02.
//

#include "production_entity.h"
#include "bn_optional.h"

namespace dl {
    void ProductionEntity::update() {
        if(_state == ProductionState::GENERATING) {
            _generator.update();
        }
    }
} // dl