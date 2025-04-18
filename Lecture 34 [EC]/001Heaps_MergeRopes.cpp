/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int mergeRopes(const vector<int>& ropeLengths) {

    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // for (auto rope : ropeLengths) {
    //     minHeap.push(rope);
    // }

    priority_queue<int, vector<int>, greater<int>> minHeap(
                ropeLengths.begin(),
                ropeLengths.end());

    int ans = 0;

    while (minHeap.size() > 1) { // time : O(nlogn) // space : O(n) due to minHeap
        int firstSmallest = minHeap.top();
        minHeap.pop();

        int secondSmallest = minHeap.top();
        minHeap.pop();

        ans += (firstSmallest + secondSmallest);
        minHeap.push(firstSmallest + secondSmallest);
    }

    return ans;


}

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    cout << mergeRopes(ropeLengths) << endl;

    return 0;
}