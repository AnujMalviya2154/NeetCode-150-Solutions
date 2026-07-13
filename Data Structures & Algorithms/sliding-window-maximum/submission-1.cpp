class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<=n-k; i++){
            int maximum=INT_MIN;
            for(int j=i; j<i+k; j++){
                maximum = max(nums[j],maximum);
            }
            ans.push_back(maximum);
        }
        return ans;
        
    }
};
