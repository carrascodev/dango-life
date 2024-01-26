//
// Created by Henrique Pagnossi on 2024-01-25.
//

#include <bn_sprite_text_generator.h>
#include "common_variable_8x16_sprite_font.h"
#include "money_hud.h"
#include "bn_window.h"

namespace dl {

    class UIFrame {
    public:
        UIFrame(bn::camera_ptr& camera);
        ~UIFrame();
        void register_ui_panels();
        void update();

    private:
        bn::sprite_text_generator _text_generator = bn::sprite_text_generator(common::variable_8x16_sprite_font);
        MoneyHud* _money_hud;
        bn::camera_ptr& _camera;
        bn::window _window = bn::window::external();
    };

} // dl
