//
// Created by Henrique Pagnossi on 2024-02-02.
//
#include "crop_production_entity.h"
#include "bn_sprite_items_spr_sowing_tiles.h"

namespace dl {
    void CropEntity::collect() {}

    void CropEntity::produce(int amount) {}

    void CropEntity::sow() {
        auto sprite = bn::sprite_items::spr_sowing_tiles.create_sprite(0, 0, 0);
        sprite.set_position(get_position());
        sprite.set_z_order(1);
        sprite.set_camera(_camera);
        sprite.set_visible(true);
    }
} // namespace dl
