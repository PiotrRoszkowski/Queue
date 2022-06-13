//
// Created by proszkowski on 25.05.2022.
//

#include <stdlib.h>
#include "queue_example1Port.h"

#define EXAMPLE1_QUE_LEN 256 //Actually queue is able to store one element less

QUEUE_STATIC_ALLOCATION(example1, 1, EXAMPLE1_QUE_LEN)
QUEUE_STATIC_CREATE_PORT(example1, 1, EXAMPLE1_QUE_LEN)
QUEUE_STATIC_PUT_PORT(example1)
QUEUE_STATIC_GET_PORT(example1)
QUEUE_STATIC_GET_MAX_DEPTH_PORT(example1)