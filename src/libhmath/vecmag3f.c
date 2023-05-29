#include "common.h"
#include "math.h"

float HuVecGetLength3F(HuVec3F * vec)
{
    return HuSqrtf(HuVecGetLengthSqr3F(vec));
}
