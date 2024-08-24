#link: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/
import heapq
class Solution:
    def halveArray(self, nums: List[int]) -> int:
        target = sum(nums) / 2
        nums = [-num for num in nums]
        heapq.heapify(nums)
        num_of_operations = 0

        while (target > 0):
            num_of_operations += 1
            top = heapq.heappop(nums)
            target += top/2 #bc the heap stores negative values
            heapq.heappush(nums, top/2)

        return num_of_operations




        
