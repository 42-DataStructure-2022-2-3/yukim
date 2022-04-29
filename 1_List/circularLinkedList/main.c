#include "circularList.h"

int main(void)
{
	CircularList *a = createCircularList();
	CListNode	node1;
	CListNode	node2;
	//Case 1. 노드 1개인 상황
	node1.data = 42;
	node1.pLink = NULL;
	addCLElement(a, 0, node1);
	//Case 2. 마지막 노드 수정
	node2.data = 12;
	node2.pLink = NULL;
	addCLElement(a, 1, node2);
	addCLElement(a, 0, node2);

	displayCircularList(a);
	removeCLElement(a, 2);
	displayCircularList(a);
}