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

ListNode* insertAtHead(ListNode* head, int val) { // here we are passing headPtr by value

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;
	return head;

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

	ListNode* head = NULL; // linkedList is empty

	head = insertAtHead(head, 50);
	head = insertAtHead(head, 40);
	head = insertAtHead(head, 30);
	head = insertAtHead(head, 20);
	head = insertAtHead(head, 10);

	printLinkedList(head);

	return 0;
}