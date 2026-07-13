class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         // Always binary search the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;
        int half = (total + 1) / 2;

        int left = 0;
        int right = m;

        while (left <= right) {

            // Partition in A
            int cutA = (left + right) / 2;

            // Partition in B
            int cutB = half - cutA;

            int leftA  = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
            int rightA = (cutA == m) ? INT_MAX : nums1[cutA];

            int leftB  = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
            int rightB = (cutB == n) ? INT_MAX : nums2[cutB];

            // Correct partition
            if (leftA <= rightB && leftB <= rightA) {

                if (total % 2 == 0) {

                    return (max(leftA, leftB) +
                            min(rightA, rightB)) / 2.0;
                }

                return max(leftA, leftB);
            }

            // Too many elements taken from A
            else if (leftA > rightB) {

                right = cutA - 1;
            }

            // Too few elements taken from A
            else {

                left = cutA + 1;
            }
        }

        return 0;

        
    }
};
