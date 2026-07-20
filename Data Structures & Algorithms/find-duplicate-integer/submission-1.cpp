class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            int ele = it.first;
            int count = it.second;
            if(count>1) return ele;
        }
        return -1;
        
    }
};
