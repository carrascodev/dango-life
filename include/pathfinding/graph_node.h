//
// Created by Henrique Pagnossi on 2024-01-30.
//
#pragma once
#include "utils.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_math.h"

namespace dl {
    struct GraphNode {
        const bn::fixed_point position;
        bn::fixed get_distance(GraphNode* other) const
        {
            return dl::distance(position, other->position);
        }

        double operator <(GraphNode* other) const {
            return magnitude(position) < magnitude(other->position);
        }

        double operator <(GraphNode& other) const {
            return magnitude(position) < magnitude(other.position);
        }

        double operator >(GraphNode* other) const {
            return magnitude(position) > magnitude(other->position);
        }
        bool operator ==(GraphNode* other) const {
            return position.x().to_double() == other->position.x().to_double() &&
            position.y().to_double() == other->position.y().to_double();
        }
    };
}
