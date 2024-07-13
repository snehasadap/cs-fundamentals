//Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k. This is the problem we have been talking about above.

int findLength(vector<int>& nums, int k) {
    // curr is the current sum of the window
    int left = 0, curr = 0, ans = 0;
    for (int right = 0; right < nums.size(); right++) { //we declare right pointer at beginning and start expanding it
        curr += nums[right];
        while (curr > k) {
            curr -= nums[left]; //if the curr is > k, we will drop an element from the window on the lefthand side, aka "sliding" the window to till the end of the array
            left++;
        }
        
        ans = max(ans, right - left + 1); //store current subarray, then compare it to the subarray after iteration to find the max. our goal is to find the longest subarray. a way of thinking about this is max length of subarray with sum <= k
    }
    
    return ans;
}

//time compexity: O(n)
//space complexity: O(1)
