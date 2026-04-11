class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        for i in range(0, len(s)):
            for j in range(i+1,len(s)+1):
                subs = s[i:j]
                if not len(set(subs)) != len(subs):
                    res = max(res, len(subs))
        return res
