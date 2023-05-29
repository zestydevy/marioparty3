#include "common.h"
#include "math.h"

void HuVecAddScaled(HuVec3F * out, HuVec3F * a, f32 scalar, HuVec3F * b)
{
    float x = a->x + (scalar * b->x);
    float y = a->y + (scalar * b->y);
    float z = a->z + (scalar * b->z);

    out->x = x;
    out->y = y;
    out->z = z;
}

