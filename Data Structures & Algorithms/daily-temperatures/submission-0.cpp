class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=i+1; j<n; j++){
                if(temperatures[j]>temperatures[i]){
                    count = j-i;
                    break;
                } 
            }
            ans.push_back(count);
        }
        return ans;
    }
};
