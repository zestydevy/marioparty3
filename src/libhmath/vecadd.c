#include "common.h"
#include "math.h"

void HuVecAdd(HuVec3F * out, HuVec3F * a, HuVec3F * b)
{
    float x = a->x + b->x;
    float y = a->y + b->y;
    float z = a->z + b->z;

    out->x = x;
    out->y = y;
    out->z = z;
}

