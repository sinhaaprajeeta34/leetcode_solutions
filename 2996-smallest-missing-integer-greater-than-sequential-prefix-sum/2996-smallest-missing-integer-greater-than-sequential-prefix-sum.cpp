class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int sum = nums[0];

        // Find longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1)
                break;

            sum += nums[i];
        }

        // Find smallest missing number >= sum
        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};