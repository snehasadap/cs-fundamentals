class Solution:
    def maxArea(self, height: List[int]) -> int:
        #brute force, find out every area possibility and rreturn the max
        #if one of the values is less than the other, we need to use that as the height, and then width will be high - low

        #right, left = 0, 0
        
        #area = 0
        #max_area = 0
        #curr_height = 0

        #for i in range(len(height)):
        ##    for j in range(i+1, len(height)):
         #       if height[i] <= height[j]:
         #           curr_height = height[i]
        #            area = curr_height * (j - i)
        #        else:
        #            curr_height = height[j]
        #            area = curr_height * (j - i)
                
        #        max_area = max(max_area, area)
        
        #return max_area
        #above resulted in time limit exceeded

        left = 0
        right = len(height) - 1

        max_area = 0

        while left < right:
            w = right - left
            h = min(height[left], height[right])
            a = w * h

            max_area = max(max_area, a)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area


        
            


