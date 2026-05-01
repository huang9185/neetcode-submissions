class Solution {
    // one simple approach can be done with:
    // go through each letter, check the cur prefix (including this letter is in),
    // if so, call wordbreak on the suffix
    // if return is true, true
    // else continue on the next letter
    int size;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        size = s.size();
        vector<int> dp(size, -1);
        unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
        return checkBreak(s, 0, hashSet, dp);
    }
    // prefix [0, start) has proper word breaks
    // [start, end) is so far no match
    // end: next letter unexplored
    bool checkBreak(string s, int start, unordered_set<string>& wordDict, vector<int>& dp) {
        if (start == size) return true;
        if (dp[start] != -1) return dp[start];
        for (int i = start+1; i <= size; ++i) {
            string sub = s.substr(start, i-start);
            if (wordDict.contains(sub)) {
                if (checkBreak(s, i, wordDict, dp)) {
                    dp[start] = 1;
                    return true;
                }
            }
        }
        dp[start] = 0;
        return false;
    }
};

