/*
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

 

Example 1:

Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.
Example 2:

Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.
Example 3:

Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
In both cases, there are five consecutive 'T's.

*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> map; //hashMap to store count of T and F
        int left = 0;
        int start = 0;
        int ans = 0;
        int maxCount = 0;
        //keep track of the T's and F's. then calculate the max. the one that's not the max will be the one associated with k
        //window is no longer valid when the min of t or f exceeds k

        while (start < answerKey.size()){
            char curr = answerKey[start];
            map[curr]++; //use a map to store values of t and f
            maxCount = max(maxCount, map[curr]); //keep track of the max count

            if(start - left + 1 - maxCount > k){ //whichever value you are associating with k atm
                map[answerKey[left]]--; //decrease size of window from the left until the window is valid again and can add new element
                left++;

            }
            ans = max(ans, start - left + 1);
            start++;



            }
            return ans;
        }

};
