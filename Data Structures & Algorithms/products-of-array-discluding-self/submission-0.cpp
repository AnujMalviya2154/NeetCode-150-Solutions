class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(j==i) continue;
                product *= nums[j];
            }
            result.push_back(product);
        }
        return result;

    }
};
