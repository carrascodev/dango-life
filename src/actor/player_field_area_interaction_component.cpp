//
// Created by Henrique Pagnossi on 2024-01-28.
//
#include "player_field_area_interaction_component.h"
#include "player.h"
#include "bn_optional.h"
#include "field_area.h"
#include "entity_direction.h"
#include "bn_math.h"
#include "gen_grid_data.h"
#include "utils.h"


namespace dl {
    PlayerFieldAreaInteractionComponent::PlayerFieldAreaInteractionComponent(bn::camera_ptr &camera, Player *p)
            : _player(p), _camera(camera) {
        _cursor.set_camera(camera);
        _cursor.set_visible(false);
    }

    PlayerFieldAreaInteractionComponent::~PlayerFieldAreaInteractionComponent() {

    }

    void PlayerFieldAreaInteractionComponent::update() {
        show_cursor();
    }

    void PlayerFieldAreaInteractionComponent::show_cursor() {
        FieldArea *area = FieldArea::instance();
        bn::fixed_point playerPos = bn::fixed_point(_player->get_position().x(),
                                                    _player->get_position().y()+24);

        bn::fixed_point neighborPos = get_neighbour(_player->get_direction());
        bn::fixed_point cursorPos = playerPos + neighborPos;
        cursorPos.set_x(((cursorPos.x().integer()|15)+1)-8);
        cursorPos.set_y(((cursorPos.y().integer()|15)+1)-8);

        if(area->get_tile_index(cursorPos) > -1) {
            _cursor.set_visible(true);
            _cursor.set_position(cursorPos);
        }
        else {
            _cursor.set_visible(false);
        }
    }

    void PlayerFieldAreaInteractionComponent::do_sow() {
        FieldArea *area = FieldArea::instance();
        auto index = area->get_tile_index(_cursor.position());
        if (index > -1) {
            area->sow(_cursor.position());
        }
    }

    void PlayerFieldAreaInteractionComponent::do_water() {
        FieldArea *area = FieldArea::instance();
        auto index = area->get_tile_index(_cursor.position());
        if (index > -1) {
            area->water(_cursor.position());
        }
    }

    void PlayerFieldAreaInteractionComponent::do_plant() {
        FieldArea *area = FieldArea::instance();
        auto index = area->get_tile_index(_cursor.position());
        if (index > -1) {
            area->plant(index);
        }
    }

    void PlayerFieldAreaInteractionComponent::do_collect() {
        FieldArea *area = FieldArea::instance();
        auto index = area->get_tile_index(_cursor.position());
        if (index > -1 && area->try_collect(index)) {
            _player->add_money(20);
        }
    }
}


