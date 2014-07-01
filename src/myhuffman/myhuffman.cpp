/*
 * myhuffman.cpp
 *
 *  Created on: Jun 25, 2014
 *      Author: xsun
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myhuffman.h"
#include "myPQueue.h"

myhtTree* buildHtTree(char *inputString)
{
	int* probirity = (int*)malloc(sizeof(int)*256);
	int i;
	for(i=0; i<256; ++i)
	{
		probirity[i] = 0;
	}
	for(i=0; i<strlen(inputString); ++i)
		probirity[(unsigned char)inputString[i]]++;

	myPQueue* myHtQueue;
	initMyPQueue(&myHtQueue);
	for(i=0; i<256; i++)
	{
		if(probirity[i] != 0)
		{
			myhtNode* node = (myhtNode*)malloc(sizeof(myhtNode));
			node->symble = (char)i;
			node->lchiled = NULL;
			node->rchild = NULL;
			addMyPQueue(&myHtQueue, node, probirity[i]);
		}
	}
	free(probirity);

	while(myHtQueue->size != 1)
	{
		unsigned int prob = myHtQueue->first->priority;
		prob += myHtQueue->first->nextQNode->priority;
		TYPE first = getMyPQueue(&myHtQueue);
		TYPE second = getMyPQueue(&myHtQueue);
		myhtNode* newNode = (myhtNode*)malloc(sizeof(myhtNode));
		newNode->lchiled = first;
		newNode->rchild = second;

		addMyPQueue(&myHtQueue, newNode, prob);
	}
	myhtTree* p = (myhtTree*)malloc(sizeof(myhtTree));
	p->root = getMyPQueue(&myHtQueue);

	return p;
}

void mytraverseTree(myhtNode* node, myhlTable** table, int k, char code[256])
{
	if(node->lchiled == NULL && node->rchild == NULL)
	{
		myhlNode* hlnode = (myhlNode*)malloc(sizeof(myhlNode));
		hlnode->symble = node->symble;
		hlnode->code = (char*)malloc(sizeof(char)*(strlen(code)+1));
		strcpy(hlnode->code, code);
		hlnode->next = NULL;
		if((*table)->first == NULL)
		{
			(*table)->first = hlnode;
			(*table)->last = hlnode;
		}else
		{
			(*table)->last->next = hlnode;
			(*table)->last = hlnode;
		}

	}

	if(node->lchiled != NULL)
	{
		code[k] = '0';
		mytraverseTree(node->lchiled, table, k++, code);
	}
	if(node->rchild != NULL)
	{
		code[k] = '1';
		mytraverseTree(node->rchild, table, k++, code);
	}
}

myhlTable* buildHlTable(myhtTree* myhuffmanTree)
{
	myhlTable* table = (myhlTable*)malloc(sizeof(myhlTable));
	table->first = NULL;
	table->last = NULL;

	char code[256];
	memset(code, '\0', sizeof(code));

	int k = 0;

	mytraverseTree(myhuffmanTree->root, &table, k, code);

	return table;
}







