class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        li = {i:0 for i in range(2001)}

        for n in nums:
            li[n+1000] = li[n+1000] + 1

        newLi = list(li.items())
        newLi.sort(reverse=True, key=lambda pair: pair[1])
        ret = [i[0]-1000 for i in newLi[:k]]

        return ret

        