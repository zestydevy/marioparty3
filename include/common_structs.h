#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "PR/ultratypes.h"

typedef struct Vec2f {
               f32 x;
               f32 y;
} Vec2f;
typedef struct Vec2s {
               s32 x;
               s32 y;
} Vec2s;
typedef struct Vec3f {
               f32 x;
               f32 y;
               f32 z;
} Vec3f;
typedef struct Vec3s {
               s32 x;
               s32 y;
               s32 z;
} Vec3s;
typedef struct Vec4f {
               f32 x;
               f32 y;
               f32 z;
               f32 yaw;
} Vec4f;

#endif
