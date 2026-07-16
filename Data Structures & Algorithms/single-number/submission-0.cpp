class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num:nums){
            mpp[num]++;
        }
        for(auto& it:mpp){
            int first = it.first;
            int second = it.second;
            if(second<2){
                return it.first;
            }
        }
        
    }
};
