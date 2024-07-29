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
    vector<string> retval;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
        dfs(s, 0, "");
        return retval;
    }

    void dfs(string& s, int cur, string temp) {
        if (cur == s.size()) {
            retval.push_back(temp);
        }

        TrieNode* curr = root;
        for (int i = cur; i < s.size(); i++) {
            if (curr->next[s[i] - 'a']) {
                curr = curr->next[s[i] - 'a'];
                if (curr->isEnd) {
                    dfs(s, i + 1, temp.empty() ? s.substr(cur, i - cur + 1) : temp + " " + s.substr(cur, i - cur + 1));
                }
            } else {
                break;
            }
        }
        return;
    }
};