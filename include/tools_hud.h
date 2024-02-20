//
// Created by Henrique Pagnossi on 2024-02-20.
//
#pragma once

#include <bn_sprite_ptr.h>
#include <bn_fixed_point.h>
#include <bn_sprite_text_generator.h>
#include "ui_panel.h"
#include "actor_hand_component.h"
#include "observer.h"
#include "player.h"

namespace dl {

    class ToolsHud : public UIPanel, public IObserver<WorkTool> {
    public:
        ToolsHud(Player* player,bn::camera_ptr& camera, bn::sprite_ptr& sprite, bn::fixed_point position, bn::sprite_text_generator textGenerator, bool visible = false, int zOrder = 0);
        ~ToolsHud() override;

        void on_notify(WorkTool& tool) override;

        void addListeners() override;
        void removeListeners() override;
    private:
        bn::optional<bn::sprite_ptr> _currentTool;
        bn::vector<bn::sprite_ptr, 2> _text_sprites;
        bn::sprite_text_generator _text_generator;
        Player* _player;
    };

} // dl
