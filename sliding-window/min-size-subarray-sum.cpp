/*Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0 

target: 4
[1, 1, 4, 3]
output: 2 ([1, 4]) */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //return minimum subarray, NOT maximum, so call the min function
        //the moment we find that very next value that is greater than or equal to 7, we have found our window
        //keep incrementing left ptr and decrementing each element that consists of the sum until we get zero
        //create an outside loop. if the total sum of the array is less than the target, then result is zero
        int sum = 0;
        int left = 0;
        int ans = INT_MAX; //it's not zero because if it was, then the output will always be zero

        //if total sum of array is < target, that means there are no valid subarrays, so we return zero
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        if (sum < target){
            return 0;
        }

        //clear sum to start main logic
        sum = 0;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                ans = min(ans, right - left + 1); //this goes inside of the while loop. this will track any valid windows within current window by decrementing values from the left side. doing so will help find the min. if it was max, there is no need to execute function in while loop since we want the largest value anyway so we don't have the evaluate the subarrays within our window
                sum -= nums[left];
                left++;
            }

        }

        return (ans == INT_MAX) ? 0 : ans;

        

    }
};

//complexity: O(n)
