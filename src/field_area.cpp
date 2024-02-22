#include "field_area.h"
#include "gen_sow_area_data.h"
#include "bn_camera_ptr.h"
#include "player.h"
#include "bn_unordered_map.h"
#include "crop_entity.h"

#include "bn_sprite_items_spr_sowing_tiles.h"
#include "bn_sprite_items_spr_crop_corn.h"

namespace dl {
    FieldArea::FieldArea(bn::camera_ptr &camera) : _camera(camera) {
        create_area();
    }

    FieldArea::~FieldArea() {

    }

    void FieldArea::update() {
        for (int i = 0; i < 24; ++i) {
            if(_crops[i] != nullptr)
                _crops[i]->update();
        }
    }

    void FieldArea::create_area() {
        for (int i = 0; i < 24; i++) {
            auto position = bn::fixed_point(sow_area[i].x(), sow_area[i].y());
            _crops[i] = new CropEntity(_camera,position);
        }
    }

    void FieldArea::plant(int index) {
        if(_crops[index] != nullptr)
            _crops[index]->produce(1);

    }

    int FieldArea::get_tile_index(const bn::fixed_point &point) {
        for (int i = 0; i < 24; ++i) {
            if (_crops[i]->get_position() == point) {
                return i;
            }
        }

        return -1;
    }

    void FieldArea::sow(bn::fixed_point position) {
        int index = get_tile_index(position);
        if (index > -1) {
            _crops[index]->sow();
        }
    }

    void FieldArea::water(const bn::fixed_point &point) {
        int index = get_tile_index(point);
        if (index > -1) {
            _crops[index]->water();
        }
    }

    bool FieldArea::try_collect(int index) {
        return _crops[index] != nullptr && _crops[index]->try_collect();
    }
} // dl