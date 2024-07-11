/* Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12". */



class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0; //we want to return the length of the result, so we will start off with ans index at zero and use this index to "overwrite" the chars array along the way

        // iterate through input vector using i pointer
        for (int i = 0; i < chars.size();) { //there is no i++ because we are not incrementing by 1, the i is depended on when the next different character comes up 
            const char letter = chars[i]; // current character being compressed
            int count = 0; // count of consecutive occurrences of letter

            // count consecutive occurrences of letter in input vector
            while (i < chars.size() && chars[i] == letter) {
                count++;
                i++; //increment i here so that in the outer while loop it will start with the next letter. it is noted that the i++ is here and not in the initialization of the for loop. if you need to pick up after a specific index, you can also implement i++ within your loop, depending on the program's logic
            }

            // write letter to compressed vector
            chars[ans++] = letter; //this will update as we keep iterating through the loop. we are using a different variable to overwrite the characters in chars

            // if count is greater than 1, write count as string to compressed vector
            if (count > 1) {
                // convert count to string and iterate over each character in string
                for (const char c : to_string(count)) {
                    chars[ans++] = c; //this converts the count to a string and adds it as the next char in our updated chars array using ans index
                }
            }
        }

        // return length of compressed vector
        return ans;
    }
};
