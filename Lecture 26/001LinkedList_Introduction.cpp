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

void insertAtHead(ListNode*& headRef, int val) { // here we are passing headPtr by ref
	// as we want changes done to headPtr inside the fn to reflect
	// in the caller fn i.e. main()

	ListNode* n = new ListNode(val);
	n->next = headRef;
	headRef = n;

}

void printLinkedList(ListNode* head) { // here we are passing headPtr by value as
	// we don't want changes done to headPtr to reflect
	// in the caller fn i.e. main()

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

}

int main() {

	// ListNode* n = new ListNode(10);
	// cout << n->val << endl;
	// if (n->next == NULL) {
	// 	cout << "there is no node following the node we've created" << endl;
	// }

	ListNode* head = NULL; // linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	if (head == NULL) {
		cout << "LinkedList is empty" << endl;
	}

	printLinkedList(head);

	printLinkedList(head);

	return 0;
}