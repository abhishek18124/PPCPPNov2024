class Solution {
public:

    bool canMake(const vector<int>& bloomDay, int m, int k, int timeLimit) {

        int n = bloomDay.size();

        int collectCnt = 0; // to track how many adjacent bloomed flowers we've seen
        int bouquetCnt = 0; // to track how many bouquets of k adjacent flowers we've made

        for (int i = 0; i < n; i++) {

            if (bloomDay[i] <= timeLimit) { // ith flower will bloom within the timeLimit
                collectCnt++;
                if (collectCnt == k) { // you've managed to make a bouquet using k-adjacent flowers
                    bouquetCnt++;
                    collectCnt = 0; // reset collectCnt since flowers collected are used
                }
            } else {
                collectCnt = 0; // reset collectCnt since we need k adjacent flowers for a bouquet
            }

        }

        return bouquetCnt >= m;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (s <= e) { // log(e-s) * n where e-s is the size of the search space

            int mid = s + (e - s) / 2;

            // can I make 'm' bouquets of 'k' adjacent flowers in 'mid' no. of days ?

            if (canMake(bloomDay, m, k, mid)) {

                ans = mid;
                e = mid - 1;

            } else {

                s = mid + 1;

            }

        }

        return ans;

    }
};