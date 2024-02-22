//
// Created by Henrique Pagnossi on 2024-02-02.
//
#include "crop_entity.h"
#include "bn_sprite_items_spr_sowing_tiles.h"
#include "bn_optional.h"
#include "bn_sprite_items_spr_crop_corn.h"
#include "bn_math.h"

namespace dl {

    CropEntity::CropEntity(bn::camera_ptr &camera, bn::fixed_point position) :
            _camera(camera),
            _position(position),
            _soilSprite(bn::nullopt),
            _cropSprite(bn::nullopt) {
        _state = ProductionState::IDLE;
    }

    bool CropEntity::try_collect() {
        if(_cropSprite.has_value() && _state == ProductionState::IDLE && _cropIndex == 5)
        {
            _cropSprite->set_visible(false);
            _cropSprite = bn::nullopt;

            _generator = bn::make_optional<GeneratorProductionComponent>(this, 30 * (3 * (1e5)), 1);
            _generator->start();

            return true;
        }

        return false;
    }

    void CropEntity::produce(int amount) {
        if(!_soilSprite.has_value())
            return;

        if(_cropSprite.has_value() && _state != ProductionState::IDLE)
           return;
        else {
            _generator =  bn::make_optional<GeneratorProductionComponent>(this, 10 * (1 * (1e5)), 6);

            auto sprite = bn::sprite_items::spr_crop_corn.create_sprite(0, 0, 0);
            sprite.set_position(get_position().x(), get_position().y() - 8);
            sprite.set_z_order(1);
            sprite.set_camera(_camera);
            sprite.set_visible(true);
            _cropSprite = sprite;

            if(_soilIndex == 1) {
                _generator->start();
            }
        }
    }

    void CropEntity::sow() {
        if (_soilSprite.has_value()) {
            _soilSprite->set_visible(true);
        } else {
            auto sprite = bn::sprite_items::spr_sowing_tiles.create_sprite(0, 0, 0);
            sprite.set_position(get_position());
            sprite.set_z_order(2);
            sprite.set_camera(_camera);
            sprite.set_visible(true);
            _soilSprite = sprite;
        }
        _generator =  bn::make_optional<GeneratorProductionComponent>(this, 30 * (3 * (1e5)), 1);
        _generator->start();
    }

    void CropEntity::update() {
        ProductionEntity::update();
    }

    void CropEntity::on_complete() {
            if(_cropSprite.has_value() == false)
            {
                if(_soilIndex == 0)
                {
                    _soilSprite = bn::nullopt;
                    _soilIndex = 0;
                }
                else
                {
                    auto sprite = bn::sprite_items::spr_sowing_tiles.create_sprite(0, 0, 0);
                    sprite.set_position(get_position());
                    sprite.set_z_order(2);
                    sprite.set_camera(_camera);
                    sprite.set_visible(true);

                    _soilSprite = sprite;
                    _generator = bn::make_optional<GeneratorProductionComponent>(this, 30 * (3 * (1e5)), 1);
                    _generator->start();
                }
            }
            else
            {
                _state = ProductionState::IDLE;
            }

    }

    void CropEntity::water() {
        if(_soilSprite.has_value())
        {
            _soilIndex = 1;
            auto sprite = bn::sprite_items::spr_sowing_tiles.create_sprite(0, 0, 1);
            sprite.set_position(get_position());
            sprite.set_z_order(2);
            sprite.set_camera(_camera);
            sprite.set_visible(true);
            _soilSprite = sprite;
        }

        if(_cropSprite.has_value() && _generator != bn::nullopt) {
            _generator->start();
        }
        else {
            _generator =  bn::make_optional<GeneratorProductionComponent>(this, 30 * (3 * (1e5)), 1);
            _generator->start();
        }
    }

    void CropEntity::on_cycle_complete() {
        if(!_cropSprite.has_value())
            return;

        if(_cropIndex < 5)
            _cropIndex++;
        auto sprite = bn::sprite_items::spr_crop_corn.create_sprite(0, 0, _cropIndex);
        sprite.set_position(get_position().x(), get_position().y() - 8);

        _cropSprite = sprite;
    }
} // namespace dl
