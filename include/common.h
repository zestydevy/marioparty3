#ifndef _COMMON_H_
#define _COMMON_H_

#define IS_DEBUG_PANIC(statement, file, line) do {} while(1)
#define ASSERT(condition) \
    if (!(condition)) { \
        IS_DEBUG_PANIC("Assertion failed: " #condition, __FILE__, __LINE__); \
    }

#include "libultra.h"
#include "include_asm.h"
#include "variables.h"
#include "functions.h"
#include "macros.h"
#endif
