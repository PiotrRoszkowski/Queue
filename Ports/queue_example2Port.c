//
// Created by proszkowski on 01.06.2022.
//

#include <stdlib.h>
#include "queue.h"
#include "queue_example2Port.h"

static Queue_t _example2TxQueCtrlMem;
static Queue _example2TxQue = NULL;
static uint8_t _example2TxQueElMem[EXAMPLE2_QUE_LEN];

bool Queue_example2TxPort_Create(void){
    _example2TxQue = Queue_Create(1, EXAMPLE2_QUE_LEN, _example2TxQueElMem, &_example2TxQueCtrlMem);
    if (_example2TxQue == NULL){
        return false;
    }
    return true;
}

bool Queue_example2TxPort_Put(const void* elPtr){
    if(Queue_Put(_example2TxQue, elPtr) == Que_OK){
        return true;
    }
    return false;
}

bool Queue_example2TxPort_Get(void* elPtr){
    if(Queue_Get(_example2TxQue, elPtr) == Que_OK){
        return true;
    }
    return false;
}