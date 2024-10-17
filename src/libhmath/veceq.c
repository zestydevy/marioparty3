#include "common.h"
#include "math.h"

s32 HuVecIsEqual(Vec * a, Vec * b) {
    if ((a->x == b->x) && (a->y == b->y) && (a->z == b->z)) {
        return TRUE;
    } 
    return FALSE;
}
