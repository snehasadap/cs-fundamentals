'''
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 


'''



class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        #lefthand window product
        #righthand window product

        length = len(nums)
        products = [1] * length #we will overwrite the 1s

        for i in range(1, length): #calculate products at left of each element
            products[i] = products[i-1] * nums[i-1] #it's taking the previous index and multiplying it by the prev value of the nums index to get the current product
            
        right = nums[-1] #initialize to rightmost element
        for i in range(length - 2, -1, -1): #length - 2 will start at second last index, -1 will traverse index backwards until it reaches zero
            products[i] *= right #it's taking the second to last value of products and multiplying it by the last number in nums
            right *= nums[i]
        return products



      
