#include "SimpleCommand.h" 

bool SimpleCommand::m_penIsDown = false;

SimpleCommand::SimpleCommand() 
{
}

SimpleCommand::SimpleCommand(SPW_COMMAND c, SimpleLength l)
    : m_command(c)
{
    m_arguments.push_back(l);
}

SimpleCommand::SimpleCommand(SPW_COMMAND c, std::vector<SimpleLength> vl)
    : m_command(c)
{
    std::vector<SimpleLength>::iterator it;
    for (it = vl.begin(); it != vl.end(); it++)
        m_arguments.push_back(*it);
}

SimpleCommand::~SimpleCommand() 
{
}

void SimpleCommand::writePath(FILE *fp)
{
    // right == +ve x
    // up == -ve y
    switch(m_command)
    {
        case SPW_COMMAND_NONE:
        {
            break;
        }
        case SPW_COMMAND_PEN_UP:
        {
            m_penIsDown = false;
            break;
        }
        case SPW_COMMAND_PEN_DOWN:
        {
            m_penIsDown = true;
            break;
        }
        case SPW_COMMAND_MOVE: // right,up
        {
            SimpleLength xLen = m_arguments[0].getLength();
            SimpleLength yLen = m_arguments[1].getLength();
            // yLen = -1 * yLen; as svg up is -ve y

            if (m_penIsDown)
            {
                fprintf(fp, "l%ld %ld ", xLen.getLength(), -1*yLen.getLength());
            }
            else
            {
                fprintf(fp, "m%ld %ld ", xLen.getLength(), -1*yLen.getLength());
            }

            break;
        }
        case SPW_COMMAND_UP:
        {
            SimpleLength l = m_arguments[0].getLength();
            // l = -1 * l; as svg up is -ve y

            if (m_penIsDown)
            {
                fprintf(fp, "v%ld ", -1*l.getLength());
            }
            else
            {
                fprintf(fp, "m0 %ld ", -1*l.getLength());
            }
            break;
        }
        case SPW_COMMAND_DOWN:
        {
            SimpleLength l = m_arguments[0].getLength();
            if (m_penIsDown)
            {
                fprintf(fp, "v%ld ", l.getLength());
            }
            else
            {
                fprintf(fp, "m0 %ld ", l.getLength());
            }
            break;
        }
        case SPW_COMMAND_LEFT:
        {
            SimpleLength l = m_arguments[0].getLength();
            if (m_penIsDown)
            {
                fprintf(fp, "h%ld ", -1*l.getLength());
            }
            else
            {
                fprintf(fp, "m%ld 0 ", -1*l.getLength());
            }
            break;
        }
        case SPW_COMMAND_RIGHT:
        {
            SimpleLength l = m_arguments[0].getLength();
            if (m_penIsDown)
            {
                fprintf(fp, "h%ld ", l.getLength());
            }
            else
            {
                fprintf(fp, "m%ld 0 ", l.getLength());
            }
            break;
        }
    }    
}

long SimpleCommand::xComponent()
{
    long res = 0;

    switch(m_command)
    {
        case SPW_COMMAND_MOVE:
        {
            SimpleLength xLen = m_arguments[0].getLength();
            res = xLen.getLength();
            break;
        }
        case SPW_COMMAND_LEFT:
        {
            SimpleLength l = m_arguments[0].getLength();
            res = -1*l.getLength();
            break;
        }
        case SPW_COMMAND_RIGHT:
        {
            SimpleLength l = m_arguments[0].getLength();
            res = l.getLength();
            break;
        }
    } 

    return res;
}

long SimpleCommand::yComponent()
{
    long res = 0;

    switch(m_command)
    {
        case SPW_COMMAND_MOVE:
        {
            SimpleLength yLen = m_arguments[1].getLength();
            res = -1*yLen.getLength(); // our up is svg -ve y
            break;
        }
        case SPW_COMMAND_UP:
        {
            SimpleLength l = m_arguments[0].getLength();
            res = -1*l.getLength();
            break;
        }
        case SPW_COMMAND_DOWN:
        {
            SimpleLength l = m_arguments[0].getLength();
            res = l.getLength();
            break;
        }
    }    

    return res;
}

