#include "input_handler.h"
#include "bn_keypad.h"
#include "player.h"
#include "actor_hand_component.h"

using namespace dl;

dl::InputHandler::InputHandler(Player* player)
{
    this->_player = player;
}

void dl::InputHandler::handleInput() {
    bn::fixed x = 0;
    bn::fixed y = 0;

    if(bn::keypad::left_held()) {
       x = -1;
    }
    if(bn::keypad::right_held()) {
        x = 1;
    }
    if(bn::keypad::up_held()) {
         y = -1;
    }
    if(bn::keypad::down_held()) {
        y = 1;
    }

    if(x.integer() != 0 && y.integer() != 0) {
        x *= bn::fixed(0.7);
        y *= bn::fixed(0.7);
    }
    if(bn::keypad::a_pressed()) 
    {
        _player->interact();
        return;
    }

    if(bn::keypad::l_pressed())
    {
        _player->get_hand_component()->switch_tool(true);
        return;
    }

    if(bn::keypad::r_pressed())
    {
        _player->get_hand_component()->switch_tool(false);
        return;
    }

    _player->move(bn::fixed_point(x, y));
}