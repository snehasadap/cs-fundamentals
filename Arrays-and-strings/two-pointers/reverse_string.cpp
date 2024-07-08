//reverse a string in place. use two pointers, one starting on left and the other on the right. to "reverse" the string, you swap the left and right indices

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        char temp;
        while (i < j){
           temp = s[i]; //assign temp to the left char to ensure the left value is stored somewhere
           s[i] = s[j]; //since we have temp, we can safely assign the right value to the left. now, the left index is equal to the right
           s[j] = temp; //we take the temp which has the original value of the left and assign it to the right value to "swap" the indices   
            i++; //once that is complete, we increment and decrement the left and right indices, respectively, to repeat the process for the rest of the chars
            j--;
        }
        
        
    }
};

//time complexity: O(n)
//space complexity: O(1)
