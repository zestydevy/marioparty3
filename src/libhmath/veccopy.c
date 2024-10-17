#include "common.h"
#include "math.h"

void HuVecCopyXYZ(Vec * out, f32 x, f32 y, f32 z)
{
    out->x = x;
    out->y = y;
    out->z = z;
}

void HuVecCopy3F(Vec * out, Vec * a)
{
    *out = *a;
}

