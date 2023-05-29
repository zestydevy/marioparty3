#ifndef _MATH_H_
#define _MATH_H_

#include "PR/ultratypes.h"

#define M_PI 3.14159265358979323846

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} HuVec3F;

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

void HuVecCopyXYZ(HuVec3F * out, f32 x, f32 y, f32 z);
void HuVecCopy3F(HuVec3F * out, HuVec3F * a);
f32 HuVecGetLengthSqr3F(HuVec3F * vec);
f32 HuVecGetLength3F(HuVec3F * vec);

#endif
