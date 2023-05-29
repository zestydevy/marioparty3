#include "math.h"

void HuVecCross(HuVec3F * out, HuVec3F * a, HuVec3F * b)
{
    f32 vector1Y = a->y;
    f32 vector2Z = b->z;
    f32 vector1Z = a->z;
    f32 vector2Y = b->y;
    f32 vector2X = b->x;
    f32 vector1X = a->x;

    out->x = (vector1Y * vector2Z) - (vector1Z * vector2Y);
    out->y = (vector1Z * vector2X) - (vector1X * vector2Z);
    out->z = (vector1X * vector2Y) - (vector1Y * vector2X);
}
