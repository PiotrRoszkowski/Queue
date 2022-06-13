//
// Created by proszkowski on 25.05.2022.
//

#include <stdlib.h>
#include "queue.h"
#include "queue_example1Port.h"

//static Queue_t _example1QueCtrlMem;
//static Queue _example1Que = NULL;
//static uint8_t _example1QueElMem[EXAMPLE1_QUE_LEN];
#define QUEUE_STATIC_ALLOCATION(name,elSize, elAmount) \
    static Queue_t _##name##QueCtrlMem; \
    static Queue _##name##Que = NULL; \
    static uint8_t _##name##QueElMem[elSize*elAmount];

QUEUE_STATIC_ALLOCATION(example1, 1, 200)

//bool Queue_example1TxPort_Create(void){
//    _example1Que = Queue_Create(1, EXAMPLE1_QUE_LEN, _example1QueElMem, &_example1QueCtrlMem);
//    if (_example1Que == NULL){
//        return false;
//    }
//    return true;
//}

#define QUEUE_STATIC_CREATE_PORT(portName, elSize, elAmount) \
bool Queue_##portName##TxPort_Create(void){ \
    _##portName##Que = Queue_Create(1, elSize*elAmount, _##portName##QueElMem, &_##portName##QueCtrlMem); \
    if (_##portName##Que == NULL){ \
        return false; \
    } \
    return true; \
}

QUEUE_STATIC_CREATE_PORT(example1, 1, 200)

bool Queue_example1TxPort_Put(const void* elPtr){
    if(Queue_Put(_example1Que, elPtr) == Que_OK){
        return true;
    }
    return false;
}

bool Queue_example1TxPort_Get(void* elPtr){
    if(Queue_Get(_example1Que, elPtr) == Que_OK){
        return true;
    }
    return false;
}

uint16_t Queue_example1TxPortGetMaxDepth(void){
    return Queue_GetMaxDepth(_example1Que);
}