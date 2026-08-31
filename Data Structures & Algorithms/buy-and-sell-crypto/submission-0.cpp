class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprice=prices[0];
        int maxprof=0;
        for(int i=1; i<n; i++){
            maxprof=max(maxprof, prices[i]-minprice);
            minprice=min(prices[i],minprice);
        }
        return maxprof;
    }
};
