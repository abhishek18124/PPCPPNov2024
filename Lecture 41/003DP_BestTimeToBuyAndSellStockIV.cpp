// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {

public:

    int f(const vector<int>& prices, int N, int i, int k) {

        // base case

        if (i == N || k == 0) {
            return 0;
        }

        // recursive case

        // f(i, k) = find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day

        int donotBuyOption = f(prices, N, i + 1, k);

        // 2. buy the stock on the ith day

        int buyOptionMaxSofar = 0;

        for (int j = i + 1; j <= N - 1; j++) {

            buyOptionMaxSofar = max(buyOptionMaxSofar,
                                    (prices[j] - prices[i]) + f(prices, N, j + 1, k - 1));

        }

        return max(donotBuyOption, buyOptionMaxSofar);

    }

    // time : O(N^2K)
    // space: O(NK) due to dp[][]

    int fBottomUp(const vector<int>& prices, int N, int K) {

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

        // 0-init handles the base case (i == N || k == 0) automatically

        for (int i = N - 1; i >= 0; i--) {
            for (int k = 1; k <= K; k++) {
                // dp[i][k] = f(i, k) = find the max. profit we can make
                // from days i to N-1 by doing <= k transaction

                // decide for the ith day

                // option 1 : don't buy on the ith day

                int donotBuyOption = dp[i + 1][k];

                // option 2 : buy on the ith day

                int buyOptionMaxSofar = 0;
                for (int j = i + 1; j <= N - 1; j++) {
                    buyOptionMaxSofar = max(buyOptionMaxSofar, (prices[j] - prices[i]) + dp[j + 1][k - 1]);
                }

                dp[i][k] = max(donotBuyOption, buyOptionMaxSofar);

            }
        }

        return dp[0][K]; // at the 0,Kth index we store f(0, K) which is org. prob.

    }

    int maxProfit(int K, vector<int>& prices) {

        int N = prices.size();

        // return f(prices, N, 0, K);

        return fBottomUp(prices, N, K);

    }
};