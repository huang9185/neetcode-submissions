class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return backtrack(coins, amount, 0);
    }
    // take amt, minus largest num possible if enough, check feasible, record number of times minusing nums, if not feasible, backtracking, and try another, else
    int backtrack(vector<int>& coins, int amount, int times) {
        if (amount == 0) return times;
        auto it = upper_bound(coins.begin(), coins.end(), amount);
        int res = -1;
        while (it != coins.begin()) {
            int temp = backtrack(coins, amount - *(--it), times+1);
            if (res == -1) res = temp;
            else res = min(res, temp);
            --it;
        }
        return res;
    }

    // 11: 
    //  not 0, continue; largest under is 5, minus 5 keep going
    //. 6 minus 5 keep going; 1
};

