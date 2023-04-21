#ifndef __PAD_H
#define __PAD_H

#include "common.h"
#include "siman.h"

#define PAD_NOT_INSERTED 0

typedef struct {
 OSContPad pad;
 s32 unk[4];
} HuPad;

extern s16 D_800ABF80;
extern s16 D_800ABF82;
extern s16 D_800ABF84;
extern u8 D_800ABF8A[];
extern u16 D_800CBB66[];
extern s8 D_800CBB6E[];
extern s16 D_800CDA7C[];
extern s16 D_800D056A[];
extern s16 D_800D1244[];
extern s16 D_800D1382[];
extern s16 gNumOfControllers;
extern s8 D_800D20A1[];
extern s16 D_800D5558[];

extern s16 D_800ABF9C;
extern OSMesgQueue D_800ABFA0;
extern void* D_800ABFB8;

extern functionListEntry D_800ABF90;

extern OSContPad D_800ABE40[8];

extern s8 D_800ABF8E;
extern s8 D_800ABF8F;

extern s8 D_800ABF86[];

s32 HuPadInit(u16 * channel);
s16 func_80008F3C_9B3C(s16 ch, s32 arg1);
s32 func_80008FD4_9BD4(s32 arg0);
void func_8000914C_9D4C(s8 arg0, s8 arg1);
s16 func_80009160_9D60(void);
void func_800097B8_A3B8(void);
void func_800097D4_A3D4(void);
void func_80009824_A424(void);
s32 HuGetPadInserted(s16 padNum);

#endif