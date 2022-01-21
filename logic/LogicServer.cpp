#include "LogicInterface.h"
#include "../common/BaseGame.h"
#include <dlfcn.h>

const char* dllPath = "./game.so";
typedef BaseGame*(*CREATE_GAME)(BaseLogicInterface*);
int main()
{
    //test
    LogicInterface *pInterface = new LogicInterface();
    void* handle = dlopen(dllPath, RTLD_NOW);
    CREATE_GAME func = (CREATE_GAME)dlsym(handle, "CreateGame");
    BaseGame* game = func(pInterface);
    game->TestCallGameFunc();
    delete pInterface;
    pInterface = nullptr;
    return 0;
}
