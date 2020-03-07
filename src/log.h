#ifndef _VEO_LOG_HPP_
#define _VEO_LOG_HPP_
#include <stdarg.h>
#include "veo_debug.h"

#define VEO_ERROR(fmt, ...) eprintf("VEO_ERROR " fmt "\n", ## __VA_ARGS__)
#define VEO_DEBUG(fmt, ...) dprintf("[VH DEBUG] " fmt "\n", ## __VA_ARGS__)
#define VEO_TRACE(fmt, ...) dprintf("[VH TRACE] " fmt "\n", ## __VA_ARGS__)

#define VEO_ASSERT(_cond) do { \
  if (!(_cond)) { \
    fprintf(stderr, "%s %d: Assertion failure: %s\n", \
              __FILE__, __LINE__, #_cond); \
    VEO_ERROR("%s %d: Assertion failure: %s", \
              __FILE__, __LINE__, #_cond); \
    abort(); \
  } \
} while (0)

#endif
