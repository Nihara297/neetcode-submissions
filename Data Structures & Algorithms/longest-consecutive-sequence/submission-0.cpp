class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        set<int> s(nums.begin(), nums.end());

        int ans = 1;
        int count = 1;

        for (auto it = next(s.begin()); it != s.end(); it++) {
            auto prev = std::prev(it);

            if (*it == *prev + 1) {
                count++;
            } else {
                count = 1;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};