#include "polynomial.h"

int	main(void)
{
	LinkedList *a = createLinkedList();
	LinkedList *b = createLinkedList();

	ListNode *a1 = createNode(6, 6);
	ListNode *a2 = createNode(4, 5);
	ListNode *a3 = createNode(2, 2);
	addLLElement(a, 0, a1);
	addLLElement(a, 1, a2);
	addLLElement(a, 2, a3);

	ListNode *b1 = createNode(1, 5);
	ListNode *b2 = createNode(2, 4);
	ListNode *b3 = createNode(3, 2);
	ListNode *b4 = createNode(4, 0);
	addLLElement(b, 0, b1);
	addLLElement(b, 1, b2);
	addLLElement(b, 2, b3);
	addLLElement(b, 3, b4);

	displayLinkedList(a);
	displayLinkedList(b);

	displayLinkedList(addPolyNode(a, b));
	return (0);
}