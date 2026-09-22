class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> in;
        for (string w : words)
            for (char c : w)
                in[c] = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i], b = words[i + 1];
            int j = 0, n = min(a.size(), b.size());
            while (j < n && a[j] == b[j])
                j++;
            if (j == n) {
                if (a.size() > b.size())
                    return "";
                continue;
            }
            char u = a[j], v = b[j];

            if (adj[u].insert(v).second)
                in[v]++;
        }
        queue<char> q;
        for (auto p : in)
            if (p.second == 0)
                q.push(p.first);
        string ans;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            ans += u;
            for (char v : adj[u]) {
                in[v]--;

                if (in[v] == 0)
                    q.push(v);
            }
        }
        return ans.size() == in.size() ? ans : "";
    }
};
