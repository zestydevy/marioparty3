#include "common.h"
#include "common_structs.h"
#include "obj.h"
#include "malloc.h"
#include "process.h"

extern f32 D_800CB890;
extern s16 D_800CC430;
extern s16 D_800CCF50;
extern s16 D_800CCF8C;
extern f32 D_800CCF98[];
extern s16 D_800CD050;
extern HuObjUnk1 D_800CD1E0[];
extern s32 D_800D2118;
extern f32 D_800D4198[];
extern f32 D_800D5210;
extern s16 D_800D530C;
extern s16 D_800D5560;
extern s32 D_800D6A40;
extern s8 D_800D6A90;
extern s16 D_800D6B40;

void func_80048054_48C54();                         /* extern */
extern HuObjInfo * D_800A1770_A2370;
extern s16 D_800A1774_A2374;        // process count
extern s16 D_800A1776_A2376;
extern s16 D_800A1778_A2378;        // dtor index?
extern HuObjUnk0 * D_800A177C_A237C;

void HuObjInit(s32 numOfObjs, s32 numOfPrcs)
{
    s16 prcCount;
    s32 i;
    HuObjInfo * obj;
    HuObjUnk0 * prcInfo;

    D_800CCF50 = numOfObjs + 1;
    D_800CCF8C = 0;
    D_800D6B40 = 0;
    D_800CC430 = -1;
    D_800D5560 = -1;
    D_800D2118 = 0;
    D_800D530C = 0;
    D_800D6A90 = 0;
    
    if (D_800A1770_A2370 != NULL) {
        HuMemMemoryFreeTemp((void *)D_800A1770_A2370);
    }
    
    D_800A1770_A2370 = (HuObjInfo *)HuMemMemoryAllocTemp(D_800CCF50 * sizeof(HuObjInfo));
    
    for (i = 0; i < D_800CCF50; ++i)
    {
        obj = &D_800A1770_A2370[i];
        obj->unk0 = 1;
        obj->unk8 = -1;
        obj->unk6 = -1;
        obj->unk4 = -1;
        obj->unk10 = 0;
        obj->unk24.x =
        obj->unk24.y =
        obj->unk24.z = 0.0f;
        obj->unk18.x =
        obj->unk18.y =
        obj->unk18.z = 0.0f;
        obj->unk30.x =
        obj->unk30.y =
        obj->unk30.z = 1.0f;
        obj->unk48 = 0;
        obj->unk40 = 0;
        obj->unk5C = 0;
        obj->func = NULL;
        obj->unkA = i + 1;
        obj->unk44 = 0;
        obj->unk48 = 0;
    }
   
    for (i = 0; i < 10; ++i)
    {
        D_800CD1E0[i].unk2 = 0;
        D_800CD1E0[i].unk4 = 0;
        D_800CD1E0[i].unk0 = 0;
        D_800CD1E0[i].objs = NULL;
        D_800CD1E0[i].unk8 = 0;
    }
    
    prcCount = numOfPrcs + 2;
    D_800A1774_A2374 = prcCount;
    D_800A1776_A2376 = 0;
    D_800A1778_A2378 = 0;
    D_800A177C_A237C = (HuObjUnk0 *)HuMemMemoryAllocTemp(prcCount * sizeof(HuObjUnk0));
    
    for (i = 0; i < D_800A1774_A2374; ++i)
    {
        prcInfo = &D_800A177C_A237C[i];
        prcInfo->unk0 = 1;
        prcInfo->unk2 = i + 1;
        prcInfo->prc = NULL;
        prcInfo->unk8 = 0;
    }
    
    D_800D5210 = 20000.0f;
    D_800CB890 = 10000.0f;
    
    for (i = 0; i < 4; ++i) {
        D_800CCF98[i] = 20000.0f;
        D_800D4198[i] = 10000.0f;
    }
    
    D_800D6A40 = 0;
    D_800CD050 = 0x5A;
    
}

// clean up?
INCLUDE_ASM(s32, "unknown/47d60", func_80047420_48020);

