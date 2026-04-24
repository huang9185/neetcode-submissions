class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // from definition, first position has n choices, second has n-1, third has n-2, and so on,
        // in the vector insert each to first position, 

        vector<bool> visited(nums.size(), false);
        vector<int> cur_path;
        vector<vector<int>> res;
        backtrack(res, nums, visited, cur_path);
        return res;
    }

    void backtrack(vector<vector<int>>&res, vector<int>&nums, vector<bool>&visited, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // check if used in current array
            if (visited[i]) continue;

            // when not used, take this as next, and then fill in rest of array
            visited[i] = true;
            cur.push_back(nums[i]);
            backtrack(res, nums, visited, cur);
            visited[i] = false;
            cur.pop_back();
        }
    }
};

