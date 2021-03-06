#ifndef _SIM_LINKED_QUEUE_
#define _SIM_LINKED_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "simdef.h"

typedef struct queueNodeType
{
	SimCustomer data;
	struct queueNodeType* pLink;
} queueNode;

typedef struct LinkedqueueType
{
	int currentElementCount;	// ���� ������ ����
	queueNode* pFrontNode;		// Front ����� ������
	queueNode* pRearNode;		// Rear ����� ������
} Linkedqueue;

Linkedqueue* createLinkedQueue();
int enqueueLQ(Linkedqueue* pQueue, queueNode element);
queueNode* dequeueLQ(Linkedqueue* pQueue);
queueNode* peekLQ(Linkedqueue* pQueue);
void deleteLinkedQueue(Linkedqueue* pQueue);
int isLinkedQueueFull(Linkedqueue* pQueue);
int isLinkedQueueEmpty(Linkedqueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
