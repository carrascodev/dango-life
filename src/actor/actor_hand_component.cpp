//
// Created by Henrique Pagnossi on 2024-02-15.
//

#include "actor_hand_component.h"

namespace dl {
    ActorHandComponent::ActorHandComponent() {
        _currentTool = WorkTool::HOE;
        _observer = nullptr;
    }

    ActorHandComponent::~ActorHandComponent() {
        _observer = nullptr;
    }

    void ActorHandComponent::switch_tool(bool left) {
        int shift = left ? -1 : 1;
        int toolValue = static_cast<int>(_currentTool);

        if(shift + toolValue < 0) {
            _currentTool = WorkTool::WATERING_CAN;
        }
        else if(shift + toolValue > static_cast<int>(WorkTool::WATERING_CAN)) {
            _currentTool = WorkTool::HOE;
        }
        else {
            _currentTool = static_cast<WorkTool>(toolValue + shift);
        }

        if(_observer != nullptr) {
            _observer->on_notify(_currentTool);
        }
    }

    void ActorHandComponent::attach(IObserver<dl::WorkTool> *observer) {
        _observer = observer;
    }

    void ActorHandComponent::detach(IObserver<dl::WorkTool> *observer) {
        _observer = nullptr;
    }

    WorkTool &ActorHandComponent::get_tool() {
        return _currentTool;
    }

} // dl