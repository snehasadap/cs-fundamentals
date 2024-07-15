class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //calculate sum of first k elements

        double sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
    
        double maxAverage = sum / k;
        

        for(int i = k; i < nums.size(); i++) {
            // Slide the window to the right: add the next element and remove the first element of the previous window
            sum = sum + nums[i] - nums[i - k]; //nums[i-k] refers to dropping the element on the left
            
            // Update the maximum average if the new average is higher
            maxAverage = max(maxAverage, sum / k);
        }
        
        return maxAverage;
    }
};
