// SimplePathWriter.h
#ifndef have_SimplePathWriter
#define have_SimplePathWriter

#include "CommandList.h"

class SimplePathWriter
{
    CommandList m_commands;

public:
    SimplePathWriter();
    virtual ~SimplePathWriter();

    void setCommands(CommandList cl)
    {
        m_commands.set(cl);
    }

    static void startSvg(FILE *fp, SimpleLength width, SimpleLength height);
    static void endSvg(FILE *fp);
    static void startPath(FILE *fp, bool standAlone);
    static void startDashedPath(FILE *fp, bool standAlone);
    static void endPath(FILE *fp);
    void writeSvg(FILE *fp, bool adjustPos, const char *iFile);
    void writePathData(FILE *fp);
    void writeCompletePath(FILE *fp);
};



#endif // have_SimplePathWriter
