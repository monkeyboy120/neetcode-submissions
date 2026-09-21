class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = dict()
        for i, num in enumerate(nums):
            value = target - num
            if value in d:
                return [d[value], i]
            d[num] = i
        