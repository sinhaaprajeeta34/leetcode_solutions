class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // minIdx should be the leftmost index
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // 1. Remove both from left
        int option1 = right + 1;

        // 2. Remove both from right
        int option2 = n - left;

        // 3. Remove min from left and max from right
        int option3 = left + 1 + n - right;

        return min({option1, option2, option3});
    }
};