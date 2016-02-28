/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node* NODE;

NODE getKthNode(NODE startNode, int K)
{
	if (startNode == NULL)
		return NULL;
	NODE temp = startNode;
	while ((K >= 1) && (temp != NULL)){
		temp = temp->next;
		K--;
	}
	return temp;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	NODE temp = head;
	if ((head == NULL) || (K < 1))
		return NULL;
	while (temp != NULL){
		temp = getKthNode(temp,K - 1);
		if (temp != NULL){
			NODE newNode = (NODE)malloc(sizeof(NODE));
			newNode->num = K;
			newNode->next = temp->next;
			temp->next = newNode;
			temp = newNode->next;
		}
	}
	return head;
}
