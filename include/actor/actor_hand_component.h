//
// Created by Henrique Pagnossi on 2024-02-15.
//
#pragma once

#include "bn_array.h"
#include "observer.h"

namespace dl {

    enum class WorkTool {
        HOE,
        WATERING_CAN,
        SEEDS
    };
    class ActorHandComponent : public ISubject<WorkTool> {
    public:
        ActorHandComponent();
        ~ActorHandComponent();

        void switch_tool();

        void attach(IObserver<dl::WorkTool>* observer) override;
        void detach(IObserver<dl::WorkTool>* observer) override;

        WorkTool &get_tool();

    private:
        WorkTool _currentTool;
        IObserver<WorkTool>* _observer;
    };

} // dl
