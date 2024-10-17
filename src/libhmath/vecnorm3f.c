#include "common.h"
#include "math.h"

// https://decomp.me/scratch/6UMIQ
// the original output has the function prologue near the end rather than the start
#ifdef NONMATCHING
void _HuVecNormalize3F(Vec * vec)
{
    f32 x;
    f32 y;
    f32 z;
    f32 invMag;

    x = vec->x;
    y = vec->y;
    z = vec->z;
    invMag = 1.0f / HuSqrtf((x * x) + (y * y) + (z * z));

    vec->x = invMag * x;
    vec->y = invMag * y;
    vec->z = invMag * z;
}
#else
INCLUDE_ASM(void, "libhmath/vecnorm3f", HuVecNormalize3F, Vec * vec);
#endif