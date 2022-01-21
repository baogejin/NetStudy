#include "Game.h"

extern "C"
BaseGame* CreateGame(BaseLogicInterface* pInterface)
{
    return new Game(pInterface);
}
