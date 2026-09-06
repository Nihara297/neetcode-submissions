class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int need[128]={0};
        int cnt[128]={0};
        for(char c:t){
            need[c]++;
        }
        int l=0;
        int have=0;
        int ans=INT_MAX;
        int start=0;
        for(int r=0; r<n; r++){
            cnt[s[r]]++;
            if(cnt[s[r]]<=need[s[r]]){
                have++;
            }
            while(have==m){
                if(r-l+1<ans){
                    ans=r-l+1;
                    start=l;
                }
                cnt[s[l]]--;
                if(cnt[s[l]]<need[s[l]]){
                    have--;
                }
                l++;
            }
        }
        if(ans==INT_MAX){
            return "";
        }
        return s.substr(start, ans);
        
    }
};
