/*
 * myPQueue.h
 *
 *  Created on: Jun 23, 2014
 *      Author: sun38
 */

#ifndef MYPQUEUE_H_
#define MYPQUEUE_H_

#include "myhuffman.h"

#define TYPE myhtNode *
#define MAX_SZ 256
typedef struct myPQueueNode_
{
	TYPE val;
	unsigned int priority;
	struct myPQueueNode_* nextQNode;
} myPQueueNode;

typedef struct myPQueue_
{
	unsigned int size;
	myPQueueNode* first;
} myPQueue;

void initMyPQueue(myPQueue** queue);
void addMyPQueue(myPQueue** queue, TYPE val, unsigned int priority);
TYPE getMyPQueue(myPQueue** queue);


#endif /* MYPQUEUE_H_ */
