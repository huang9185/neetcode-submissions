class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m-1;
        int b = n-1;
        // starting from back i = m+n-1
        for (int i = m+n-1; a >= 0 && b >= 0; --i) {
            if (nums1[a] > nums2[b]) nums1[i] = nums1[a--];
            else nums1[i] = nums2[b--];
        }
        // if both a and b not -1
        // take the larger one from nums1[a--] or nums2[b--]
        // leftover: 
        if (b >= 0) {
            copy(nums2.begin(), nums2.begin()+b+1, nums1.begin());
        }
    }
};