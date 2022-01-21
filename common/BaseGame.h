#ifndef B_BASE_GAME_H
#define B_BASE_GAME_H

class BaseGame
{
public:
    BaseGame(){}
    virtual ~BaseGame(){}
    virtual void TestCallGameFunc() = 0;
};

#endif
