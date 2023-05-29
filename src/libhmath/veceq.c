#include "common.h"
#include "math.h"

s32 HuVecIsEqual(HuVec3F * a, HuVec3F * b) {
    if ((a->x == b->x) && (a->y == b->y) && (a->z == b->z)) {
        return TRUE;
    } 
    return FALSE;
}
