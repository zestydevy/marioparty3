#include "common.h"
#include "math.h"

void HuVecSubtract(Vec * dest, Vec * a, Vec * b) {


    float x = a->x - b->x;
    float y = a->y - b->y;
    float z = a->z - b->z;

    dest->x = x;
    dest->y = y;
    dest->z = z;
}
