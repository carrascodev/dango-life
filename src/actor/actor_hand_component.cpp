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

    void ActorHandComponent::switch_tool() {
        if(_currentTool == WorkTool::SEEDS) {
            _currentTool = WorkTool::HOE;
        } else {
            _currentTool = static_cast<WorkTool>(static_cast<int>(_currentTool) + 1);
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