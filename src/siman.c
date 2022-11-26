#include "common.h"
#include "process.h"

#include "siman.h"


// TODO: find SI thread stack size
void func_80051750_52350(void) {
    D_800BD7B0 = 0;
    D_800BD7B4 = 0;
    osCreateMesgQueue(&D_800CE1A0, &D_800BCD00, 32);
    osSetEventMesg(OS_EVENT_SI, &D_800CE1A0, (OSMesg)32);
    osCreateMesgQueue(&D_800D1220, &D_800BCD80, 32);
    osCreateThread(&D_800BCE00, 0x14, func_80051A44_52644, NULL, &D_800BD7B0, HOS_PRIORITY_SIMGR);
    osStartThread(&D_800BCE00);
}


functionListEntry ** func_800517F4_523F4(functionListEntry * entry) {
    switch (entry->type) {
    case 0:
        return &D_800BD7B0;
    case 1:
        return &D_800BD7B4;
    default:
        return NULL;
    }
}


/* Function Linked List Insertion */
s32 func_8005182C_5242C(functionListEntry* node) {
    functionListEntry* pYoungest;
    functionListEntry* child;

    // Add node as youngest child of a linked list
    pYoungest = (functionListEntry*) func_800517F4_523F4(node);
    child = pYoungest->child;
    if (child != NULL) {
        pYoungest = child;
        if (pYoungest->child != NULL) {
            do {
                pYoungest = pYoungest->child;
            } while (pYoungest->child != NULL);
        }
    }
    pYoungest->child = node;
    node->child = NULL;
    return 0;
}


void func_8005188C_5248C(functionListEntry * entry, s16 type, void * func) {
    OSMesg msgBuffer;
    OSMesgQueue mq;
    unkMesg msgOut;

    msgOut.pFunc = &func_8005182C_5242C;
    msgOut.pFuncListEntry = entry;
    msgOut.recvQueue = &mq;
    entry->pFunc = func;
    entry->type = type;

    osCreateMesgQueue(&mq, &msgBuffer, OS_MESG_BLOCK);
    osSendMesg(&D_800D1220, &msgOut, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, 1);
}


/* Function Linked List Deletion */
s32 func_800518FC_524FC(functionListEntry* arg0) {
    functionListEntry* var_v0;
    functionListEntry* var_v1;
    functionListEntry** root;

    root = func_800517F4_523F4(arg0);
    var_v0 = *root;
    var_v1 = NULL;
    // Search until the end of the list
    while (var_v0 != NULL) {
        // Check if the node is the one we're looking for
        if (var_v0 == arg0) {
            // If this wasn't at the start of the list (previous node is nonnull), remove it from the list
            if (var_v1 != NULL) {
                var_v1->child = arg0->child;
            } else {
                // Otherwise set the root of the list to the next node
                *root = arg0->child;
            }
            return 0;
        }
        var_v1 = var_v0;        
        var_v0 = var_v0->child;
    }
    return 0;
}


void func_80051968_52568(functionListEntry *entry) {
    OSMesg msgBuffer;
    OSMesgQueue mq;
    unkMesg msgOut;

    msgOut.pFunc = &func_800518FC_524FC;
    msgOut.pFuncListEntry = entry;
    msgOut.recvQueue = &mq;
    
    osCreateMesgQueue(&mq, &msgBuffer, 1);
    osSendMesg(&D_800D1220, &msgOut, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}


/* Do all functions in functionList of type "type" */
void func_800519D0_525D0(s16 type) {
    functionListEntry* funcList;

    funcList = 0;
    switch (type) {
    case 0:
        funcList = D_800BD7B0;
        break;
    case 1:
        funcList = D_800BD7B4;
        break;
    }
    if (funcList != 0) {
        do {
            funcList->pFunc();
            funcList = funcList->child;
        } while (funcList != 0);
    }
}


/* Wait for message to do all functions in a global function list
 * or to run custom functions?
 */
void func_80051A44_52644(void* arg0) {
    unkMesgWrapper msgWrapper;

    func_800511C4_51DC4(&msgWrapper, &D_800D1220, 3);

    while (1) {
        osRecvMesg(&D_800D1220, (OSMesg*) &msgWrapper.unkMsg, OS_MESG_BLOCK);       
        switch ((s32) msgWrapper.unkMsg) {
            case 1:
                func_800519D0_525D0((s16) 0);
                break;
            case 2:
                func_800519D0_525D0((s16) 1);
                break;
            default:
            {
                unkMesg* recvdMsg;
                recvdMsg = msgWrapper.unkMsg;
                recvdMsg->ret = recvdMsg->pFunc(recvdMsg->pFuncListEntry);
                if (recvdMsg->recvQueue != NULL) {
                    osSendMesg(recvdMsg->recvQueue, NULL, OS_MESG_BLOCK);
                }
            }
        }
    }
}


s32 func_80051B0C_5270C(unkMesg* pUnkMsg, void* func, functionListEntry* entry, s32 type) {
    OSMesgQueue msgQueue;
    OSMesg tmpMsg;

    pUnkMsg->pFunc = func;
    pUnkMsg->pFuncListEntry = entry;
    pUnkMsg->recvQueue = &msgQueue;
    osCreateMesgQueue(&msgQueue, &tmpMsg, 1);
    osSendMesg(&D_800D1220, pUnkMsg, OS_MESG_BLOCK);
    switch (type) {
    case 0:
        pUnkMsg->ret = 0;
        break;
    case 1:
        osRecvMesg(&msgQueue, NULL, OS_MESG_BLOCK);
        break;
    case 2:
        while (osRecvMesg(&msgQueue, NULL, OS_MESG_NOBLOCK)) {
            HuPrcVSleep();
        }
        break;
    }
    return pUnkMsg->ret;
}
