class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            int num=nums[i];
            if(s.count(num)){
            return true;
            }
            s.insert(num);
        }
        return false;
    }
};