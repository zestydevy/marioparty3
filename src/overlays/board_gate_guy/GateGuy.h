#include "common.h"
#include "process.h"
#include "common_structs.h"

typedef struct unkStruct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
} unkStruct;
typedef struct unkStruct01 {
    f32 unk_00;
    char unk_04[4];
    f32 unk_08;
} unkStruct01;

typedef struct unkStruct02 {
HuVec3F unk_00;
char unk_0C[4];
} unkStruct02;

struct heap_node
{
    s32 size;                   // 0000
    u8 heap_constant;           // 0004
    u8 used; // bool            // 0005
    struct heap_node *prev;     // 0008
    struct heap_node *next;     // 000C
};

typedef struct unkStruct03 {
char unk_00[0x18];
struct heap_node* unk_18;
char unk_1C[0x70];
unkStruct02* unk_8C;
} unkStruct03;

typedef struct unkStruct04 {
char unk_00[0x0C];
HuVec3F unk_0C;
} unkStruct04;

typedef struct unkStruct05 {
char unk_00[0x24];
s32 unk_24;
} unkStruct05;

typedef struct unkStruct06 {
    s32 unk_00;
    s32 unk_04;
    f32 unk_08;
    char unk_0C[4];
} unkStruct06;

typedef struct unkStruct07 {
    char unk_00[0x17];
    u8 unk_17;
} unkStruct07;

void func_800359E0_365E0(void*, s16);
extern s16 D_800A1764_A2364;

extern s8 gCurrentPlayerIndex;
extern Player gPlayers[4];
void func_80047B80_48780(Process**, s32);
void func_80047BAC_487AC(Process**, s32);
void func_80100CEC(u8);
extern s16 D_800CDD58;
extern s16 D_800D037C;
s32 func_800E1824(s32, s32, s32);
s32 func_800E88FC(void);
extern s16 D_800D51F8;
extern s32 D_80119470;
extern s32 D_80119474;
extern s32 D_80119478;
extern s32 D_8011947C;
void func_800E1854(s32);
extern s16 D_800D51F8;
extern s32 D_80119470;
extern s32 D_80119474;
extern s32 D_80119478;
extern s32 D_8011947C;
void HuObjInit(s32, s32);
void omOvlGotoEx(s32, s16, u16);
extern s8 D_800CD059;
s32 omOvlReturnEx(s16 level);
void func_800E94D0(void);
void func_800E9564(void);
void func_800E9B10(s32, s32);
void func_800E9D9C(void);
void func_800E9F4C(s32, s8*, s8*);
void func_800EA760(void);
void func_800ECD0C(s32, s8, s8);
f32 HuMathCos(f32);
f32 HuMathSin(f32);
f32 func_800D76D0(void*);
void func_800EB708(s32, s32, unkStruct01*);
void * HuMemMemoryAlloc(struct heap_node * heap, s32 size);
unkStruct03* func_80047EA0_48AA0(void*, s32, s32, s32);
void func_80105CC0_3D8DB0(void); //probably takes object as arg
void func_800FC8C4(void*);
extern s32 D_80105540;
void func_800EC1E4(void*, s32, void*, f32);
extern s32 D_80105540;
extern unkStruct D_800CD0B0;
void func_800EBF2C(void*, s32, void*);
void func_80106308_3D93F8(void);
void func_8001C258_1CE58(s16, s32, s32);
void func_8001C448_1D048(s16);
void func_8001C814_1D414(s16, s32, s32);
void func_8001C8E4_1D4E4(s16, s32);
void* func_800D8010(s32, s32);
void func_800D8944(void*);
void func_800D8F0C(void*);
void func_80089A20_8A620(HuVec3F*, s32);
void func_800D8E88(void);
s16 func_800F3750(void);
void* func_800F375C(s32);
void func_800F38DC(s32, s32, s32);
void func_80110068_3E3158(s32);
s16 func_800F3750(void);
void* func_800F375C(s32);
void func_800F38DC(s32, s32, s32);
void func_80110068_3E3158(s32);