#include "CommandList.h" 

CommandList::CommandList() 
{
}

CommandList::~CommandList() 
{
}

void CommandList::writePathData(FILE *fp)
{
    std::vector<SimpleCommand>::iterator it;
    for (it = begin(); it != end(); it++)
    {
        it->writePath(fp);
    }
}

long CommandList::maxXExtent()
{
    long res = 0;
    long curXpos = 0;

    std::vector<SimpleCommand>::iterator it;
    for(it = begin(); it != end(); it++)
    {
        SimpleCommand cur = *it;
        
        curXpos += cur.xComponent();

        if (curXpos > res)
        {
            res = curXpos;
        }
    }

    return res;
}

long CommandList::minXExtent()
{
    long res = 0;
    long curXpos = 0;

    std::vector<SimpleCommand>::iterator it;
    for(it = begin(); it != end(); it++)
    {
        SimpleCommand cur = *it;
        
        curXpos += cur.xComponent();

        if (curXpos < res)
        {
            res = curXpos;
        }
    }

    return res;
}

long CommandList::maxYExtent()
{
    long res = 0;
    long curYpos = 0;

    std::vector<SimpleCommand>::iterator it;
    for(it = begin(); it != end(); it++)
    {
        SimpleCommand cur = *it;
        
        curYpos += cur.yComponent();

        if (curYpos > res)
        {
            res = curYpos;
        }
    }

    return res;
}

long CommandList::minYExtent()
{
    long res = 0;
    long curYpos = 0;

    std::vector<SimpleCommand>::iterator it;
    for(it = begin(); it != end(); it++)
    {
        SimpleCommand cur = *it;
        
        curYpos += cur.yComponent();

        if (curYpos < res)
        {
            res = curYpos;
        }
    }

    return res;
}

