// CommandList.h
#ifndef have_CommandList
#define have_CommandList

#include <cstdio>
#include <vector>
#include <limits.h>

#include "SimpleCommand.h"

class CommandListExtents
{
    friend class CommandList;

    long m_maxX;
    long m_maxY;
    long m_minX;
    long m_minY;

public:
    CommandListExtents()
        :m_maxX(LONG_MIN)
        ,m_maxY(LONG_MIN)
        ,m_minX(LONG_MAX)
        ,m_minY(LONG_MAX)
    {
    }

    virtual ~CommandListExtents(){}

    long getMinX()
    {
        return m_minX;
    }

    void update(long x, long y)
    {
        if (x > m_maxX)
        {
           m_maxX = x;
        }

        if (y > m_maxY)
        {
            m_maxY = y;
        }

        if (x < m_minX)
        {
            m_minX = x;
        }

        if (y < m_minY)
        {
            m_minY = y;
        }
    }

    long minYExtent()
    {
        return m_minY;
    }

    long xExtent()
    {
        return m_maxX - m_minX;
    }

    long yExtent()
    {
        return m_maxY - m_minY;
    }
};

class CommandList : public std::vector<SimpleCommand>
{
public:

    CommandList(){}
    virtual ~CommandList(){}

    void writePathData(FILE *fp)
    {
        std::vector<SimpleCommand>::iterator it;
        for (it = begin(); it != end(); it++)
        {
            it->writePath(fp);
        }
    }

    void set(CommandList cl)
    {
        *this = cl;
    }

    CommandListExtents computeDimensions()
    {
        long curX = 0;
        long curY = 0;
        CommandListExtents res;

        std::vector<SimpleCommand>::iterator it;
        for(it = begin(); it != end(); it++)
        {
            SimpleCommand cur = *it;

            if (cur.isAbsolute())
            {
                curX = cur.xComponent();
                curY = cur.yComponent();
            }
            else
            {
                curX += cur.xComponent();
                curY += cur.yComponent();
            }

            res.update(curX, curY);
        }

        return res;
    }
};



#endif // have_CommandList
