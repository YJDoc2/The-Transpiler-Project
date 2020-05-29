#include "expressions.h"

#include <stdlib.h>
#include <string.h>

extern char *type_arr;

char *join(char *start, char *middle, char *end) {
  void *_t = calloc(1, strlen(start) + strlen(middle) + strlen(end));
  strcat(_t, start);
  strcat(_t, middle);
  strcat(_t, end);
  return (char *)_t;
}

int verify_types(type combining_with, type combining_type) {
  if (combining_type == VOID_TYPE || combining_with == VOID_TYPE) return 1;

  if (combining_with == STRING_TYPE) {
    if (combining_type != STRING_TYPE) return 1;
  }
  if (combining_with == FLOAT_TYPE || combining_with == DOUBLE_TYPE) {
    if (combining_type == BOOL_TYPE || combining_type == STRING_TYPE ||
        combining_type == COMPLEX_TYPE) {
      return 1;
    }
  }

  if (combining_with == INT_TYPE || combining_with == SHORT_TYPE ||
      combining_with == LONG_TYPE) {
    if (!(combining_type == INT_TYPE || combining_type == SHORT_TYPE ||
          combining_type == LONG_TYPE)) {
      return 1;
    }
  }

  if (combining_with == BOOL_TYPE)
    if (combining_type != BOOL_TYPE) return 1;

  if (combining_with == COMPLEX_TYPE)
    if (combining_type == BOOL_TYPE) return 1;

  return 0;
}