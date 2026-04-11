class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i,n in enumerate(numbers):
            v = target-n
            if v != n and v in numbers[i+1:]:
                return [i+1,numbers.index(v)+1]

        return True