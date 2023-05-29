#include <PR/ultratypes.h>
#include "math.h"

f32 HuSqrtf(f32);
f32 HuVecGetLengthSqr(f32 arg0, f32 arg1, f32 arg2);
f32 HuVecGetLength(f32 arg0, f32 arg1, f32 arg2);

f32 HuVecGetLengthSqr(f32 arg0, f32 arg1, f32 arg2) {
    return (arg0 * arg0) + (arg1 * arg1) + (arg2 * arg2);
}

f32 mulHuVecGetLength(f32 arg0, f32 arg1, f32 arg2) {
    return HuSqrtf(HuVecGetLengthSqr(arg0, arg1, arg2));
}