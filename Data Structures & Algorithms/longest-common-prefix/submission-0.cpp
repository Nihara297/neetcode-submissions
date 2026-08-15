class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first=strs.front();
        string last=strs.back();
        int len=min(first.size(),last.size());
        int i=0;
        while(i<len && first[i]==last[i]){
            i++;
        }
        return first.substr(0,i);
    }
};