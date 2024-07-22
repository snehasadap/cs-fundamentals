#include <unordered_map>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result; //if the number of characteres in s is less than p, then return empty array
        //brute force: figure out all combinations of p, then use the sliding window to see if that window matches any of variations of p
        //window is no longer valid if we encounter a letter that's not in p or if we have previously encountered the same letter
        //unlike a normal while loop in a sliding window, in this case, we will update the left pointer to start at the next index that also matches a character in p
        //if we have all three characters in s, we append the left side of the window, or left ptr, since that will be the start of the window
        //create a hashmap, one for p and one for s. if a key in p > 1, then window is no longer valid since the value is repeated, and if the key in p isn't in p, then the window is also invalid.
        
       unordered_map<char, int> p_count, s_count;
       for (char c : p) { //initialize hashMap for p with char and value
            p_count[c]++;
        }

        int left = 0, right = 0, match = 0;

        for (right = 0; right < s.size(); ++right) {
        char c = s[right];
        if (p_count.count(c) > 0) { //check if current char is part of p. if true then it will execute next statement. if s is not in p, then right pointer will increment
            s_count[c]++; //add 1 to s hashMap to store frequency
            if (s_count[c] == p_count[c]) { //if char count of currChar matches the char count of p, that means that we have found a char for our anagram
                match++;
            }
        }
        //adjust the window size if it exceeds the length of p
        if (right - left + 1 > p.size()) {
            char left_char = s[left]; 
            if (p_count.count(left_char) > 0) {
                if (s_count[left_char] == p_count[left_char]) {
                    match--; //decrement match to make space for next char in window
                }
                s_count[left_char]--; //clear hashMap for next window
            }
            left++; //increment left ptr for s. only execute this if the window size is greater than p
            //you will still keep the values from the previous window, just remove the hashmap count on the lefthand side bc you can still have a situation where you have two anagrams right next to each other
        }

        if (match == p_count.size()) { //if the match count matches the p count, that means we have found an anagram, we can append the left ptr to the result
            result.push_back(left);
        }
    }

    return result;

        
    }
};
