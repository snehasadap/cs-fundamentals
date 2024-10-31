class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        #solution: create 2 for loops, one to handle prefix product and one for suffix

        n = len(nums)

        result = [1] * n #initializes result array with all 1s

        prefix_product = 1
        for i in range(n): #create array of prefix products
            result[i] = prefix_product
            prefix_product *= nums[i]
        
        suffix_product = 1
        for i in range(n-1, -1, -1): #calculate suffix product, then each indice will be multiplied against result[i] since it stores the prefix products
            result[i] *= suffix_product
            suffix_product *= nums[i]

        return result



