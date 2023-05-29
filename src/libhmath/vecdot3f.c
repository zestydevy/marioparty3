#include "math.h"

f32 HuVecDot3F(HuVec3F * a, HuVec3F * b)
{
    return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}
