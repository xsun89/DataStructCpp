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
	struct htNode_* lchiled, rchild;
} myhtNode;

typedef struct myhtTree_
{
	htNode * root;
} myhtTree;


myhtTree* buidHtTree(char* inputString);

#endif /* MYHUFFMAN_H_ */
