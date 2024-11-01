class Solution:
    def search(self, nums: List[int], target: int) -> int:
    #we will have to keep this index into account when we are doing our binary search
    #we will have to determine what the middle is. if the target is less than the middle, 
        low = 0
        high = len(nums) - 1 

        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return mid
                
            if nums[low] <= nums[mid]: #if a value on the left is less than the middle value, then the greater values of mid are on the right
                if target > nums[mid] or target < nums[low]:
                    low = mid + 1
                else:
                    high = mid - 1
            #right sorted portion
            else:
                if target < nums[mid] or target > nums[high]:
                    high = mid - 1
                else:
                    low = mid + 1
        return -1

             


