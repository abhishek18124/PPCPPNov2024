#include<iostream>

using namespace std;

class ListNode {
public:

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}


void printLinkedList(ListNode* head) {

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

ListNode* findMidPoint(ListNode* head) {
	if (!head) { // head == NULL
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

ListNode* mergeSortedLinkedList(ListNode* head1, ListNode* head2) {

	ListNode* dummy = new ListNode(0);
	ListNode* temp = dummy; // think of temp as a pointer to the tail of the linkedList under-construction

	while (head1 != NULL and head2 != NULL) {
		if (head1->val < head2->val) {
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;
		} else {
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;
		}
	}

	if (head1 != NULL) {
		temp->next = head1;
	}

	if (head2 != NULL) {
		temp->next = head2;
	}

	return dummy->next;

}

// time : O(nlogn)
// space: O(logn) due to fn call stack

/*
	t(n) = n.c + 2t(n/2) + n.c
	t(n) = 2t(n/2) + 2.n.c
	t(n) = 2t(n/2) + n.c ~ O(nlogn)
*/

ListNode* mergeSort(ListNode* head1) {

	// base case

	if (head1 == NULL || head1->next == NULL) {
		// linkedList is empty or linkedList has one node
		return head1;
	}

	// recursive case

	// 1. divide the given linkedList around the midPoint

	ListNode* midPoint = findMidPoint(head1);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 2. sort the two sublists recursively

	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	// 3. merge the two sorted sublists

	return mergeSortedLinkedList(head1, head2);

}


int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = mergeSort(head);

	printLinkedList(head);

	return 0;
}