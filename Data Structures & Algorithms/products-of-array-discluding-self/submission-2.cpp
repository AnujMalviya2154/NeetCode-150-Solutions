class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        int product = 1;
        int zeroCount = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zeroCount++;
                continue;
            } 
            product *= nums[i];
        }
        if(zeroCount>1) return vector<int>(nums.size(),0);
        for(int i=0;i<n;i++){
            if(zeroCount==1){
                if(nums[i]==0) nums[i]=product;
                else nums[i]=0;
            }
            else nums[i]=product/nums[i];
        }

        return nums;

    }
};
