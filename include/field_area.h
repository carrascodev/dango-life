//
// Created by Henrique Pagnossi on 2024-01-24.
//

#include <bn_sprite_ptr.h>

struct CropModel {
    bn::sprite_ptr sprite;
    int id;
};

namespace dl {
    class FieldArea {
        public:
            FieldArea();
            ~FieldArea();
            void update();
        protected:
            int _tiles[4][3];

    };

} // dl
