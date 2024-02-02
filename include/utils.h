//
// Created by Henrique Pagnossi on 2024-01-30.
//
#pragma once
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_math.h"

#include "gen_grid_data.h"

namespace dl {
    static bn::fixed distance(bn::fixed_point a, bn::fixed_point b)
    {
        return bn::abs(a.x() - b.x()) + bn::abs(a.y() - b.y());
    }

    static double magnitude(bn::fixed_point a)
    {
        return bn::sqrt(a.x() + a.x() + (a.y() * a.y())).to_double();
    }

    static bn::fixed_point get_neighbour(EntityDirection direction) {
        switch (direction) {
            case EntityDirection::LEFT:
                return bn::fixed_point(-16, 0);
            case EntityDirection::RIGHT:
                return bn::fixed_point(16, 0);
            case EntityDirection::FRONT:
                return bn::fixed_point(0, 16);
            case EntityDirection::BACK:
                return bn::fixed_point(0, -16);
            default:
                return bn::fixed_point(0, 0);
        }
    }
}