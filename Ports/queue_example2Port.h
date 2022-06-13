//
// Created by proszkowski on 01.06.2022.
//

#ifndef AMCT_DRIVERS_STM32_QUEUE_EXAMPLE2PORT_H
#define AMCT_DRIVERS_STM32_QUEUE_EXAMPLE2PORT_H

#include <stdbool.h>

#define EXAMPLE2_QUE_LEN 512

bool Queue_example2TxPort_Create(void);
bool Queue_example2TxPort_Put(const void* elPtr);
bool Queue_example2TxPort_Get(void* elPtr);

#endif //AMCT_DRIVERS_STM32_QUEUE_EXAMPLE2PORT_H
