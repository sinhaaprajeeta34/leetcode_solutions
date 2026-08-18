class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        // Har element kitne k-length subarrays me present hai
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            for (int x : seen) {
                freq[x]++;
            }
        }

        int ans = -1;

        // Jo element exactly ek k-length subarray me hai
        for (auto &p : freq) {
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }

        return ans;
    }
};