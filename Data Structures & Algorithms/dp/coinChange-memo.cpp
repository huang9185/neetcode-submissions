class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> m(amount+1, -2);
        m[0]=0;
        sort(coins.begin(), coins.end());
        return backtrack(coins, amount, m);
    }
    // take amt, minus largest num possible if enough, check feasible, record number of times minusing nums, if not feasible, backtracking, and try another, else
    int backtrack(vector<int>& coins, int amount, vector<int>&m) {
        if (m[amount] != -2) return m[amount];
        auto it = upper_bound(coins.begin(), coins.end(), amount);
        int res = INT_MAX;
        for (auto ite = coins.begin(); ite < it; ++ite) {
            int temp_min = backtrack(coins, amount - *ite, m);
            if (temp_min != -1) res = min(temp_min+1, res);
        }
        if (res == INT_MAX) res = -1;
        m[amount] = res;
        return res;
    }

    // 11: 
    //  not 0, continue; largest under is 5, minus 5 keep going
    //. 6 minus 5 keep going; 1
};

