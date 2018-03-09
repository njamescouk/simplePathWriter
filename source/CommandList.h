// CommandList.h
#ifndef have_CommandList
#define have_CommandList

#include <cstdio>
#include <vector>
#include "SimpleCommand.h"

class CommandList : public std::vector<SimpleCommand>
{
    long maxXExtent();
    long maxYExtent();

public:
    CommandList();
    virtual ~CommandList();

    void writePathData(FILE *fp);
    long minXExtent();
    long minYExtent();

    void set(CommandList cl)
    {
        *this = cl;
    }

    long xExtent()
    {
        return maxXExtent() - minXExtent();
    }

    long yExtent()
    {
        return maxYExtent() - minYExtent();
    }
};



#endif // have_CommandList
