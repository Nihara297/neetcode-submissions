class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxp=nums[0];
        int minp=nums[0];
        int ans=nums[0];
        for(int i=1; i<n; i++){
            int x=nums[i];
            int nmax=max(x,max(maxp*x,minp*x));
            int nmin=min(x,min(maxp*x,minp*x));
            maxp=nmax;
            minp=nmin;
            ans=max(ans, maxp);
        }
        return ans;
    }
};
