class Solution {
public:
    void sortColors(vector<int>& nums) {
        // first do a brute force solution
        // do insertion sort
        int s = nums.size();
        if (s <= 1) return;
        for (int i = 1; i < s; ++i) {
            for (int j = i; j >=1 && nums[j-1] > nums[j]; --j) 
                swap(nums[j-1],nums[j]);
        }
    }
};