#ifndef _LINKEDLIST_
#define _LINKEDLIST_
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} CListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	CListNode headerNode;
} CircularList;

CircularList* createCircularList();
int addCLElement(CircularList* pList, int position, CListNode element);
int addFirstElement(CircularList* pList, int position, CListNode element);
int removeCLElement(CircularList* pList, int position);
int removeFirstElement(CircularList* pList, int position);
CListNode* getCLElement(CircularList* pList, int position);

void displayCircularList(CircularList *pList);
void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
void deleteCircularList(CircularList* pList);

void	timeCheck(CircularList *pList, int max);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif