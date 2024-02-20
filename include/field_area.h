//
// Created by Henrique Pagnossi on 2024-01-24.
//

#include <bn_sprite_ptr.h>
#include <bn_vector.h>
#include <bn_optional.h>
#include <bn_unordered_map.h>
#include <bn_array.h>
#include "crop_production_entity.h"

namespace dl {

    const int SOIL_LAYER_Z_ORDER = 2;
    const int PLANT_LAYER_Z_ORDER = 1;

    class Player;

    class FieldArea {
    public:

        static FieldArea* create(bn::camera_ptr &camera) {
            if(_instance == nullptr)
                _instance = new FieldArea(camera);
            return _instance;
        }

        static FieldArea* instance() {
            return _instance;
        }

        ~FieldArea();

        void create_area();
        void update();



        void plant(int index);
        void sow(bn::fixed_point position);

        int get_tile_index(const bn::fixed_point &point);

        void water(const bn::fixed_point &point);

    private:
        explicit FieldArea(bn::camera_ptr &camera);
        bn::array<CropEntity*,24> _crops;
        bn::camera_ptr &_camera;
        inline static FieldArea* _instance = nullptr;
    };
} // dl
