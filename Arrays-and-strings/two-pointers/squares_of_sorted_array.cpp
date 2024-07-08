//takes in an array, sorted in non-decreasing order, and returns the squares.
//Ex: [-5, -3, 2, 6, 7, 9, 10]
//result: [4, 9, 25, 36, 49, 100]
//brute force: iterate through the entire list and return the squares of each value. Runtime: (O(nlogn)) 
//Better approach: use two pointers to evaluate the absolute value of the left and right values and determine which one is greater. 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0;
        int right = nums.size() - 1;
        for (int i = n - 1; i >= 0; i--){ //loop starts at end. we will start off by appending the largest value and work our way backwards
            int square;
            if (abs(nums[left]) < abs(nums[right])){ //if right index is greater, this will be the first value to be added to the result, and vice-versa for left
                square = nums[right]; //assigns the value to be squared
                right--; //decrement right index to compare next value to left
            } else{ //left value is greater
                square = nums[left];
                left++; //increment left index if left value is greater
            }
            result[i] = square * square; //compute square of left or right, depending on the outcome
        }
        return result;     
        
    }
};

//Time complexity: O(n)
//Space complecity: O(n)
