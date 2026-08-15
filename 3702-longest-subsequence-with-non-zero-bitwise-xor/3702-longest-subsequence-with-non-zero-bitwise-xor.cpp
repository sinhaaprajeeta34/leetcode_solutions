class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0, zero = 0;

        for (int x : nums) {
            xr ^= x;
            if (x == 0) zero++;
        }

        if (xr != 0) return nums.size();
        if (zero == nums.size()) return 0;
        return nums.size() - 1;
    }
};