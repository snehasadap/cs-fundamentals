class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [nums[0]] #it will start off by containing the first value of nums
        
        for i in range(1, n):
            prefix.append(nums[i] + prefix[-1])
        
        return prefix
