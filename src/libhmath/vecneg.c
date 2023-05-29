#include "common.h"
#include "math.h"

void HuVecNeg(HuVec3F * out, HuVec3F * a) {

    float x = -a->x;
    float y = -a->y;
    float z = -a->z;

    out->x = x;
    out->y = y;
    out->z = z;
}

