/*
 * myPQueue.cpp
 *
 *  Created on: Jun 23, 2014
 *      Author: sun38
 */
#include <stdio.h>
#include <stdlib.h>
#include "myPQueue.h"
void initMyPQueue(myPQueue** queue) {
	(*queue) = (myPQueue*) malloc(sizeof(myPQueue));
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
	if((*queue)->first == NULL || (*queue)->size == 0 )
	{
		node->nextQNode = NULL;
		(*queue)->first = node;
		(*queue)->size++;
		return;
	} else
	{
		if(priority <= (*queue)->first->priority)
		{
			node->nextQNode = (*queue)->first;
			(*queue)->first = node;
			(*queue)->size++;
			return;
		} else {
			myPQueueNode* p = (*queue)->first;
			while(p)
			{
				if(priority <= p->priority)
					break;
				p = p->nextQNode;
			}
			node->nextQNode = p->nextQNode;
			p->nextQNode = node;
			(*queue)->size++;
			return;
		}
	}

}

TYPE getMyPQueue(myPQueue** queue)
{
	TYPE htNode;
	if((*queue)->size <= 0 || (*queue)->first == NULL)
	{
		printf("\nQueue is empty.\n");
	}else
	{
		htNode = (*queue)->first->val;
		(*queue)->first = (*queue)->first->nextQNode;
		(*queue)->size--;
	}

	return htNode;
}

