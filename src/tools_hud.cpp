//
// Created by Henrique Pagnossi on 2024-02-20.
//

#include "tools_hud.h"
#include "bn_sprite_items_spr_ui_tool_hoe.h"
#include "bn_sprite_items_spr_ui_tool_watering_can.h"
#include "bn_sprite_items_spr_ui_tool_potato_seed.h"
#include "bn_sprite_items_spr_ui_tool_hand.h"


namespace dl {
    ToolsHud::ToolsHud(Player* player,bn::camera_ptr& camera, bn::sprite_ptr& sprite, bn::fixed_point position, bn::sprite_text_generator textGenerator, bool visible, int zOrder) : UIPanel(camera, sprite, position, visible, zOrder), _text_generator(textGenerator), _currentTool(bn::nullopt), _player(player) {
        addListeners();
        on_notify(_player->get_hand_component()->get_tool());
    }

    void ToolsHud::on_notify(WorkTool &tool) {
        if(_currentTool.has_value()) {
            _currentTool.value().set_visible(false);
        }

        if(tool == WorkTool::HOE) {
            _currentTool = bn::sprite_items::spr_ui_tool_hoe.create_sprite(0, 0);
        }
        else if(tool == WorkTool::WATERING_CAN) {
            _currentTool = bn::sprite_items::spr_ui_tool_watering_can.create_sprite(0, 0);
        }
        else if(tool == WorkTool::SEEDS) {
            _currentTool = bn::sprite_items::spr_ui_tool_potato_seed.create_sprite(0, 0);
        }
        else if(tool == WorkTool::HAND)
        {
            _currentTool = bn::sprite_items::spr_ui_tool_hand.create_sprite(0, 0);
        }
        _currentTool->set_position(_position.x(), _position.y());
        _currentTool->set_z_order(z_order);
        _currentTool->set_camera(_camera);
        _currentTool->set_visible(true);
    }

    ToolsHud::~ToolsHud() {
        removeListeners();
        _player = nullptr;
    }

    void ToolsHud::addListeners() {
        _player->get_hand_component()->attach(this);
    }

    void ToolsHud::removeListeners() {
        _player->get_hand_component()->detach(this);
    }
} // dl