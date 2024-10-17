#include "math.h"

f32 HuVecDot3F(Vec * a, Vec * b)
{
    return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}
