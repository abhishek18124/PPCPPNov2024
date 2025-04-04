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

// time : O(n)
// space: O(1)

bool searchIterative(ListNode* head, int target) {
	while (head != NULL) {
		if (head->val == target) {
			return true;
		}
		head = head->next;
	}
	// target not found
	return false;
}

// time : O(n)
// space: O(n) due to fn call stack

bool searchRecursive(ListNode* head, int target) {

	// base case

	if (head == NULL) {
		return false;
	}

	// recursive case

	if (head->val == target) {
		return true;
	}

	// ask your friend to search for the target in the sublist that starts
	// from the node which comes after the head node

	return searchRecursive(head->next, target);

}


int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int target = 500;

	searchIterative(head, target) ? cout << target << " found" << endl :
	                                     cout << target << " not found" << endl;


	searchRecursive(head, target) ? cout << target << " found" << endl :
	                                     cout << target << " not found" << endl;


	return 0;
}