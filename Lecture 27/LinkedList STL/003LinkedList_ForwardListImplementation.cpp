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

class forward_list {

	ListNode* head;
	int  cnt;

public :

	forward_list() {
		head = NULL;
		cnt = 0;
	}

	void push_front(int val) {
		ListNode* n = new ListNode(val);
		n->next = head;
		head = n;
		cnt++;
	}

	void pop_front() {
		ListNode* temp = head;
		head = head->next;
		delete temp;
		cnt--;
	}

	int size() {
		return cnt;
	}

	bool empty() {
		return head == NULL; // cnt == 0
	}

	int front() {
		return head->val;
	}

	void traverse() {
		ListNode* temp = head;
		while (temp != NULL) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

};

int main() {

	forward_list fw;

	fw.push_front(50);
	fw.push_front(40);
	fw.push_front(30);
	fw.push_front(20);
	fw.push_front(10);

	cout <<  "head->val : " << fw.front() << endl;

	fw.traverse();

	cout << "size : " << fw.size() << endl;

	fw.pop_front();
	fw.pop_front();

	cout <<  "head->val : " << fw.front() << endl;

	fw.traverse();

	cout << "size : " << fw.size() << endl;

	fw.pop_front();
	fw.pop_front();
	fw.pop_front();

	fw.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}


