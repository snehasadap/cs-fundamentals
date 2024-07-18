/*Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring. */

#include <iostream>
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //use hashmap to store values along with its count. if count of one of the letters is > 1, we have our first string. then we will update the pointer starting at the repeated value. then, we can call the max function at the end to keep track of largest length. we have to refresh the hashmap at the end. the letter will be the key and the count will value. 
        //to get left pointer. keep decrementing the count, the repeated key specficially, until your reach = 1, and increment left pointer in the while loop. that will be new index of left ptr
        int ans = 0;
        int left = 0;
        unordered_map<char, int> charMap;
        int right = 0;

        while (right < s.length()) { 
            char currentChar = s[right];
            charMap[currentChar]++; //creates char key and adds 1 to that key. you are going to find a moment where the currentchar is already in the hashmap, so now second while loop will execute

            while (charMap[currentChar] > 1) {
                charMap[s[left]]--; //clear the hashmap by removing the count of each key. so for all characters, the count is going to be one, so the count will be zero 
                if (charMap[s[left]] == 0) { //if the count is zero, we will remove that value from the hashmap aka clear the hashmap of all existing values except for the value that we will starting off with in the next iteration
                    charMap.erase(s[left]); //clearing each element of hashmap
                }
                left++; // Move the left pointer to curr right value of ptr
            }

            ans = max(ans, right - left + 1); //return max string
            right++;

        }
        
        return ans;
    }
};

//Time complexity: O(n)
