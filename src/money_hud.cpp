//
// Created by Henrique Pagnossi on 2024-01-25.
//

#include <bn_string.h>
#include "money_hud.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_sprite_ptr.h"

namespace dl {
    MoneyHud::MoneyHud(bn::camera_ptr &camera, Player& player,bn::sprite_ptr &sprite, bn::fixed_point position, bn::sprite_text_generator textGenerator, bool visible,
                       int zOrder) : UIPanel(camera, sprite, position, visible, zOrder), _text_generator(textGenerator), _player(player) {
        _money = _player.get_money();
        addListeners();
    }

    MoneyHud::~MoneyHud() {
        UIPanel::~UIPanel();
        removeListeners();
    }

    void MoneyHud::set_money(int money) {
        _money = money;
        show();
    }

    void MoneyHud::show() {
        UIPanel::show();
        _text_sprites.clear();
        _text_generator.generate(_camera.position().x() + _position.x() - 10, _camera.position().x() + _position.y() - 1, bn::to_string<10>(_money), _text_sprites);
        _text_generator.set_left_alignment();
    }

    void MoneyHud::hide() {
        UIPanel::hide();
    }

    void MoneyHud::addListeners() {
        _player.attach(this);
    }

    void MoneyHud::removeListeners() {
        _player.detach(this);
    }

    void MoneyHud::on_notify(Player& data) {
        set_money(_player.get_money());
    }


} // dl