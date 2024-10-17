#include "common.h"
#include "math.h"

void HuVecAdd(Vec * out, Vec * a, Vec * b)
{
    float x = a->x + b->x;
    float y = a->y + b->y;
    float z = a->z + b->z;

    out->x = x;
    out->y = y;
    out->z = z;
}

