class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        #create a hashmap of the numbers and indices
        #then use i and j adn two pointers. if we do some math, we can see that our desired value is -i - j to get 0, so we can check against the hashmap in constant to time to see if we have that value. to find every value except for i and j, we run a conditional. we sort the tuple so that we can ensure that there aren't any duplicates
        h = {}
        n = len(nums)
        s = set()

        for i, num in enumerate(nums):
            h[num] = i #add all the elements to the hashmap as well as indices
        
        for i in range(n):
            for j in range(i+1, n):
                desired = -nums[i] - nums[j]

                if desired in h and h[desired]  != i and h[desired] != j: #access value by doing h[desired]
                    s.add(tuple(sorted([nums[i], nums[j], desired])))
        
        return [list(triplet) for triplet in s]
            





