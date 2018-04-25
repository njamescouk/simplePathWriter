yacc.exe -ldv simplePathWriter.y 
sed.exe "/extern char \*getenv();/d" y.tab.c > junk 
del y.tab.c 
move junk y.tab.c  
flex.exe -olex.yy.c simplePathWriter.l 

set COMPILE_CPP_SRCS=SimpleCommand.cpp SimpleLength.cpp SimplePathWriter.cpp dependencies\parseCmdline\source\lex.pcl.c dependencies\parseCmdline\source\pcl.tab.c dependencies\split_string\split_string.cpp lex.yy.c simpleGlobals.cpp simpleMain.cpp y.tab.c
set COMPILE_INCLUDES=-Idependencies\yacc -Idependencies\parseCmdline\source -Idependencies\split_string
g++ -o simplePathWriter.exe %COMPILE_INCLUDES% %COMPILE_DEFINES% -x c++ %COMPILE_CPP_SRCS% 
