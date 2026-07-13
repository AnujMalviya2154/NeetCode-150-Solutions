class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for(char c:s){
            if(isalnum(c)){
                newStr += tolower(c);
            }
        }
        int n = newStr.length();
        int i=0,j=n-1;
        while(i<j){
            if(newStr[i]!=newStr[j]) return false;
            i++;
            j--;
        }
        return true;
        
    }
};
