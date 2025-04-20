/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

	// time : on avg O(n) if you are using unordered_map<>
	// time : O(nlogn)  if you are using map<>
	// space: O(n) due to map<> / unordered_map<>

	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap;

		for (int x : nums) {

			if (startMap.find(x - 1) == startMap.end()) {
				// x-1 is not present, for now, you can make x a starting point
				startMap[x] = true;
			} else {
				// x-1 is already present, so x cannot be starting point
				startMap[x] = false;
			}

			if (startMap.find(x + 1) != startMap.end()) {
				// x+1, which was earlier set as a starting point
				// can no longer be a starting point since you've
				// seen x
				startMap[x + 1] = false;
			}

		}

		int maxSoFar = 0;

		for (pair<int, bool> p : startMap) {

			int key = p.first;
			bool canStart = p.second;

			if (canStart) {

				// find the length of the sequence of consecutive
				// elements that start with key

				int cnt = 0;
				while (startMap.find(key) != startMap.end()) {
					cnt++;
					key++;
				}

				maxSoFar = max(maxSoFar, cnt);

			}

		}

		return maxSoFar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {0, 1, 4, 5, 6, 11, 12, 13, 14};

	cout << s.longestConsecutive(nums) << endl;

}
