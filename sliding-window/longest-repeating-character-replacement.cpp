class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> count(26); //
        int maxCount = 0;

        // Two pointers for the sliding window: left and right
        int left = 0;
        int right = 0;
        
        int result = 0;

        // Iterate through the string with the 'right' pointer
        while (right < s.size()) {
            count[s[right] - 'A']++; // Increment the frequency of the current character in the window

            maxCount = max(maxCount, count[s[start] - 'A']); //finds character that occurs the most frequently in the window. the one that appears less will be the one that's associated with k

        // Check if the current window size minus the maximum frequency character is greater than k
            if (right - left + 1 - maxCount > k) { //if the count of B in this case is greater than k, then the window is no longer valid. If maxCount refers to the count of A, then start - left + 1 (the size of the array) - maxCount (A count) refers to B
                count[s[right] - 'A']--; // If yes, shrink the window from the left
                left++;
            }
            result = max(result, right - left + 1);
            right++; // Move the 'right' pointer to the right
        }
        
        return result;
    }
};
