#include <cstdio>
#include <string>
#include <cstring>
#include "yaccFns.h"
#include "SimpleGlobals.h"
#include "CmdLineParser.h" 

extern SimplePathWriter gResult;

#pragma warning( disable : 4996 )

void usage(FILE *fp);

int main (int argc, char *argv[])
{
    progname = argv[0];

    std::map<std::string, OptionSpec> specs;

    specs["h"] = OptionSpec(false, "help. Writes usage text and exits.");
    specs["v"] = OptionSpec(false, "version. Writes version and exits.");
    specs["s"] = OptionSpec(false, "svg. Write complete svg to stdout.");
    specs["p"] = OptionSpec(false, "path. Write complete path to stdout.");
    specs["o"] = OptionSpec(true, "output file. Write result to output.");
    specs["a"] = OptionSpec(false, "adjust. Ensure path is inside svg first quadrant.");

    CmdLineSpec cls(specs);

    pcldebug = 1;
    CmdLineParser clp(argc, argv, cls);

    Cmdline cmdline = clp.parse();
    if (!cmdline.isValid())
    {
        return 1;
    }

    if (cmdline.hasOption("v"))
    {
        printf ("%s version 1.0\n", argv[0]);
        return 0;
    }

    if (cmdline.hasOption("h"))
    {
        fprintf(stdout, "%s [-h] [-v] [-s [-a]] [-p] [-o outputFile] [file]\n"
                        "produces svg path from up/down/left/right/move\n"
                        "instructions, combined with pen up/down commands\n"
                        "defaults to writing path data to stdout\n\n"
                        "options:\n",
                        progname);
        cls.help(progname, stdout);
        return 0;
    }

    bool writeSvg = cmdline.hasOption("s");
    bool writeCompletePath = cmdline.hasOption("p");
    bool adjustPos = cmdline.hasOption("a");
    if (adjustPos && !writeSvg)
        fprintf(stderr, "-a has no effect unless -s applied\n");

    int res = 0;
    FILE *ifp = stdin;

    if (cmdline.numArguments() >= 1)
    {
        ifp = fopen(cmdline.getArgument(0).c_str(), "rt");
        if (ifp == 0)
        {
            perror(cmdline.getArgument(0).c_str());
            return 1;
        }
    }

    yyin = ifp;
    yydebug = 1;
    if (yyparse() == 0)
    {
        FILE *ofp = stdout;
        if (cmdline.hasOption("o"))
        {
            ofp = fopen(cmdline.getOptionValue("o").c_str(), "wt");
            if (ofp == 0)
            {
                perror(cmdline.getOptionValue("o").c_str());
                ofp = stdout;
            }
        }

        if (writeSvg)
            gResult.writeSvg(ofp, adjustPos);
        else if (writeCompletePath)
            gResult.writeCompletePath(ofp);
        else
            gResult.writePathData(ofp);

        if (ofp != stdout)
            fclose(ofp);
    }

    if (ifp != stdin)
    {
        fclose(ifp);
    }

    return res;
}
 
void usage(FILE *fp)
{
    fprintf(fp, "%s [-h] [-v] [-s [-a]] [-p] [-o outputFile] [file]\n"
                    "produces svg path from up/down/left/right/move\n"
                    "instructions, combined with pen up/down commands\n"
                    "defaults to writing path data to stdout\n\n"
                    "options:\n"
                    "-s\n"
                    "    svg. Write complete svg to stdout.\n"
                    "-p\n"
                    "    path. Write complete path to stdout.\n"
                    "-o\n"
                    "    output file. Write result to output.\n"
                    "-a\n"
                    "    adjust. Ensure path is inside svg first quadrant.\n"
                    "-v\n"
                    "    version. Writes version and exits.\n"
                    "-h\n"
                    "    help. Writes usage text and exits.\n",
                    progname);
}
