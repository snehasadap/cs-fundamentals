

//returns true if there are two integers in which their sum = target, returns false otherwise. unlike two sum, both of these lists are already sorted
//Ex: [1, 3, 6, 7, 8] target: 13
//    returns True
//    [1, 4, 5, 6, 7] target: 21
//    returns False
//Brute force: do a nested for loop that adds each of the elements with the current value. Time complexity: (O(n^2))



bool CheckForTarget{vector<int>& nums, int target}{ //takes in an sorted array of ints and a target sum
    int left = 0; //establishing index of left pointer
    int right = nums.size() - 1; //establishing index of right pointer
    while (left < right){
        //current sum "curr" is defined within the loop
        int curr = nums[left] + nums[right];
        if curr = target{
            return True;
        }
        if curr > target{ 
           right--; //decrement the pointer on the right to receive a lower value for the next iteration
        } else{ //sum is < target
            left--; //increase the pointer on the left to receive a larger value for the next iteration
        }
    return False; //returns false after loop finishes executing,
}

//basic gist: declare pointers, start logic, then decrement pointers at the end of the loop 
//space complexity: O(1)
//time complexity: O(n)
