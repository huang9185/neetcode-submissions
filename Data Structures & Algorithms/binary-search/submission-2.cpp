class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lowi = 0; // 3
        int highi = nums.size() - 1; // 3
        while (lowi <= highi) {
            int mid = (lowi + highi)/2; // 4
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                highi = mid-1;
            } else {
                lowi = mid+1;
            }
        }
        return -1;
    }
};