HuObjInfo * HuObjCreate(s16 priority, u16 arg1, u16 arg2, s16 arg3, HuObjFunc func)
{
    HuObjInfo * temp_s0;
    s16* temp_v1;
    s32 temp_s1;
    s32 var_a0;
    s32 var_a0_2;

    if (D_800CCF8C == D_800CCF50) {
        return NULL;
    }
    
    temp_s0 = &D_800A1770_A2370[D_800D6B40];
    temp_s0->unk2 = D_800D6B40;
    temp_s0->unk4 = priority;
    
    HuObjRegister(temp_s0);
    
    if (arg1 != 0) {
        temp_s0->unk40 = HuMemMemoryAllocTemp(arg1 * sizeof(u16));
        temp_s0->unk3C = arg1;
        for (var_a0 = 0; var_a0 < arg1; ++var_a0) {
            temp_s0->unk40[var_a0] = -1;
        }
    } else {
        temp_s0->unk40 = NULL;
        temp_s0->unk3C = 0;
    }

    if (arg2 != 0) {
        temp_s0->unk48 = HuMemMemoryAllocTemp(arg2 * sizeof(u16));
        temp_s0->unk44 = arg2;
    } else {
        temp_s0->unk48 = NULL;
        temp_s0->unk44 = 0;
    }
    
    if (arg3 >= 0) {
        func_80047CDC_488DC(arg3, temp_s0);
    } else {
        temp_s0->unkC = arg3;
        temp_s0->unkE = 0;
    }

    temp_s0->unk0 = 4;
    temp_s0->unk10 = 0;
    temp_s0->func = func;
    temp_s0->unk58 = 0;
    temp_s0->unk54 = 0;
    temp_s0->unk50 = 0;
    temp_s0->unk4C = 0;
    D_800D6B40 = temp_s0->unkA;
    ++D_800CCF8C;
    
    return temp_s0;
}

void func_800477A4_483A4(HuObjInfo * arg0, s16 arg1)
{
    s16 temp_a0;

    arg0->unk4 = arg1;
    
    if (D_800CC430 != D_800D5560)
    {
        temp_a0 = arg0->unk8;
        if (temp_a0 >= 0) {
            D_800A1770_A2370[temp_a0].unk6 = arg0->unk6;
        }

        if ((arg0->unk6 < 0) || (D_800A1770_A2370[arg0->unk6].unk8 = arg0->unk8, arg0->unk6 < 0)) {
            D_800D5560 = D_800A1770_A2370[arg0->unk8].unk2;
        }
        if (arg0->unk8 < 0) {
            D_800CC430 = D_800A1770_A2370[arg0->unk6].unk2;
        }
        
        HuObjRegister(arg0);
    }
}

// register object into linked list, sort based on priority
void HuObjRegister(HuObjInfo * obj)
{
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t1;
    s16 var_a2;
    HuObjInfo * temp_a3;
    s16 temp_t4;

    temp_t0 = obj->unk2;
    temp_t1 = obj->unk4;
    
    if (D_800D5560 == -1) {
        obj->unk6 = -1;
        obj->unk8 = -1;
        D_800D5560 = temp_t0;
        D_800CC430 = temp_t0;
    } else {
        var_a2 = D_800D5560;
        while (var_a2 != -1) {
            temp_a3 = &D_800A1770_A2370[var_a2];
            if (temp_a3->unk4 <= temp_t1) {
                break;
            }
            temp_t4 = var_a2;
            var_a2 = temp_a3->unk8;
        }
        if (var_a2 != -1) {
            obj->unk6 = temp_a3->unk6;
            obj->unk8 = var_a2;
            temp_a0 = temp_a3->unk6;
            if (temp_a0 != -1) {
                D_800A1770_A2370[temp_a0].unk8 = temp_t0;
            } else {
                D_800D5560 = temp_t0;
            }
            temp_a3->unk6 = temp_t0;
        } else {
            obj->unk8 = -1;
            obj->unk6 = temp_t4;
            temp_a3->unk8 = temp_t0;
            D_800CC430 = temp_t0;
        }
    }
}

INCLUDE_ASM(s32, "unknown/47d60", func_800479AC_485AC);

INCLUDE_ASM(s32, "unknown/47d60", func_80047B30_48730);

INCLUDE_ASM(s32, "unknown/47d60", func_80047B38_48738);

INCLUDE_ASM(s32, "unknown/47d60", func_80047B48_48748);

INCLUDE_ASM(s32, "unknown/47d60", func_80047B5C_4875C);

INCLUDE_ASM(s32, "unknown/47d60", func_80047B80_48780);

INCLUDE_ASM(s32, "unknown/47d60", func_80047BAC_487AC);

INCLUDE_ASM(s32, "unknown/47d60", func_80047BDC_487DC);

INCLUDE_ASM(s32, "unknown/47d60", func_80047BEC_487EC);

INCLUDE_ASM(s32, "unknown/47d60", func_80047BFC_487FC);

