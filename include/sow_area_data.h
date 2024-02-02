//
// Created by Henrique Pagnossi on 2024-01-26.
//

namespace dl {
    struct SowAreaData {
        inline constexpr SowAreaData(const int x, const int y) : _x(x), _y(y) {

        }
        inline int x() const {
            return _x;
        }

        inline int y() const {
            return _y;
        }

    private:
        const int _x;
        const int _y;
    };
}
