/*
 * myPQueue.cpp
 *
 *  Created on: Jun 23, 2014
 *      Author: sun38
 */
#include <stdio.h>
#include <stdlib.h>
#include "myPQueue.h"
void initMyPQueue(myPQueue** queue)
{
	(*queue) = (myPQueue*)malloc(sizeof(myPQueue));
	(*queue)->size = 0;
	(*queue)->first = NULL;

	return;

}
void addMyPQueue(myPQueue** queue, TYPE val, unsigned int priority)
{
	if((*queue)->size >= MAX_SZ)
	{
		printf("\nQueue is full.\n");
		return;
	}
	myPQueueNode* node = (myPQueueNode*)malloc(sizeof(myPQueueNode));
	node->priority = priority;
	node->val = val;
	if((*queue)->first == NULL)
	{
		(*queue)->first = node;
		(*queue)->size++;
		return;
	}else
	{

	}
}

TYPE getMyPQueue(myPQueue** queue)
{
	TYPE htNode;
	return htNode;
}


