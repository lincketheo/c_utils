#include <math.h>
#include <stdarg.h>
#include <stdio.h>

#include "utils/utils.h"

size_t floored_power_of_two(size_t val)
{
  float power = floorf(log2f((float)val));
  return (size_t)powf(2, power);
}

void printf_if_verbose(int verbose, const char* format, ...)
{
  if (verbose) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
  }
}
