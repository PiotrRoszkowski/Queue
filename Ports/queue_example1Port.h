//
// Created by proszkowski on 25.05.2022.
//

#ifndef AMCT_EXAMPLE_QUEUE_LOGGERPORT_H
#define AMCT_EXAMPLE_QUEUE_LOGGERPORT_H

#include <stdbool.h>

#define EXAMPLE1_QUE_LEN 256 //Actually queue is able to store one element less

bool Queue_example1TxPort_Create(void);
bool Queue_example1TxPort_Put(const void* elPtr);
bool Queue_example1TxPort_Get(void* elPtr);
uint16_t Queue_example1TxPortGetMaxDepth(void);

#endif //AMCT_EXAMPLE_QUEUE_LOGGERPORT_H
