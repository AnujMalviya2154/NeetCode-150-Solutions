class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combinedArray;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                combinedArray.push_back(nums1[i]);
                i++;
            } 
            else{
                combinedArray.push_back(nums2[j]);
                j++;
            } 
        }
        while(i<nums1.size()){
            combinedArray.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            combinedArray.push_back(nums2[j]);
            j++;
        }
        int n = combinedArray.size();
        if(n%2==0) return (combinedArray[n/2-1] + combinedArray[n/2]) / 2.0;
        return combinedArray[n/2];

        
    }
};
