#ifndef B_LOGIC_INTERFACE_H
#define B_LOGIC_INTERFACE_H

#include "../common/BaseLogicInterface.h"
#include <iostream>

class LogicInterface:public BaseLogicInterface
{
public:
    LogicInterface(){}
    virtual ~LogicInterface(){}
    virtual void TestLogicInterfaceFunc() override;
};

#endif
