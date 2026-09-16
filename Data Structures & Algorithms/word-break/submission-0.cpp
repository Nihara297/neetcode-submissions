class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(n+1, false);
        dp[0]=true;
        for(int i=0; i<=n; i++){
            for(string word:wordDict){
                int len=word.size();
                if(len<=i && dp[i-len]){
                    if(s.substr(i-len, len)==word){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
