#include "common.h"
#include "common_structs.h"
#include <PR/gbi.h>

#define ASPECT_RATIO (4.0f / 3.0f)
#define SCREEN_WIDTH 320.0f
#define SCREEN_HEIGHT 240.0f
#define SCREEN_WIDTH_CENTER SCREEN_WIDTH / 2.0f
#define SCREEN_HEIGHT_CENTER SCREEN_HEIGHT / 2.0f

void guLookAt(Mtx *m,
   float xEye, float yEye, float zEye,
   float xAt,  float yAt,  float zAt,
   float xUp,  float yUp,  float zUp );

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} HuVec4F;

typedef struct
{
    Mtx perspMtx;
    Mtx lookAtMtx;
} HuCamMtxs;

typedef struct {
    /* 0x000 */ u16 perspNorm;
    /* 0x002 */ char pad2[2];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00C */ f32 unkC;
    /* 0x010 */ HuVec3F pos;
    /* 0x01C */ HuVec3F at;
    /* 0x028 */ HuVec3F up;
    /* 0x034 */ HuVec3F screenScale;
    /* 0x040 */ HuVec3F screenPos;
    /* 0x04C */ s32 unk4C;
    /* 0x050 */ f32 fov;
    /* 0x054 */ f32 near;
    /* 0x058 */ f32 far;
    /* 0x05C */ f32 unk5C;
    /* 0x060 */ Vp viewports[3];
    /* 0x090 */ f32 screenLeft;
    /* 0x094 */ f32 screenTop;
    /* 0x098 */ f32 screenRight;
    /* 0x09C */ f32 screenBottom;
    /* 0x0A0 */ s32 unkA0;
    /* 0x0A4 */ s32 unkA4;
    /* 0x0A8 */ s32 unkA8;
    /* 0x0AC */ s32 unkAC;
    /* 0x0B0 */ HuCamMtxs mtxs[3];
} HuCamera;              

extern HuCamera* gCameraList;
typedef f32 HuMtx4F[4][4];

f32 HuMathCos(f32);
f32 HuMathSin(f32);

void guLookAtF(f32 mf[4][4], f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);

INCLUDE_ASM(s32, "camera", Hu3DCamInit);

extern u8 D_800D2008;
extern s16 D_800D418E;

void func_800123F4_12FF4(void)
{
    D_800D418E = D_800D2008;
}


void Hu3DCamSetPositionOrientation(s16 camIndex, HuVec3F * pos, HuVec3F * at, HuVec3F * up)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->pos = *pos;
    camera->at  = *at;
    camera->up  = *up;
}

void Hu3DCamSetPerspective(s16 camIndex, f32 fov, f32 near, f32 far)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->fov = fov;
    camera->near = near;
    camera->far = far;
    camera->perspNorm = 1;
}

void func_800124BC_130BC(s16 camIndex, HuVec4F * arg1)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->screenLeft = arg1->x;
    camera->screenTop = arg1->y;
    camera->screenRight = arg1->z;
    camera->screenBottom = arg1->w;
}

void func_80012508_13108(s16 camIndex, HuVec3F * arg1, HuVec3F * arg2)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->screenScale = *arg1;
    camera->screenPos = *arg2;
}

void Hu3DCamUpdateMtx(s16 camIndex)
{
    HuCamera * camera;
    HuCamMtxs * mtxs;

    camera = &gCameraList[camIndex];
    mtxs = &camera->mtxs[D_800D418E];

    guPerspective(&mtxs->perspMtx, &camera->perspNorm, camera->fov, (SCREEN_WIDTH / SCREEN_HEIGHT), camera->near, camera->far, 1.0f);
    guLookAt(&mtxs->lookAtMtx, camera->pos.x, camera->pos.y, camera->pos.z, camera->at.x, camera->at.y, camera->at.z, camera->up.x, camera->up.y, camera->up.z);
}

void func_80012640_13240(s16 camIndex, Gfx ** dispList)
{
    HuCamMtxs * camMtx;
    HuCamera * camera;

    camera = &gCameraList[camIndex];
    camMtx = &camera->mtxs[D_800D418E];
    camera->viewports[D_800D418E].vp.vscale[0] = (s16) camera->screenScale.x;
    camera->viewports[D_800D418E].vp.vscale[1] = (s16) camera->screenScale.y;
    camera->viewports[D_800D418E].vp.vscale[2] = (s16) camera->screenScale.z;
    camera->viewports[D_800D418E].vp.vtrans[0] = (s16) camera->screenPos.x;
    camera->viewports[D_800D418E].vp.vtrans[1] = (s16) camera->screenPos.y;
    camera->viewports[D_800D418E].vp.vtrans[2] = (s16) camera->screenPos.z;

    gSPViewport((*dispList)++, &camera->viewports[D_800D418E].vp);
    gSPPerspNormalize((*dispList)++, camera->perspNorm);
    gSPMatrix((*dispList)++, osVirtualToPhysical(&camMtx->perspMtx), G_MTX_PROJECTION | G_MTX_LOAD);
    gSPMatrix((*dispList)++, OS_PHYSICAL_TO_K0(&camMtx->lookAtMtx), G_MTX_LOAD);
}

