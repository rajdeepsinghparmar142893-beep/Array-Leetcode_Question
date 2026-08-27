class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lookup = dict()
        for index, value in enumerate(nums):
            key = target - value
            if key in lookup:
                return [index, lookup[key]]
            lookup[value] = index
        return [-1, -1]
