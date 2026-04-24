class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int sum = 0;
        int max = 0;
        vector<int> dif;
        dif.push_back(0);
        for (int i = 1; i < prices.size(); ++i) {
            dif.push_back(prices[i]-prices[i-1]);
        }
        for (int i : dif) {
            sum += i;
            if (sum >= max) max = sum;
            else if (sum < 0) sum = 0;
        }
        return max;
    }
};

