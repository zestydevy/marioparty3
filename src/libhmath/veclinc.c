#include "common.h"
#include "math.h"

void HuVecLinearComb(Vec * out, f32 scale, Vec * a, f32 arg3, Vec * b)
{
    float x = (scale * a->x) + (arg3 * b->x);
    float y = (scale * a->y) + (arg3 * b->y);
    float z = (scale * a->z) + (arg3 * b->z);

    out->x = x;
    out->y = y;
    out->z = z;
}

void HuVecLinearComb2D(Vec * out, Vec * scale, Vec * a, Vec * b)
{
    f32 scaleX;
    f32 scaleY;
    f32 x;
    f32 y;
    f32 z;

    scaleX = scale->x;
    scaleY = scale->y;

    x = (scaleX * a->x) + (scaleY * b->x);
    y = (scaleX * a->y) + (scaleY * b->y);
    z = (scaleX * a->z) + (scaleY * b->z);

    out->x = x;
    out->y = y;
    out->z = z;
}
