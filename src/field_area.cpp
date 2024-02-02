#include "field_area.h"
#include "gen_sow_area_data.h"
#include "bn_camera_ptr.h"
#include "player.h"
#include "bn_unordered_map.h"

#include "bn_sprite_items_spr_sowing_tiles.h"
#include "bn_sprite_items_spr_crop_corn.h"

namespace dl {
    FieldArea::FieldArea(bn::camera_ptr &camera) : _camera(camera) {
        _soilLayer = bn::unordered_map<bn::fixed_point, bn::sprite_ptr, 32>();
        _plantLayer = bn::unordered_map<bn::fixed_point, bn::optional<bn::sprite_ptr>, 32>();
        create_area();
    }

    FieldArea::~FieldArea() {

    }

    void FieldArea::update() {

    }

    void FieldArea::create_area() {
        for (int i = 0; i < 24; i++) {
            int x = sow_area[i].x();
            int y = sow_area[i].y();
            auto sprite = bn::sprite_items::spr_sowing_tiles.create_sprite(0, 0, 0);
            sprite.set_position(x, y);
            sprite.set_z_order(1);
            sprite.set_camera(_camera);
            sprite.set_visible(false);
            _soilLayer.insert(sprite.position(), sprite);
        }
    }

    void FieldArea::plant(int index) {
        int x = sow_area[index].x();
        int y = sow_area[index].y();
        auto sprite = bn::sprite_items::spr_crop_corn.create_sprite(0, 0, 0);
        sprite.set_position(x, y - 8);
        sprite.set_z_order(1);
        sprite.set_camera(_camera);
        sprite.set_visible(true);
        _plantLayer.try_emplace(sprite.position(), sprite);
    }

    void FieldArea::sow(bn::fixed_point position) {
        auto sprite = _soilLayer.at(position);
        sprite.set_visible(true);
    }
} // dl