class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int reqIndex = -1;

        int top = 0;
        int bottom = m-1;
        while(top<=bottom){
            int mid = top + ((bottom-top)/2);
            if(matrix[mid][0]<=target && target<=matrix[mid][n-1]){
                reqIndex = mid;
                break;
            } 
            else if(matrix[mid][n-1]<target) top = mid+1; 
            else bottom = mid-1; 
        }

        if(reqIndex == -1) return false;

        int start = 0;
        int end = n - 1;

        while(start<=end){
            int mid = start+((end-start)/2);
            if(matrix[reqIndex][mid] == target) return true;
            else if(matrix[reqIndex][mid]<target) start = mid+1;
            else end = mid-1;

        }
        return false;
        
        
    }
};
