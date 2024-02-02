//
// Created by Henrique Pagnossi on 2024-02-02.
//

#pragma once
#include "bn_fixed_point.h"

namespace dl {
    class IEntity {
        public:
            virtual ~IEntity() = default;
            virtual bn::fixed_point get_position() = 0;
            virtual void set_position(const bn::fixed_point position) = 0;
    };
}