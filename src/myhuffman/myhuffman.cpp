/*
 * myhuffman.cpp
 *
 *  Created on: Jun 25, 2014
 *      Author: xsun
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "huffman.h"
#include "pQueue.h"

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


	myhtTree* p;

	return p;
}



