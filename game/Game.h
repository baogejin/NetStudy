#ifndef B_GAME_H
#define B_GAME_H

#include "../common/BaseGame.h"
#include "../common/BaseLogicInterface.h"
#include <iostream>

class Game:public BaseGame
{
public:
    Game(BaseLogicInterface* pInterface):m_pInterface(pInterface){}
    virtual ~Game(){}
    virtual void TestCallGameFunc() override;

public:
    BaseLogicInterface* m_pInterface;
};

#endif
