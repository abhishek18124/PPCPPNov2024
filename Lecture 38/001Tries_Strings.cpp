/*

Implementation of the TRIE data structure to store strings.

Motivation :

Given an array of N strings, and an array of Q queries,
check for each query if it is present in the array or not.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	unordered_map<char, node*> childMap;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
	}

};

class trie {
	node* root;

public :

	trie() {
		root = new node('#');
	}

	// time : on avg. O(len of str) if you use an unordered_map<> as childMap
	// time : O(len of str * log(size of childMap)) is you use map<> as childMap
	// time : O(len of str * log(26)) is you use map<> as childMap ~ O(len of str)

	void insert(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
		}
		cur->terminal = true;
	}

	// time : on avg. O(len of str) if you use an unordered_map<> as childMap
	// time : O(len of str * log(size of childMap)) is you use map<> as childMap
	// time : O(len of str * log(26)) is you use map<> as childMap ~ O(len of str)

	bool search(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				return false;
			}
			cur = cur->childMap[ch];
		}
		return cur->terminal;
	}
};

int main() {

	string words[] = {"code", "coder", "coding", "block", "blocks", "news"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	string queries[] = {"code", "coding", "blocked", "block", "news", "new"};

	for (string query : queries) {
		t.search(query) ? cout << query << " present" << endl : cout << query << " absent" << endl;
	}

	cout << endl;

	return 0;
}