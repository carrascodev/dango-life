#pragma once

#include <bn_fixed_point.h>
#include <bn_rect_window.h>
#include <bn_sprite_ptr.h>
#include <bn_camera_ptr.h>

namespace dl {

    class UIPanel {
    public:
        UIPanel(bn::camera_ptr& camera, bn::sprite_ptr& sprite, bn::fixed_point position, bool visible = false, int zOrder = 0);
        virtual ~UIPanel();
        virtual void show();
        virtual void hide();
        virtual void addListeners() = 0;
        virtual void removeListeners() = 0;
        void set_position(bn::fixed_point position);
        bool is_visible();
    protected:
        bn::fixed_point _position;
        bool _visible;
        int z_order;
        bn::sprite_ptr _sprite;
        bn::camera_ptr _camera;
    };

} // dl
