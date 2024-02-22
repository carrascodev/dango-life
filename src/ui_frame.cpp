//
// Created by Henrique Pagnossi on 2024-01-25.
//

#include "ui_frame.h"
#include <new>
#include <bn_window.h>
#include "bn_sprite_items_spr_ui_money_hud.h"
#include "bn_sprite_items_spr_ui_tool_menu.h"

namespace dl {
    UIFrame::UIFrame(Player* player,bn::camera_ptr &camera) : _camera(camera), _player(player)
    {
        register_ui_panels();
    }

    UIFrame::~UIFrame() {

    }

    void UIFrame::update() {

    }

    void UIFrame::register_ui_panels() {
        bn::sprite_ptr moneyHudSprite = bn::sprite_items::spr_ui_money_hud.create_sprite(0, 0);
        _money_hud = new MoneyHud(_camera,*_player, moneyHudSprite, bn::fixed_point(92,-70),_text_generator, false, 0);
        _money_hud->show();

        bn::sprite_ptr toolsHudSprite = bn::sprite_items::spr_ui_tool_menu.create_sprite(0, 0);
        _tools_hud = new ToolsHud(_player, _camera, toolsHudSprite, bn::fixed_point(-100,-64), _text_generator, true, 0);
    }


} // dl