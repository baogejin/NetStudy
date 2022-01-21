#ifndef B_BASE_LOGIC_INTERFACE_H
#define B_BASE_LOGIC_INTERFACE_H

class BaseLogicInterface
{
public:
    BaseLogicInterface(){}
    virtual ~BaseLogicInterface(){}
    virtual void TestLogicInterfaceFunc() = 0;
};

#endif
