#include<iostream>

using namespace std;

class ListNode {

public :

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

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
}

ListNode* getNode(ListNode* head, int j) {

	// get the address of the node at index j

	int k = 1;

	while (head != NULL and k <= j) {
		head = head->next;
		k++;
	}

	return head;

}

// time : O(n)

void deleteAtIndex(ListNode*& head, int idx) {

	if (idx == 0) {
		deleteAtHead(head);
		return;
	}

	ListNode* prev = getNode(head, idx - 1);
	if (prev == NULL) {
		// idx is not valid
		return;
	}
	ListNode* cur = prev->next;
	if (cur == NULL) {
		// prev exists but since idx = n, we don't have a node
		// to delete
		return;
	}
	prev->next = cur->next;
	delete cur;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtIndex(head, 2);

	printLinkedList(head);

	return 0;
}