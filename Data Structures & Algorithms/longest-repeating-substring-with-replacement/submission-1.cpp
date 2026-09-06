class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26]={0};
        int n=s.size();
        int l=0;
        int ans=0;
        int mx=0;
        for(int r=0; r<n; r++){
            cnt[s[r]-'A']++;
            mx=max(mx, cnt[s[r]-'A']);
            while(r-l+1-mx>k){
                cnt[s[l]-'A']--;
                l++;
            }
            ans=max(ans, r-l+1);
        } 
        return ans;

    }
};
