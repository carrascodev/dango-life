//
// Created by Henrique Pagnossi on 2024-01-25.
//

#include "ui_panel.h"

dl::UIPanel::UIPanel(bn::camera_ptr& camera, bn::sprite_ptr& sprite, bn::fixed_point position, bool visible, int zOrder) :
        _sprite(sprite),
        _camera(camera),
        _position(position),
        _visible(visible),
        z_order(zOrder)
        {
            addListeners();
        }

dl::UIPanel::~UIPanel() {
    removeListeners();
}

void dl::UIPanel::show() {
    _visible = true;
    _sprite.set_position(_position);
    _sprite.set_z_order(z_order);
    _sprite.set_camera(_camera);
    _sprite.set_visible(true);
}

void dl::UIPanel::hide() {
    _visible = false;
    _sprite.set_visible(false);
}

void dl::UIPanel::addListeners() {}

void dl::UIPanel::removeListeners() {}

void dl::UIPanel::set_position(bn::fixed_point position) {
    _position = position;
    _sprite.set_position(_position);
}

bool dl::UIPanel::is_visible() {
    return _visible;
}


