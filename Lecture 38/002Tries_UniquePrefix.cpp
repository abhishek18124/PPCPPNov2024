#include<iostream>
#include<unordered_map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	unordered_map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0;
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
			cur->freq++;
		}
		cur->terminal = true;
	}

	// time : on avg. O(len of str) if you use an unordered_map<> as childMap
	// time : O(len of str * log(size of childMap)) is you use map<> as childMap
	// time : O(len of str * log(26)) is you use map<> as childMap ~ O(len of str)

	string shortestUniquePrefix(string str) {
		string ans = "";
		node* cur = root;
		for (char ch : str) {
			ans += ch;
			cur = cur->childMap[ch];
			if (cur->freq == 1) {
				return ans;
			}
		}
		return ""; // str has no unique prefix
	}

};

int main() {

	string words[] = {"code", "coder", "coding", "new", "neon"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	for (string word : words) {
		cout << "uniquePrefix(" << word << ") = " << t.shortestUniquePrefix(word) << endl;
	}

	return 0;
}