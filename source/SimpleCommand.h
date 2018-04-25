// SimpleCommand.h
#ifndef have_SimpleCommand
#define have_SimpleCommand

#include <vector>
#include <cstdio>
#include "SimpleLength.h"
#include "simplePwCommands.h"

class SimpleCommand
{
    SPW_COMMAND m_command;
    std::vector<SimpleLength> m_arguments;
    static bool m_penIsDown;

public:
    SimpleCommand();
    SimpleCommand(SPW_COMMAND c, SimpleLength l);
    SimpleCommand(SPW_COMMAND c, std::vector<SimpleLength> vl);
    virtual ~SimpleCommand();

    void writePath(FILE *fp);

    SPW_COMMAND getCommand()
    {
        return m_command;
    }

    long xComponent();
    long yComponent();

    bool isAbsolute()
    {
        switch(m_command)
        {
            case SPW_COMMAND_ABS_MOVE:
            case SPW_COMMAND_ABS_UP:
            case SPW_COMMAND_ABS_DOWN:
            case SPW_COMMAND_ABS_LEFT:
            case SPW_COMMAND_ABS_RIGHT:
                return true;
        }

        return false;
    }
};



#endif // have_SimpleCommand

