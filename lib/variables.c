#include "variables.h"

#include "parserfn.h"
char* type_arr[] = {
    "int", "float", "double", "bool", "float complex", "long", "short", "void",
};

char* mod_arr[] = {"", "const", "static"};

void decl_var(modifier m, type t, char* ident) {
  printcode("%s %s %s;\n", mod_arr[m], type_arr[t], ident);
}

void assg_decl_var(modifier m, type t, char* ident, char* val) {
  printcode("%s %s %s = %s;\n", mod_arr[m], type_arr[t], ident, val);
}