INCLUDE_ASM(s32, "unknown/47d60", func_80047C0C_4880C);

void func_80047CDC_488DC(u16 arg0, HuObjInfo * obj)
{
    HuObjUnk1 * temp_a2;

    temp_a2 = &D_800CD1E0[arg0];
    if (temp_a2->unk4 != temp_a2->unk2)
    {
        obj->unkC = arg0;
        obj->unkE = temp_a2->unk0;
        temp_a2->objs[temp_a2->unk0] = obj;
        temp_a2->unk0 = temp_a2->unk8[temp_a2->unk0];
        ++temp_a2->unk4;
    }
}

INCLUDE_ASM(s32, "unknown/47d60", func_80047D4C_4894C);

INCLUDE_ASM(s32, "unknown/47d60", func_80047DBC_489BC);

INCLUDE_ASM(s32, "unknown/47d60", func_80047DD4_489D4);

INCLUDE_ASM(s32, "unknown/47d60", func_80047DFC_489FC);

INCLUDE_ASM(s32, "unknown/47d60", func_80047E5C_48A5C);

INCLUDE_ASM(s32, "unknown/47d60", func_80047E90_48A90);

struct process * HuObjPrcCreate(process_func func, u16 priority, s32 stackSize, s32 extDataSize)
{
    s16 prevIdx;
    struct process * newPrc;
    HuObjUnk0 * temp_s0;

    if (D_800A1776_A2376 == D_800A1774_A2374) {
        return NULL;
    }

    prevIdx             = D_800A1778_A2378;
    temp_s0             = &D_800A177C_A237C[D_800A1778_A2378];
    temp_s0->unk0       = 4;
    D_800A1778_A2378    = temp_s0->unk2;

    newPrc = HuPrcCreate(func, priority, stackSize, extDataSize);
    
    temp_s0->prc        = newPrc;
    newPrc->dtor_idx    = prevIdx;
    HuPrcDtor(temp_s0->prc, func_80048054_48C54);

    temp_s0->unk8 = NULL;
    ++D_800A1776_A2376;
    
    return temp_s0->prc;
}

INCLUDE_ASM(s32, "unknown/47d60", func_80047F50_48B50);

INCLUDE_ASM(s32, "unknown/47d60", func_80048008_48C08);

void func_80048054_48C54(void)
{
    process_func func;
    struct process * currPrc;
    HuObjUnk0 * temp_s0;

    currPrc = HuPrcGetCurrent();
    temp_s0 = &D_800A177C_A237C[currPrc->dtor_idx];
    func = temp_s0->unk8;
    if (func != NULL) {
        func();
    }
    temp_s0->unk0 = 1;
    temp_s0->unk2 = D_800A1778_A2378;
    D_800A1778_A2378 = currPrc->dtor_idx;
    --D_800A1776_A2376;
}

INCLUDE_ASM(s32, "unknown/47d60", func_800480E4_48CE4);

INCLUDE_ASM(s32, "unknown/47d60", func_80048128_48D28);

INCLUDE_ASM(s32, "unknown/47d60", func_8004819C_48D9C);

INCLUDE_ASM(s32, "unknown/47d60", func_80048228_48E28);

INCLUDE_ASM(s32, "unknown/47d60", func_80048460_49060);

INCLUDE_ASM(s32, "unknown/47d60", func_8004849C_4909C);

INCLUDE_ASM(s32, "unknown/47d60", func_80048504_49104);

INCLUDE_ASM(s32, "unknown/47d60", func_80048E88_49A88);

INCLUDE_ASM(s32, "unknown/47d60", func_80048EE8_49AE8);

INCLUDE_ASM(s32, "unknown/47d60", func_800499B0_4A5B0);

INCLUDE_ASM(s32, "unknown/47d60", func_80049F98_4AB98);

INCLUDE_ASM(s32, "unknown/47d60", func_80049FB8_4ABB8);

INCLUDE_ASM(s32, "unknown/47d60", func_8004A0E0_4ACE0);

INCLUDE_ASM(s32, "unknown/47d60", func_8004A208_4AE08);

INCLUDE_ASM(s32, "unknown/47d60", func_8004A354_4AF54);

INCLUDE_ASM(s32, "unknown/47d60", func_8004A444_4B044);

INCLUDE_ASM(s32, "unknown/47d60", func_8004A468_4B068);

INCLUDE_ASM(s32, "unknown/47d60", func_8004A49C_4B09C);
