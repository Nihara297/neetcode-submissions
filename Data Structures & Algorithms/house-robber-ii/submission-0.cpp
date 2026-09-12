class Solution {
public:
    int rob(vector<int>&nums, int first, int last){
        int one=0;
        int two=0;
        for(int i=first; i<=last; i++){
            int cur=max(one, nums[i]+two);
            two=one;
            one=cur;
        }
        return one;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int case1=rob(nums, 1, n-1);
        int case2=rob(nums, 0, n-2);
        return max(case1, case2);
    }
};
