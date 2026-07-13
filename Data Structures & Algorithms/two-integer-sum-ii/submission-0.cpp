class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int n = numbers.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(target==numbers[i]+numbers[j]) return {i+1,j+1};
            }
        }
        return {};

        
    }
};
