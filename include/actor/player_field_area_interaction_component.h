//
// Created by Henrique Pagnossi on 2024-01-28.
//
#pragma once

#include <bn_camera_ptr.h>
#include "bn_sprite_ptr.h"
#include "bn_optional.h"

#include "bn_sprite_items_spr_sowing_cursor.h"

namespace dl {

    class Player;
    class PlayerFieldAreaInteractionComponent {
    public:
        PlayerFieldAreaInteractionComponent(bn::camera_ptr& camera, Player* p);
        ~PlayerFieldAreaInteractionComponent();

        void update();
        void do_sow();

        void do_water();

        void do_plant();

        void do_collect();

    private:
        Player* _player;
        bn::camera_ptr _camera;
        bn::sprite_ptr _cursor = bn::sprite_items::spr_sowing_cursor.create_sprite(0, 0, 0);
        void show_cursor();
    };

} // dl