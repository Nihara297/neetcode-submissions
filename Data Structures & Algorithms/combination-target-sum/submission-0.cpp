class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    void backtrack(vector<int>& nums, int target, int start){
        int n=nums.size();
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=start; i<n; i++){
            curr.push_back(nums[i]);
            backtrack(nums, target-nums[i], i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return ans;
    }
};
