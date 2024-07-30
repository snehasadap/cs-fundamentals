class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        set_of_nums = set()
        
        for i in range(len(nums) + 1):
            set_of_nums.add(i)
        
        for val in set_of_nums:
            if val not in nums:
                return val
        return -1
        
