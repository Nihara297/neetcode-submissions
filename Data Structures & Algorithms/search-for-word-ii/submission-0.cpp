class Solution {
private:
    struct TrieNode {
        TrieNode* child[26];
        string word;
        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };
    TrieNode* root;
    vector<string> ans;
    int m, n;
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;
        char ch = board[r][c];
        if (ch == '#')
            return;
        if (node->child[ch - 'a'] == nullptr)
            return;
        node = node->child[ch - 'a'];
        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";  
        }
        board[r][c] = '#';
        dfs(board, r + 1, c, node);
        dfs(board, r - 1, c, node);
        dfs(board, r, c + 1, node);
        dfs(board, r, c - 1, node);
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        root = new TrieNode();
        for (string& word : words) {
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (node->child[idx] == nullptr)
                    node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->word = word;
        }
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        return ans;
    }
};