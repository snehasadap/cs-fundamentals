class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = {}
        for i, value, in enumerate(nums):
            nums_dict[value] = i
        
        for i, value in enumerate(nums):
            complement = target - value
            if complement in nums_dict and nums_dict[complement] != i:
                return [i, nums_dict[complement]]
        
        
        



             
        
