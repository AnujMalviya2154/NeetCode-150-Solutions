class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int left = i;
            int right = i;
            while(left>0 && heights[left-1]>=heights[i]){
                left--;
            }
            while(right<n-1 && heights[right+1]>=heights[i]){
                right++;
            }
            int width = right-left+1;
            ans = max(ans,width*heights[i]);
        }
        return ans;
        
    }
};
