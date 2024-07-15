/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined. */


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_count = 0;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zero_count++;
            }
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }
            ans = max(ans, right - left + 1); //so if the zero_count < k, your left will stay the same. so in the iterations before the number of zeros in the window gets exceeded, your left index will be the same, only thing is that the difference between the right and the left grows larger. THEN, once the number of zeroes gets exceeded, that is when the while loop comes in to update the left pointer. this will execute after the while loop, but the size of the original window will still be the max.
        }
        return ans;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)
