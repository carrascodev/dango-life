//
// Created by Henrique Pagnossi on 2024-01-26.
//
#include <bn_fixed_point.h>

namespace dl {
    struct SowAreaData {
    public:
        inline constexpr SowAreaData(const int x, const int y) : _position(x, y) {

        }
        [[nodiscard]] inline constexpr bn::fixed_point position() const {
            return _position;
        }

    private:
        const bn::fixed_point _position;
    };
}
