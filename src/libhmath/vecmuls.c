#include "common.h"
#include "math.h"

void HuVecMulScalar(Vec * out, f32 scalar, Vec * a)
{
    float x = scalar * a->x;
    float y = scalar * a->y;
    float z = scalar * a->z;

    out->x = x;
    out->y = y;
    out->z = z;
}
