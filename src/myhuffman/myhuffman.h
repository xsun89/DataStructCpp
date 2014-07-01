/*
 * myhuffman.h
 *
 *  Created on: Jun 23, 2014
 *      Author: sun38
 */

#ifndef MYHUFFMAN_H_
#define MYHUFFMAN_H_

typedef struct myhtNode_
{
	char symble;
	struct myhtNode_* lchiled, *rchild;
} myhtNode;

typedef struct myhtTree_
{
	myhtNode * root;
} myhtTree;

typedef struct myhlNode_
{
	char symble;
	char* code;
	struct myhlNode_* next;
}myhlNode;

typedef struct myhtTable_
{
	myhlNode * first;
	myhlNode * last;
}myhlTable;

myhtTree* buidHtTree(char* inputString);
myhlTable* buildHlTable(myhtTree* myhuffmanTree);

#endif /* MYHUFFMAN_H_ */