void func_800127C4_133C4(s16 camIndex, Gfx ** dispList) {
    HuCamera * camera = &gCameraList[camIndex];
    gDPSetScissor((*dispList)++, G_SC_NON_INTERLACE, camera->screenLeft, camera->screenTop, camera->screenRight, camera->screenBottom);
}

void func_80012888_13488(s16 camIndex, s32 arg1, s32 arg2)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->unkA0 = arg1;
    camera->unkA4 = arg2;
}

void func_800128BC_134BC(s16 camIndex, s32 arg1)
{
    gCameraList[camIndex].unkA8 = arg1;
}


void func_800128EC_134EC(s16 camIndex, s32 arg1)
{
    gCameraList[camIndex].unkAC = arg1;
}


void Hu3DCam3DToScreen(s16 camIndex, HuVec3F * worldPos, HuVec3F * outPos) 
{
    f32 x;
    f32 y;
    f32 z;
    f32 projectedX;
    f32 projectedY;
    f32 projectedZ;
    HuCamera * camera;
    HuMtx4F viewMtx;
    
    camera = &gCameraList[camIndex];
    guLookAtF(
        viewMtx, 
        camera->pos.x, 
        camera->pos.y, 
        camera->pos.z, 
        camera->at.x, 
        camera->at.y, 
        camera->at.z, 
        camera->up.x, 
        camera->up.y, 
        camera->up.z
    );

    x = worldPos->x;
    y = worldPos->y;
    z = worldPos->z;
    x -= camera->pos.x;
    y -= camera->pos.y;
    z -= camera->pos.z;
    projectedX = ((x * viewMtx[0][0]) + (y * viewMtx[1][0])) + (z * viewMtx[2][0]);
    projectedY = ((x * viewMtx[0][1]) + (y * viewMtx[1][1])) + (z * viewMtx[2][1]);
    projectedZ = ((x * viewMtx[0][2]) + (y * viewMtx[1][2])) + (z * viewMtx[2][2]);
    x = HuMathSin(camera->fov / 2.0f) / HuMathCos(camera->fov / 2.0f) * projectedZ * ASPECT_RATIO;
    y =  (HuMathSin(camera->fov / 2.0f) / HuMathCos(camera->fov / 2.0f)) * projectedZ;
    outPos->x = (projectedX * (SCREEN_WIDTH_CENTER / (-x))) + SCREEN_WIDTH_CENTER;
    outPos->y = ((projectedY * (SCREEN_HEIGHT_CENTER / y)) + SCREEN_HEIGHT_CENTER);
}

void func_80012B14_13714(s16 camIndex, HuVec3F * worldPos, HuVec3F * outPos) 
{
    f32 x;
    f32 y;
    f32 z;
    f32 projectedX;
    f32 projectedY;
    f32 projectedZ;
    HuCamera * camera;
    HuMtx4F viewMtx;
    f32 f2;
    f32 f4;
    
    camera = &gCameraList[camIndex];
    guLookAtF(
        viewMtx, 
        camera->pos.x, 
        camera->pos.y, 
        camera->pos.z, 
        camera->at.x, 
        camera->at.y, 
        camera->at.z, 
        camera->up.x, 
        camera->up.y, 
        camera->up.z
    );

    x = worldPos->x;
    y = worldPos->y;
    z = worldPos->z;
    x -= camera->pos.x;
    y -= camera->pos.y;
    z -= camera->pos.z;
    projectedX = ((x * viewMtx[0][0]) + (y * viewMtx[1][0])) + (z * viewMtx[2][0]);
    projectedY = ((x * viewMtx[0][1]) + (y * viewMtx[1][1])) + (z * viewMtx[2][1]);
    projectedZ = ((x * viewMtx[0][2]) + (y * viewMtx[1][2])) + (z * viewMtx[2][2]);
    x = HuMathSin(camera->fov / 2.0f) / HuMathCos(camera->fov / 2.0f) * projectedZ * (camera->screenScale.x / camera->screenScale.y);
    y =  (HuMathSin(camera->fov / 2.0f) / HuMathCos(camera->fov / 2.0f)) * projectedZ;
    f2 = camera->screenPos.x / 4.0f;
    outPos->x = (projectedX * (f2 / (-x))) + f2;
    f4 = camera->screenPos.y / 4.0f;
    outPos->y = ((projectedY * (f4 / y)) + f4);
}

INCLUDE_ASM(s32, "camera", func_80012D0C_1390C);

INCLUDE_ASM(s32, "camera", func_80012E54_13A54);

INCLUDE_ASM(s32, "camera", func_80013320_13F20);

INCLUDE_ASM(s32, "camera", func_80013350_13F50);
