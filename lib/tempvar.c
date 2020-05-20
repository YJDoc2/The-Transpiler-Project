#include "tempvar.h"

static int __num = 0;

char* __name = "__temp%d";

char* get_temp_var() {
  char* ret = strdup(__name);
  sprintf(ret, ret, __num);
  ++__num;
  return ret;
}