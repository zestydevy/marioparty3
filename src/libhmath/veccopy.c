#include "common.h"
#include "math.h"

void HuVecCopyXYZ(HuVec3F * out, f32 x, f32 y, f32 z)
{
    out->x = x;
    out->y = y;
    out->z = z;
}

void HuVecCopy3F(HuVec3F * out, HuVec3F * a)
{
    *out = *a;
}

