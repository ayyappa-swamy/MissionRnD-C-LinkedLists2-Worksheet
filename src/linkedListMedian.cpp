/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node * NODE;

int linkedListMedian(struct node *head) {
	NODE fast, slow;
	if (head == NULL)
		return -1;
	else if (head->next == NULL)
		return head->num;
	else if (head->next->next == NULL)
		return (int)((head->num + head->next->num) / 2);
	else {
		fast = slow = head;
		while (fast != NULL){
			if (fast->next != NULL)
				fast = fast->next->next;
			else break;
			if (fast != NULL)
				slow = slow->next;
		}
		if (fast == NULL)
			return (int)((slow->num + (slow->next->num)) / 2);
		else return slow->num;
	}
}
