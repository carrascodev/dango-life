//
// Created by Henrique Pagnossi on 2024-01-25.
//
#include <bn_fixed_point.h>
#include <bn_sprite_text_generator.h>
#include "ui_panel.h"

namespace dl {

    class MoneyHud : public UIPanel {
    public:
        MoneyHud(bn::camera_ptr& camera,bn::sprite_ptr& sprite, bn::fixed_point position, bn::sprite_text_generator textGenerator, bool visible = false, int zOrder = 0);

        ~MoneyHud() override;

        void set_money(int money);
        void show() override;
        void hide() override;

        private:
        unsigned int _money;
        bn::vector<bn::sprite_ptr, 9> _text_sprites;
        bn::sprite_text_generator _text_generator;
    };

} // dl
