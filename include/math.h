#ifndef _MATH_H_
#define _MATH_H_

#include "PR/ultratypes.h"

#define M_PI 3.14159265358979323846

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} HuVec3I;

// TODO: Where are these in libultra, if anywhere?
float sinf(float);
//double sin(double);
float cosf(float);
//double cos(double);

float sqrtf(float);
float HuSqrtf(float x);

void HuVecCopyXYZ(Vec * out, f32 x, f32 y, f32 z);
void HuVecCopy3F(Vec * out, Vec * a);
f32 HuVecGetLengthSqr3F(Vec * vec);
f32 HuVecGetLength3F(Vec * vec);

#endif
