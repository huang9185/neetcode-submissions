class Solution {
public:
    void sortColors(vector<int>& nums) {
        // bucket sort
        vector<int> l(3, 0);
        for (int i : nums) l[i]++;
        int j = 0;
        for (int i = 0; i < 3; ++i) {
            while(l[i] != 0) {
                nums[j++] = i;
                l[i]--;
            }
        }
    }
};