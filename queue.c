#include "queue.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

Queue Queue_Create(uint16_t elSize, uint16_t elAmount, const void* elMem, Queue ctrlMem){
	if(elMem != NULL && ctrlMem != NULL){
		ctrlMem->count = 0;
	    ctrlMem->writePtr = 0;
	    ctrlMem->readPtr = 0;
		ctrlMem->elAmount = elAmount;
		ctrlMem->elSize = elSize;
		ctrlMem->elements = elMem;
		ctrlMem->maxDepth = 0;
		return ctrlMem;
	}
	else{
		return NULL;
	}
}

QueueStatus_t Queue_Reset(Queue self){
	if(self != NULL){
		self->count = 0;
	    self->writePtr = 0;
	    self->readPtr = 0;
	    self->maxDepth = 0;
	    return Que_OK;
	}
	else{
		return Que_Err;
	}
}

QueueStatus_t Queue_Put(Queue self, const void* elPtr){
    uint16_t nextWritePtr = self->writePtr + 1;
    nextWritePtr %= self->elAmount;
    if (nextWritePtr == self->readPtr)
        return Que_Full;
    memcpy((void*)self->elements + (self->elSize * nextWritePtr), elPtr, self->elSize);
    self->writePtr = nextWritePtr;
    if (self->writePtr > self->readPtr)
        self->count = self->writePtr - self->readPtr;
    else if (self->writePtr < self->readPtr)
        self->count = (self->elAmount - 1) - self->readPtr + self->writePtr;
    if(self->maxDepth < self->count)
        self->maxDepth = self->count;
    return Que_OK;
}

QueueStatus_t Queue_Get(Queue self, void* elPtr){
    if (self->writePtr == self->readPtr)
        return Que_Empty;
    uint16_t nextReadPtr = self->readPtr + 1;
    nextReadPtr %= self->elAmount;
    memcpy(elPtr, self->elements + (self->elSize*nextReadPtr), self->elSize);
    self->readPtr = nextReadPtr;
    return Que_OK;
}

uint16_t Queue_GetMaxDepth(Queue self){
	return self->maxDepth;
}

uint16_t Queue_GetSize(Queue self){
	return self->elAmount;
}
