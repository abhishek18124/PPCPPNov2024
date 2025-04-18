
#include<iostream>
#include<queue>

using namespace std;

string reorganise(const string& str) {

    int freq[26] = {0};
    for (char ch : str) { // time : O(n)
        freq[ch - 'a']++;
    }

    priority_queue<pair<int, char>> maxHeap; // by default heap is built on the 1st member of the pair
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            maxHeap.push({freq[i], i + 'a'});
        }
    }

    // while (!maxHeap.empty()) {
    //     // pair<int, char> p = maxHeap.top();
    //     // maxHeap.pop();
    //     // cout << p.first << " " << p.second << endl;

    //     auto [freq, ch] = maxHeap.top(); maxHeap.pop();
    //     cout << freq << " " << ch << endl;

    // }

    // cout << endl;

    string out = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {
            pair<int, char> firstMax = maxHeap.top();
            maxHeap.pop();
            if (firstMax.first == 1) {
                out += firstMax.second;
            } else {
                out =  "";
            }

        } else {
            pair<int, char> firstMax = maxHeap.top(); // (5, a)
            maxHeap.pop();

            pair<int, char> secondMax = maxHeap.top(); // (4, b)
            maxHeap.pop();

            out += firstMax.second; // out.push_back(firstMax.second)
            firstMax.first--;

            out += secondMax.second; // out.push_back(secondMax.second)
            secondMax.first--;

            if (firstMax.first > 0) {
                maxHeap.push(firstMax);
            }

            if (secondMax.first > 0) {
                maxHeap.push(secondMax);
            }

        }

    }

    return out;

}

int main() {

    string str = "aaaaabbbbcccdd";

    cout << reorganise(str) << endl;

    return 0;
}