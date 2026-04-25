class Solution {
    int size;
    unordered_map<int, int> m;
public:
    int rob(vector<int>& nums) {
        size = nums.size();
        m.clear();
        return acc(nums, 0);
    }
    // want to have a function that recurse on nums, and i where ith house is the next house unrobbed that would not trigger the alarm; return the max number possible
    int acc(vector<int>& nums, int i) {
        if (m.count(i) != 0) return m[i];

        int res;
        if (size == i) res = 0;
        else if (size-1 == i) res = nums[i];
        else if (size-2 == i) res = max(nums[i],nums[i+1]);
        else if (size-3 == i) res = max(nums[i]+nums[i+2], nums[i+1]);
        else res = max(nums[i]+acc(nums, i+2), acc(nums, i+1));

        m[i] = res;
        return res;
    }
    // a b c: either a and c or b
    // a b c d: pick a, and then recurse on c and d
        // or recurse on b c d
    // a b c d e: pick a and recurse on c d e or
        // recurse on b c d e
};

