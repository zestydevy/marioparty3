#include "common.h"
#include "math.h"

void HuVecMulScalar(HuVec3F * out, f32 scalar, HuVec3F * a)
{
    float x = scalar * a->x;
    float y = scalar * a->y;
    float z = scalar * a->z;

    out->x = x;
    out->y = y;
    out->z = z;
}
