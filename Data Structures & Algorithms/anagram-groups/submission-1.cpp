class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>groups;

        for(auto& word: strs){
            int freq[26] = {0};
            for(char c:word){
                freq[c-'a']++;
            }
            string key;
            for(int i=0; i<26; ++i){
                key += '#';
                key += to_string(freq[i]);
            }
            groups[key].push_back(word);
        }
        vector<vector<string>>result;
        for(auto& p:groups){
            result.push_back(move(p.second));
        }
        return result;
        
    }
};
