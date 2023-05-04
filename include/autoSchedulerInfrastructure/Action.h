#if !defined(ACTION_H)
#define ACTION_H

#include <iostream>
#include <autoSchedulerInfrastructure/CodeIR.h>
class Action
{
protected:
    std::string m_Action_Type;

public:
    std::string &GetActionType()
    {
        return m_Action_Type;
    }

    virtual bool IsLegal(CodeIR *code_ir) = 0;
    virtual void Apply(CodeIR *code_ir) = 0;
};

#endif // ACTION_H
