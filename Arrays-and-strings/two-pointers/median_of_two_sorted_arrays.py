"""
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

"""



class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        #first combine the array. we can use two pointers for this then calculate the median

        i = 0
        j = 0
        median = 0
        median_idx = 0
        median_idx_2 = 0
        ans = []

        while (i < len(nums1) and j < len(nums2)):
            if nums1[i] < nums2[j]:
                ans.append(nums1[i])
                i += 1
            else:
                ans.append(nums2[j])
                j += 1
        
        while i < len(nums1):
            ans.append(nums1[i])
            i += 1
        while j < len(nums2):
            ans.append(nums2[j])
            j += 1
        
        if len(ans) % 2 == 1:
            median_idx = len(ans) // 2 
            median = ans[median_idx]
            return median
        else:
            median_idx_2 = len(ans) // 2
            median_idx = median_idx_2 - 1

            median = (ans[median_idx] + ans[median_idx_2]) / 2
            return median


