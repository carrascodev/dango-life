#include "player.h"

namespace dl {
    class InputHandler {
        public:
            InputHandler(Player* player);
            void handleInput();
        private:
            Player* _player;
    };
}