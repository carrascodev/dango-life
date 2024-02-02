//
// Created by Henrique Pagnossi on 2024-01-24.
//

#include <bn_sprite_ptr.h>
#include <bn_vector.h>
#include <bn_optional.h>
#include <bn_unordered_map.h>

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

        bn::unordered_map<bn::fixed_point,bn::sprite_ptr, 32>& get_soil_layer() {
            return _soilLayer;
        }

        bn::unordered_map<bn::fixed_point,bn::optional<bn::sprite_ptr>, 32>& get_plant_layer() {
            return _plantLayer;
        }

        void plant(int index);
        void sow(bn::fixed_point position);

    private:
        explicit FieldArea(bn::camera_ptr &camera);
        bn::unordered_map<bn::fixed_point, bn::sprite_ptr, 32> _soilLayer;
        bn::unordered_map<bn::fixed_point,bn::optional<bn::sprite_ptr>, 32> _plantLayer;
        bn::camera_ptr &_camera;
        inline static FieldArea* _instance = nullptr;
    };
} // dl
