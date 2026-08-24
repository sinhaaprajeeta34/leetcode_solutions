class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // dp[i] = maximum score difference starting from index i
        int ans = stones[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            ans = max(ans, stones[i] - ans);
        }

        return ans;
    }
};