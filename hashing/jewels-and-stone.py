"""
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
"""

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        #2 hashmaps, one with jewels, other with stones. keep count. if the individual stone is in the other hashmap, then increase the count
        count = 0
        jewels_set = set(jewels)
        
        
        for stone in stones:
            if stone in jewels_set:
                count += 1
        
        return count
        
        
