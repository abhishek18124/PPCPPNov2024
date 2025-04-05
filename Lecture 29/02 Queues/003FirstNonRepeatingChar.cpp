#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> q;
	int freq[26] = {0};

	while (true) {

		char ch;
		cin >> ch;

		if (ch == '.') break;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// ch is currently a non-repeating char so track it in the queue
			q.push(ch);
		}

		// find out what is the 1st non-repeating char. in the stream
		// once you've reach ch

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			q.pop();
		}

		if (q.empty()) {
			// there is no non-repeating char. in the stream
			cout << -1 << " ";
		} else {
			// whatever is at the front of the queue is the
			// 1st non-repeating char.
			cout << q.front() << " ";
		}

	}

	return 0;
}