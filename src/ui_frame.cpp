//
// Created by Henrique Pagnossi on 2024-01-25.
//

#include "ui_frame.h"
#include <new>
#include <bn_window.h>
#include "bn_sprite_items_spr_ui_money_hud.h"

namespace dl {
    UIFrame::UIFrame(bn::camera_ptr &camera) : _camera(camera)
    {
        register_ui_panels();
    }

    UIFrame::~UIFrame() {

    }

    void UIFrame::update() {

    }

    void UIFrame::register_ui_panels() {
        bn::sprite_ptr moneyHudSprite = bn::sprite_items::spr_ui_money_hud.create_sprite(0, 0);
        _money_hud = new MoneyHud(_camera, moneyHudSprite, bn::fixed_point(92,-70),_text_generator, false, 0);
        _money_hud->show();
    }


} // dl