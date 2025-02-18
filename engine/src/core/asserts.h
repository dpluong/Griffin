#pragma once

#include "defines.h"

// Disable assertions by commenting out the below line.
#define GASSERTIONS_ENABLED

#ifdef GASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

GAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define GASSERT(expr)                                                \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define GASSERT_MSG(expr, message)                                        \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define GASSERT_DEBUG(expr)                                          \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define GASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define GASSERT(expr)               // Does nothing at all
#define GASSERT_MSG(expr, message)  // Does nothing at all
#define GASSERT_DEBUG(expr)         // Does nothing at all
#endif
