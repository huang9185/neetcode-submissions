class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, nums, cur, 0);
        return res;
    }
    // 2 by 2 by 2
    void backtrack(vector<vector<int>>& res, vector<int>&nums, vector<int>&cur, int start) {
        if (start == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[start]);
        backtrack(res, nums, cur, start+1);
        cur.pop_back();
        backtrack(res, nums, cur, start+1);
    }
};

