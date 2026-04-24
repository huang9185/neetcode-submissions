class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exist(nums.begin(), nums.end());
        int res = 0;
        for (int i : exist) {
            if (exist.find(i-1) == exist.end()) {
                int len = 1;
                int cur = i;
                while (exist.find(cur+1) != exist.end()) {
                    len++;
                    cur++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};

