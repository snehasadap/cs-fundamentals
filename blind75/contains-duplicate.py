class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        #hashmap that includes the number as the key and the the frequency as the value

        #run a separate loop that iterates through the hashmap and checks to see if any value is greater than or equal to 2, that means we return a duplicate, false otherwise
        frequency_dict = Counter(nums) #use counter to keep track of frequency, more efficient

        for number, frequency in frequency_dict.items(): #remember that it's frequency_dict.items(). remember how the for loop is arranged since this is usually how you iterate through dictionaries in python
            if frequency >= 2: #directly check each value if you're using a counter
                return True
        
        return False

        
