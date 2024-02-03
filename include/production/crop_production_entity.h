//
// Created by Henrique Pagnossi on 2024-02-02.
//
#pragma once

#include "production_entity.h"
#include "bn_camera_ptr.h"
#include "bn_sprite_ptr.h"

namespace dl {
	class CropEntity : public ProductionEntity {
	public:
        CropEntity(bn::camera_ptr& camera);

        void sow();
		void collect() override;
		void produce(int amount) override;

    private:
        bn::camera_ptr _camera;
        bn::sprite_ptr _soilSprite;
        bn::sprite_ptr _cropSprite;
	};

} // dl
