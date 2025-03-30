#include<iostream>
#include<set>

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

// time : O(nlogn)

bool isCyclePresent(ListNode* head) {
	set<ListNode*> s;
	while (head != NULL) {
		if (s.find(head) != s.end()) {
			// you've found a cycle
			return true;
		}
		s.insert(head);
		head = head->next;
	}

	// there is no cycle present
	return false;
}

bool isCyclePresentEfficient(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			// cycle found
			return true;
		}
	}
	// no cycle found
	return false;
}

int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next;

	isCyclePresent(head) ? cout << "cycle found" << endl :
	                            cout << "cycle not found" << endl;

	isCyclePresentEfficient(head) ? cout << "cycle found" << endl : cout << "cycle not found" << endl;

	return 0;
}