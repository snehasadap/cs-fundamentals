class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Anytime that we encounter a negative prefix, we remove it

        maxSub = nums[0]
        curSum = 0

        for i in nums:
            if curSum < 0:  # If prefix is less than zero, reset it to 0
                curSum = 0
            curSum += i  # Change `nums[i]` to `i` since `i` is already the element in nums
            maxSub = max(curSum, maxSub)

        return maxSub
