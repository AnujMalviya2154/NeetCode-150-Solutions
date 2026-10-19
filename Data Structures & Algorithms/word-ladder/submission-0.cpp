class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(
            wordList.begin(), wordList.end()
        );

        if (!words.count(endWord)) {
            return 0;
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) {
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) {
                        continue;
                    }

                    word[i] = ch;

                    if (words.count(word) &&
                        !visited.count(word)) {

                        visited.insert(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};