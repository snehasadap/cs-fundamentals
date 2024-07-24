class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)

        #create prefix sum array
        prefix = [nums[0]]
        for i in range(1, n):
            prefix.append(nums[i] + prefix[-1])

        ans = 0
        for i in range(n - 1):
            left_section = prefix[i]
            right_section = prefix[-1] - prefix[i] #subtract current element of prefix sum from last element of prefix array to find the sum of of the right section
            if left_section >= right_section:
                ans += 1

        return ans
