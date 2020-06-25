#include "help.h"

const char* helpstr =
    "This is help for The Transpiler Project\n"
    "Expected format : ttp filename [-hkl] [-o outfile]\n"
    "Required argument is filename, the name of file which is to be parsed\n"
    "Optional Arguments :\n"
    "\th : help : prints help\n"
    "\tk : keep files : keeps generated files, even if there are any errors\n"
    "\tl : print line numbers : prints filename and line numbers of parsing "
    "files in generated files,\n\t\tso if any errors compiler can report as "
    "per the lines in original files. Maybe a bit off than exact line numbers\n"
    "\to outfile : name of the main output file : names the main output file "
    "as the given name, does not have any effect on name of class files "
    "generated\n\n";
