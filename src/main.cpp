#include "bn_core.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_item.h"
#include <new>

#include "input_handler.h"

#include "bn_regular_bg_items_bg_level0.h"
#include "bn_sprite_items_char_base.h"
#include "ui_frame.h"
#include "gen_sow_area_data.h"
#include "field_area.h"

int main() {
    bn::core::init();

    bn::regular_bg_ptr background = bn::regular_bg_items::bg_level0.create_bg(0, 0);
    bn::sprite_ptr playerSprite = bn::sprite_items::char_base.create_sprite(0, 0);

    bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
    camera.set_position(0, 0);

    background.set_camera(camera);
    playerSprite.set_camera(camera);

    dl::FieldArea *fieldArea = dl::FieldArea::create(camera);
    dl::Player *player = new dl::Player(camera, playerSprite);
    dl::InputHandler *inputHandler = new dl::InputHandler(player);
    dl::UIFrame *uiFrame = new dl::UIFrame(camera);

    while (true) {
        inputHandler->handleInput();
        uiFrame->update();
        fieldArea->update();
        player->update();
        bn::core::update();
    }
}
