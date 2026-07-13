class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxVol = 0;
        int n = heights.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int currentVol = 1;
                currentVol *= min(heights[i],heights[j])*(j-i);
                maxVol = max(currentVol,maxVol);
            }
        }
        return maxVol;
    }
};
