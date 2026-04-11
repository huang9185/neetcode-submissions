class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        li = []
        for n in nums:
            if n in li:
                return True
            li.append(n) 

        return False