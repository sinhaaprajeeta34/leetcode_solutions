class Solution {
    public long[] resultArray(int[] nums, int k) {

        long[] ans = new long[k];

        long[] dp = new long[k];

        for (int num : nums) {

            int value = num % k;

            long[] newDp = new long[k];

            // Subarray containing only current element
            newDp[value]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {

                int newRemainder = (r * value) % k;

                newDp[newRemainder] += dp[r];
            }

            // Add current subarrays to answer
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
}