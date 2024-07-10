/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0. */


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { 
        sort(nums.begin(), nums.end()); //we will begin by sorting the list so it will easier to iterate through. also, it's safe to say that since the list is sorted, there will be no repetitions
        int k = nums.size() - 1; //initialization of the end pointer will be outside of the loop since remains fixed
        vector<vector<int>> result; //initialize empty array and return the result at the end
        for (int i = 0; i < nums.size() - 2; i++) { //we will nums.size() - 2 since there is no point in iterating the last 2 elements since the result won't return a triplet
            int j = i + 1; //points to value after i
            while (j < k) { //two pointer logic comes into place
                if (nums[i] + nums[j] + nums[k] == 0) { //checking if the sum of the 3 current values equal to 0, then we have one of our solutions
                    result.push_back({nums[i], nums[j], nums[k]}); 
                }
                if (nums[i] + nums[j] + nums[k] < 0) { //if the sum of the three is less than zero, we will incrememnt the pointer the left hand side to receive a larger value
                    j++; 
                } else {
                    k--; //if the sum is greater than zero, then we will decrement the pointer on the right hand side 
                } 
            } // this loop will keep repeating until all elements are iterated through
        } //start with the next fixed pointer
        return result;
    }
};

//time complexity: O(n^2)
