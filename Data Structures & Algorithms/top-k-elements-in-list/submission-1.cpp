class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;

        // Count frequency
        for (int x : nums)
            mp[x]++;

        // Store {frequency, number}
        vector<pair<int, int>> v;

        for (auto x : mp)
            v.push_back({x.second, x.first});

        // Sort by frequency
        sort(v.rbegin(), v.rend());

        vector<int> ans;

        for (int i = 0; i < k; i++)
            ans.push_back(v[i].second);

        return ans;
    }
};