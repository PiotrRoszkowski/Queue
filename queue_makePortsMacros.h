//
// Created by proszkowski on 13.06.2022.
//

#ifndef LOGGERDEMO_QUEUE_MAKEPORTSMACROS_H
#define LOGGERDEMO_QUEUE_MAKEPORTSMACROS_H

#include "queue.h"

#define QUEUE_STATIC_ALLOCATION(portName,elSize, elAmount) \
    static Queue_t _##portName##QueCtrlMem; \
    static Queue _##portName##Que = NULL; \
    static uint8_t _##portName##QueElMem[elSize*elAmount];


#define QUEUE_STATIC_CREATE_PORT_HEADER(portName) \
    bool Queue_##portName##TxPort_Create(void);

#define QUEUE_STATIC_CREATE_PORT(portName, elSize, elAmount) \
    bool Queue_##portName##TxPort_Create(void){ \
        _##portName##Que = Queue_Create(1, elSize*elAmount, _##portName##QueElMem, &_##portName##QueCtrlMem); \
        if (_##portName##Que == NULL){ \
            return false; \
        } \
        return true; \
    }


#define QUEUE_STATIC_PUT_PORT_HEADER(portName) \
bool Queue_##portName##TxPort_Put(const void* elPtr);

#define QUEUE_STATIC_PUT_PORT(portName) \
    bool Queue_##portName##TxPort_Put(const void* elPtr){ \
        if(Queue_Put(_##portName##Que, elPtr) == Que_OK){ \
            return true; \
        } \
        return false; \
    }


#define QUEUE_STATIC_GET_PORT_HEADER(portName) \
bool Queue_##portName##TxPort_Get(void* elPtr);

#define QUEUE_STATIC_GET_PORT(portName) \
    bool Queue_##portName##TxPort_Get(void* elPtr){ \
        if(Queue_Get(_##portName##Que, elPtr) == Que_OK){ \
            return true; \
        } \
        return false; \
    }


#define QUEUE_STATIC_GET_MAX_DEPTH_PORT_HEADER(portName) \
uint16_t Queue_##portName##TxPortGetMaxDepth(void);

#define QUEUE_STATIC_GET_MAX_DEPTH_PORT(portName) \
    uint16_t Queue_##portName##TxPortGetMaxDepth(void){ \
        return Queue_GetMaxDepth(_##portName##Que); \
    }

#endif //LOGGERDEMO_QUEUE_MAKEPORTSMACROS_H
