#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/str_utils.h"
#include "utils/utils.h"

char* str_plus(const char* front, const char* back)
{
  assert(front);
  assert(back);

  char* actual = malloc_err(strlen(front) + strlen(back) + 1, "str_plus", ({ return NULL; }));

  strcpy(actual, front);
  strcat(actual, back);

  return actual;
}
