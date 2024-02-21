//
// Created by Henrique Pagnossi on 2024-02-02.
//
#pragma once

#include "production_entity.h"
#include "bn_camera_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_optional.h"
#include "observer.h"

namespace dl {
	class CropEntity : public ProductionEntity {
	public:
        explicit CropEntity(bn::camera_ptr& camera, bn::fixed_point position);

        void sow();
		void collect() override;
		void produce(int amount) override;
        void water();
        bn::fixed_point get_position() override { return _position; }
        void set_position(bn::fixed_point position) override { _position = position; }
        void update() override;
        void on_complete() override;
        void on_cycle_complete() override;

    private:
        bn::camera_ptr _camera;
        bn::fixed_point _position;
        bn::optional<bn::sprite_ptr> _soilSprite;
        bn::optional<bn::sprite_ptr> _cropSprite;
        int _cropIndex;
        int _soilIndex;
    };

} // dl
