#include "SimplePathWriter.h" 
#include "simpleGlobals.h" 

SimplePathWriter::SimplePathWriter() 
{
}

SimplePathWriter::~SimplePathWriter() 
{
}

void SimplePathWriter::startSvg(FILE *fp, SimpleLength width, SimpleLength height)
{
    fprintf(fp, "<svg xmlns=\"http://www.w3.org/2000/svg\"");
    fprintf(fp, " width=\"%ld\"", width.getLength());
    fprintf(fp, " height=\"%ld\">\n", height.getLength());
}

void SimplePathWriter::endSvg(FILE *fp)
{
    fprintf(fp, "</svg>\n");
}

void SimplePathWriter::startPath(FILE *fp, bool standAlone)
{
    fprintf(fp, "<path ");

    if (standAlone)
    {
        fprintf(fp, 
                "stroke=\"black\"\n" 
                "stroke-width=\"1\"\n"
                "fill=\"red\"\n"
                "class=\"pathWriter\"\n");
    }

    fprintf(fp, "d=\"");
}

void SimplePathWriter::startDashedPath(FILE *fp, bool standAlone)
{
    fprintf(fp, "<path ");

    if (standAlone)
    {
        fprintf(fp, "stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"10 10\" fill=\"none\" class=\"pathWriter\" ");
    }

    fprintf(fp, "d=\"");
}

void SimplePathWriter::endPath(FILE *fp)
{
    fprintf(fp, "\"/>\n");
}

void SimplePathWriter::writePathData(FILE *fp)
{
    m_commands.writePathData(fp);
}

void SimplePathWriter::writeCompletePath(FILE *fp)
{
    startPath(fp, true);

    m_commands.writePathData(fp);

    endPath(fp);
}

void SimplePathWriter::writeSvg(FILE *fp, bool adjustPos, const char *iFile)
{
    // insert pen up, move to origin
    // for sanity when writing complete svg
    SimpleCommand c1(SPW_COMMAND_PEN_UP, SimpleLength());
    std::vector<SimpleLength> vl(2, SimpleLength(0));
    SimpleCommand c2(SPW_COMMAND_MOVE, vl);

    m_commands.insert(m_commands.begin(), c2);
    m_commands.insert(m_commands.begin(), c1);

    CommandListExtents cle = m_commands.computeDimensions();

    SimpleLength width = cle.xExtent() ;
    SimpleLength height = cle.yExtent();

    long pathXpos = cle.getMinX();
    long pathYpos = cle.minYExtent();

    bool pathOutOfBounds = !(pathXpos == 0 && pathYpos == 0);

    if (pathOutOfBounds)
    {
        if (adjustPos)
        {
            std::vector<SimpleLength> vadj;
            vadj.push_back(-pathXpos);
            vadj.push_back(pathYpos);
            SimpleCommand adj(SPW_COMMAND_MOVE, vadj);

            m_commands.insert(m_commands.begin() + 2, adj);
        }
        else
        {
            fprintf(stderr, "path is out of bounds by (x, y) = (%ld, %ld)\n", pathXpos, pathYpos);
        }
    }

    startSvg(fp, width, height);
    fprintf(fp, "<!--\n    created by %s version %s\n    from %s\n-->\n", progname, szVersion, iFile);
    writeCompletePath(fp);
    endSvg(fp);
}
