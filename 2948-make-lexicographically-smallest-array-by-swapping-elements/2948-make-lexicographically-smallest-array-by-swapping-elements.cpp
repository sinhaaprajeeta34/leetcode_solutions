class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<int> ans(n);

        int start = 0;

        while (start < n) {
            int end = start;

            // Find all elements connected through differences <= limit
            while (end + 1 < n &&
                   a[end + 1].first - a[end].first <= limit) {
                end++;
            }

            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(a[i].second);
            }

            sort(indices.begin(), indices.end());

            // a[start...end] values are already sorted
            for (int i = 0; i < indices.size(); i++) {
                ans[indices[i]] = a[start + i].first;
            }

            start = end + 1;
        }

        return ans;
    }
};