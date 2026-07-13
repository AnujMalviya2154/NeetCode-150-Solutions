class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxVol = 0;
        int n = heights.size();
        int i=0,j=n-1;
        while(i<j){
            int currentVol = min(heights[i],heights[j])*(j-i);
            maxVol = max(currentVol,maxVol);
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return maxVol;
    }
};
