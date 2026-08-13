class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>m;
        for(string s: strs){
            string key=s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto i: m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
