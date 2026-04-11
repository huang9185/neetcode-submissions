class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // loop array with i
        // length is l
        // if is, +1
        // if not, 0
        // keep max, start as 0, when not, compare, at end compare
        int max =0;
        int length = 0;
        for (int n : nums)
        {
            length += n;
            if (n == 0) {
                if (length > max) max = length;
                length = 0;
            }
        }
        if (length > max) max = length;
        return max;
    }
};