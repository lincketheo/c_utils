#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>

/**
 * Null unwrap with lambda expr.
 * Example:
 * int* a = unwrap(malloc(10 * sizeof*a), ({ return 1; }));
 *
 * is shorthand for:
 *
 * int *a = malloc(10 * sizeof*a);
 * if(a == NULL)
 *  return 1;
 */
#define unwrap(expr, fail_expr) \
  ({                            \
    if ((expr) == NULL)         \
      (fail_expr);              \
    expr;                       \
  })

#define malloc_err(arg, name, expr) ({                           \
  unwrap(malloc(arg), ({                                         \
    fprintf(stderr, "Failed to allocate memory for %s\n", name); \
    expr;                                                        \
  }));                                                           \
})

#define create_err(expr, name, fail_expr) ({        \
  unwrap((expr), ({                                 \
    fprintf(stderr, "Failed to create %s\n", name); \
    fail_expr;                                      \
  }));                                              \
})

/**
 * Returns the closest power of two less than [val]
 */
size_t floored_power_of_two(size_t val);

/**
 * Nice readable print only if verbose. So you don't have to do if(verbose) printf....
 */
void printf_if_verbose(int verbose, const char* format, ...);

/**
 * int Print Failed Verb to reduce boilerplate code
 * @brief Quick wrapper around error messaging for int return type
 */
int int_pfv(int p, const char* verb_phrase);

#endif
