class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()){
            return "";
        }
        vector<pair<int, string>>&values=mp[key];
        int n=values.size();
        int l=0; 
        int r=n-1;
        string ans = "";
        while(l<=r){
            int m=l+(r-l)/2;
            if(values[m].first<=timestamp){
                ans=values[m].second;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return ans;
    }
};
