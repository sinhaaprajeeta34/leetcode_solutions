class Solution {
public:
vector<vector<int>>arr;
void helper(int i, vector<int>&nums, vector<int>&ans)
     {
        if(i==nums.size()){
            arr.push_back(ans);
            return;             //basecase
        }

    //include
    ans.push_back(nums[i]);
    helper(i+1,nums,ans);
    //exclude
    ans.pop_back();
    helper(i+1,nums,ans);
     }

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<int> ans;
        helper(0, nums,ans);
        return arr;
}
        
    
};