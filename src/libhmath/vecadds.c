#include "common.h"
#include "math.h"

void HuVecAddScaled(Vec * out, Vec * a, f32 scalar, Vec * b)
{
    float x = a->x + (scalar * b->x);
    float y = a->y + (scalar * b->y);
    float z = a->z + (scalar * b->z);

    out->x = x;
    out->y = y;
    out->z = z;
}

