class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        vector<int>freq1(26,0);
        vector<int>window(26,0);

        for(char c:s1){
            freq1[c-'a']++;
        }
        int m = s1.size();

        for(int i=0; i<m; i++){
            window[s2[i]-'a']++;
        }
        if(freq1 == window) return true;

        for(int i=m; i<s2.size();i++){
            window[s2[i]-'a']++;
            window[s2[i-m]-'a']--;
            if(freq1 == window) return true;
        }
        return false;        
    }
};
