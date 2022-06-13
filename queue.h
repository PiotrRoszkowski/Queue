
#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct QueueStruct{
    volatile uint16_t count;
    volatile uint16_t writePtr;
    volatile uint16_t readPtr;
    uint16_t elAmount;
    uint16_t elSize;
    uint16_t maxDepth;
    const void* elements;
}Queue_t;
typedef Queue_t* Queue;

typedef enum{
	Que_OK = 0,
	Que_Empty,
	Que_Full,
	Que_Err,
}QueueStatus_t;

/**
 * Create function which is used to specific queue parameters.
 * @param elSize size of single element
 * @param elAmount amounts of elements in the queue, IMPORTANT: when use with static allocation, used elements number
 *                 equeals elAmount - 1
 * @param elMem
 * @param ctrlMem
 * @return
 */
Queue Queue_Create(uint16_t elSize, uint16_t elAmount, const void* elMem, Queue ctrlMem);
QueueStatus_t Queue_Reset(Queue);
QueueStatus_t Queue_Put(Queue, const void* elPtr);
QueueStatus_t Queue_Get(Queue, void* elPtr);
uint16_t Queue_GetMaxDepth(Queue self);
uint16_t Queue_GetSize(Queue self);

#endif  /* QUEUE_H */
