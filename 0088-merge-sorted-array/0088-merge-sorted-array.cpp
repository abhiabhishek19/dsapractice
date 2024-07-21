class Solution {


public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
        
        int totalLength = m + n;
        int gap = (totalLength + 1) / 2;  // Initial gap
        
        while (gap > 0) {
            for (int i = 0; i + gap < totalLength; ++i) {
                if (nums1[i] > nums1[i + gap]) {
                    swap(nums1[i], nums1[i + gap]);
                }
            }
            if (gap == 1) break;
            gap = (gap + 1) / 2;  // Reduce gap
        }
    }
};