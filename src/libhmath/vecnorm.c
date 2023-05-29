#include "common.h"
#include "math.h"

void HuVecNormalize(f32 * x, f32 * y, f32 * z)
{
    f32 oldX;
    f32 oldY;
    f32 oldZ;
    f32 invMag;

    oldX = *x;
    oldY = *y;
    oldZ = *z;
    invMag = 1.0f / HuSqrtf((oldX * oldX) + (oldY * oldY) + (oldZ * oldZ));

    *x *= invMag;
    *y *= invMag;
    *z *= invMag;
}