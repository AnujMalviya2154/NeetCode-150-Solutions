class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int reqIndex = -1;

        for(int i = 0; i < m; i++) {

            if(matrix[i][0] <= target &&
               target <= matrix[i][n-1]) {

                reqIndex = i;
                break;
            }
        }

        if(reqIndex == -1) return false;

        int start = 0;
        int end = n - 1;

        while(start<=end){
            int mid = start+((end-start)/2);
            if(matrix[reqIndex][mid] == target) return true;
            if(matrix[reqIndex][mid]<target) start = mid+1;
            else end = mid-1;

        }
        return false;
        
        
    }
};
