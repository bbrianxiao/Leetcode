class Solution {
    class TrieNode {
        public:
        TrieNode* next[26];
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
            isEnd = false;
        }
    };
    TrieNode* root;
    int memo[301];
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        for (auto& word : wordDict) {
            TrieNode* curr = root;
            for (int i = 0; i < word.size(); i++) {
                int leafChar = word[i] - 'a';
                if (!curr->next[leafChar]) {
                    curr->next[leafChar] = new TrieNode();
                }
                curr = curr->next[leafChar];
            }
            curr->isEnd = true;
        }
        return dfs(s, 0);
    }

    bool dfs(string&s, int cur) {
        if (cur == s.size()) return true;
        if (memo[cur]) return false;
        TrieNode* curr = root;
        for (int i = cur; i < s.size(); i++) {
            if (curr->next[s[i] - 'a']) {
                curr = curr->next[s[i] - 'a'];
                if (curr->isEnd && dfs(s, i + 1)) {
                    return true;
                }
            } else {
                break;
            }
        }
        memo[cur] = 1;
        return false;
    }
};
