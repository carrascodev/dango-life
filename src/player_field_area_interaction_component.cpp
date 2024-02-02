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
        bn::unordered_map<bn::fixed_point, bn::sprite_ptr, 32> &soil_layer = area->get_soil_layer();
        //bn::unordered_map<bn::fixed_point, bn::optional<bn::sprite_ptr>, 32> &plant_layer = area->get_plant_layer();

        bn::fixed_point playerPos = bn::fixed_point(_player->get_position().x(),
                                                    _player->get_position().y()+24);

        bn::fixed_point neighborPos = get_neighbour(_player->get_direction());
        bn::fixed_point cursorPos = playerPos + neighborPos;
        cursorPos.set_x(((cursorPos.x().integer()|15)+1)-8);
        cursorPos.set_y(((cursorPos.y().integer()|15)+1)-8);

        if(soil_layer.contains(cursorPos)) {
            _cursor.set_visible(true);
            _cursor.set_position(cursorPos);
        }
        else {
            _cursor.set_visible(false);
        }
    }

    void PlayerFieldAreaInteractionComponent::do_sow() {
        FieldArea *area = FieldArea::instance();
        bn::unordered_map<bn::fixed_point, bn::sprite_ptr, 32> &soil_layer = area->get_soil_layer();
        if (soil_layer.contains(_cursor.position())) {
            FieldArea *area = FieldArea::instance();
            area->sow(_cursor.position());
        }
    }


}


