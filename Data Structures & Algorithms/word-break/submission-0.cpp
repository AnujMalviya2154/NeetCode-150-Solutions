class Solution {
private:
    struct TrieNode {
        int child[26];
        bool isEnd;

        TrieNode() {
            fill(child, child + 26, -1);
            isEnd = false;
        }
    };

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Build the Trie from the dictionary.
        vector<TrieNode> trie(1);

        for (const string& word : wordDict) {
            int node = 0;

            for (char ch : word) {
                int idx = ch - 'a';

                if (trie[node].child[idx] == -1) {
                    trie[node].child[idx] = trie.size();
                    trie.emplace_back();
                }

                node = trie[node].child[idx];
            }

            trie[node].isEnd = true;
        }

        int n = s.size();

        // dp[i] = first i characters can be segmented.
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // Start matching dictionary words at each valid prefix.
        for (int i = 0; i < n; i++) {
            if (!dp[i]) {
                continue;
            }

            int node = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                
                if (trie[node].child[idx] == -1) {
                    break;
                }

                node = trie[node].child[idx];

                if (trie[node].isEnd) {
                    dp[j + 1] = true;
                }
            }
        }

        return dp[n];
    }
};