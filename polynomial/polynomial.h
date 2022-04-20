#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
typedef struct ListNodeType
{
	int coef;
	int degree;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	ListNode headerNode;
} LinkedList;

LinkedList* createLinkedList();
ListNode* createNode(int coef, int degree);
int addLLElement(LinkedList* pList, int position, ListNode *element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void displayLinkedList(LinkedList *pList);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

LinkedList*	addPolyNode(LinkedList *a, LinkedList *b);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif