'''
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


'''


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix_sum = [0] * (n + 1)  # Initialize prefix_sum array
        
        # Calculate prefix sums
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        # Use a dictionary to count the frequency of each prefix sum
        prefix_sum_map = {}
        count = 0
        
        for sum_val in prefix_sum:
            # If (sum_val - k) is in the map, it means there are subarrays that sum to k
            if (sum_val - k) in prefix_sum_map:
                count += prefix_sum_map[sum_val - k]
            
            # Update the frequency of the current prefix sum
            if sum_val in prefix_sum_map:
                prefix_sum_map[sum_val] += 1
            else:
                prefix_sum_map[sum_val] = 1
        
        return count

        
