/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node *NODE;

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	else if (head->next == NULL)
		return head;
	else {
		NODE temp1 = head, temp2, temp3 = NULL;

		while (temp1 != NULL){
			temp2 = temp1->next;
			temp1->next = temp3;
			temp3 = temp2->next;
			temp2->next = temp1;
			if (temp3 == NULL)
				return temp2;
			else
				temp1 = temp3->next;
			temp3->next = temp2;
		}
		return temp3;
	}
}
