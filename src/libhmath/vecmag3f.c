#include "common.h"
#include "math.h"

float HuVecGetLength3F(Vec * vec)
{
    return HuSqrtf(HuVecGetLengthSqr3F(vec));
}
